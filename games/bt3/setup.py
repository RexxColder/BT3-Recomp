#!/usr/bin/env python3
"""Build, deploy and package Dragon Ball Z: Budokai Tenkaichi 3 (SLUS_216.78, USA).

One script, four stages:

    stage 1  detect    identify the platform, toolchain, package manager and build inputs
    stage 2  deps      report and (interactively) install missing dependencies
    stage 3  build     the original pipeline: extract, recompile, generate, patch, build the runner
    stage 4  package   assemble the portable tree and produce the release artifact for this OS

The game's code is generated locally from YOUR copy of the game -- this repository ships no game
code or assets.

    python3 games/bt3/setup.py <iso|elf> [--stage N] [-y] [--deploy OUT] [--package]

Backwards-compatible flags kept for the release containers and scripts: --jobs, --skip-setup,
--gen-only, --deploy. See --help and --list-stages.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
import platform as _platform
import shutil
import stat
import subprocess
import sys
from dataclasses import dataclass, field
from pathlib import Path
from typing import Callable, Optional

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent.parent
# Overridable so a container can generate into a build-local dir (PS2X_BUILD_DIR)
# instead of the host source tree. Defaults to <repo>/build.
BUILD = Path(os.environ.get("PS2X_BUILD_DIR") or str(ROOT / "build"))
WORK = HERE / "work"
ELF_SHA256 = "811188ba9b416500d921cd4d9514df0cbf42f3a41a99cf5aac5a3da37171bf99"
# Generated TUs are huge; high job counts can exhaust RAM (16 GB: keep <= 3).
DEFAULT_JOBS = "3"

# Pinned tool versions (stage 2 installs exactly these; keep in sync with the release containers).
CMAKE_MIN = (3, 21)
QT_VERSION = "6.5.3"
QT_KIT_WINDOWS = "win64_msvc2022_64"
MESA_LAVAPIPE_VERSION = "26.2.0"
DEPS_7ZR_URL = "https://www.7-zip.org/a/7zr.exe"

# Linux package groups per package manager (stage 2). Split so a missing FFmpeg or Qt can be
# installed without re-running the whole toolchain install.
LINUX_GROUPS: dict[str, dict[str, str]] = {
    "apt": {
        "toolchain": "clang cmake ninja-build pkg-config git ccache mold libx11-dev libxrandr-dev "
                     "libxi-dev libxcursor-dev libxinerama-dev libgl1-mesa-dev libglu1-mesa-dev "
                     "libarchive-tools p7zip-full",
        "ffmpeg": "libavcodec-dev libavformat-dev libavutil-dev libswresample-dev libswscale-dev",
        "qt": "qt6-base-dev",
    },
    "pacman": {
        "toolchain": "clang cmake ninja pkgconf git ccache mold libx11 libxrandr libxi libxcursor "
                     "libxinerama mesa glu libarchive p7zip",
        "ffmpeg": "ffmpeg",
        "qt": "qt6-base",
    },
    "dnf": {
        "toolchain": "clang cmake ninja-build pkgconf-pkg-config git ccache mold libX11-devel "
                     "libXrandr-devel libXi-devel libXcursor-devel libXinerama-devel mesa-libGL-devel "
                     "mesa-libGLU-devel libarchive p7zip",
        "ffmpeg": "ffmpeg-devel",
        "qt": "qt6-qtbase-devel",
    },
    "zypper": {
        "toolchain": "clang cmake ninja pkg-config git ccache mold libX11-devel libXrandr-devel "
                     "libXi-devel libXcursor-devel libXinerama-devel Mesa-libGL-devel glu-devel "
                     "libarchive p7zip",
        "ffmpeg": "ffmpeg-devel",
        "qt": "qt6-base-devel",
    },
}

# Stage registry: name -> (number, callable). Order matters.
STAGES: list[tuple[str, str]] = [
    ("1", "detect  - platform, toolchain, package manager and build inputs"),
    ("2", "deps    - report and install missing dependencies"),
    ("3", "build   - extract, recompile, generate, patch, build the runner"),
    ("4", "package - assemble the deploy tree and the release artifact"),
]


# ------------------------------------------------------------------------------------------------
# Output helpers
# ------------------------------------------------------------------------------------------------
def die(msg: str, code: int = 1) -> "None":
    print(f"ERROR: {msg}", file=sys.stderr)
    sys.exit(code)


def warn(msg: str) -> None:
    print(f"WARNING: {msg}", file=sys.stderr)


def step(msg: str) -> None:
    print(f"\n== {msg}")


def run(cmd, **kw) -> None:
    print("+ " + " ".join(str(c) for c in cmd))
    subprocess.run([str(c) for c in cmd], check=True, **kw)


def run_capture(cmd) -> str:
    try:
        r = subprocess.run([str(c) for c in cmd], capture_output=True, text=True)
        return (r.stdout or "") + (r.stderr or "")
    except OSError:
        return ""


def has_tty() -> bool:
    try:
        return sys.stdin.isatty() and sys.stdout.isatty()
    except Exception:   # noqa: BLE001
        return False


def ask_yes_no(ctx: "Context", question: str, default: bool = True) -> bool:
    """Interactive yes/no. -y answers yes, --non-interactive (or no TTY) answers the default."""
    if ctx.args.yes:
        print(f"{question} [auto-yes]")
        return True
    if not ctx.interactive:
        print(f"{question} [non-interactive -> {'yes' if default else 'no'}]")
        return default
    suffix = "[Y/n]" if default else "[y/N]"
    try:
        ans = input(f"{question} {suffix} ").strip().lower()
    except EOFError:
        return default
    if not ans:
        return default
    return ans in ("y", "yes", "s", "si", "sí")


def ask_path(ctx: "Context", prompt: str, what: str) -> Optional[Path]:
    """Interactive path prompt. Returns None in non-interactive mode (caller decides how to fail)."""
    if not ctx.interactive or ctx.args.yes:
        return None
    try:
        raw = input(f"{prompt} ").strip().strip('"').strip("'")
    except EOFError:
        return None
    if not raw:
        return None
    p = Path(raw).expanduser()
    if not p.exists():
        print(f"  {what} not found: {p}")
        return None
    return p.resolve()


# ------------------------------------------------------------------------------------------------
# Filesystem helpers
# ------------------------------------------------------------------------------------------------
def make_writable(root: Path) -> None:
    # ISO9660 files extract read-only; the game opens some (e.g. BIN/DBZP.BIN) read-write.
    for p in root.rglob("*"):
        try:
            p.chmod(p.stat().st_mode | stat.S_IWRITE)
        except OSError:
            pass


def sha256_of(path: Path) -> str:
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def sync_tree(src: Path, dst: Path, exclude=()) -> None:
    """rsync -a --checksum --delete equivalent: copy changed files, remove extras."""
    dst.mkdir(parents=True, exist_ok=True)
    src_names = {p.name for p in src.iterdir() if p.is_file() and p.name not in exclude}
    for p in sorted(dst.iterdir()):
        if p.is_file() and p.name not in src_names:
            p.unlink()
    copied = 0
    for name in sorted(src_names):
        s, d = src / name, dst / name
        if not d.exists() or s.stat().st_size != d.stat().st_size or \
           sha256_of(s) != sha256_of(d):
            shutil.copyfile(s, d)
            copied += 1
    print(f"synced {src} -> {dst} ({copied} updated, {len(src_names)} total)")


def copytree_overlay(src: Path, dst: Path) -> None:
    """copy_tree-like that overwrites instead of failing on existing dirs."""
    if src.is_dir():
        dst.mkdir(parents=True, exist_ok=True)
        for child in src.iterdir():
            copytree_overlay(child, dst / child.name)
    elif src.is_file():
        dst.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(src, dst)


def find_extractor():
    # bsdtar reads ISO9660 directly; Windows 10+ ships it as tar.exe.
    for name in ("bsdtar", "tar"):
        exe = shutil.which(name)
        if exe:
            return ("tar", exe)
    for name in ("7z", "7za"):
        exe = shutil.which(name)
        if exe:
            return ("7z", exe)
    return (None, None)


def find_binary(name: str) -> Path:
    exe = name + (".exe" if os.name == "nt" else "")
    hits = sorted(BUILD.rglob(exe))
    if not hits:
        die(f"{exe} not found under {BUILD} after build")
    return hits[0]


# ------------------------------------------------------------------------------------------------
# Stage 1: platform + dependency detection
# ------------------------------------------------------------------------------------------------
def _cmake_version() -> Optional[tuple[int, int]]:
    if not shutil.which("cmake"):
        return None
    txt = run_capture(["cmake", "--version"])
    for line in txt.splitlines():
        if line.lower().startswith("cmake version"):
            parts = line.split("version", 1)[1].strip().split()[0].split(".")
            try:
                return (int(parts[0]), int(parts[1]))
            except (ValueError, IndexError):
                return None
    return None


def _distro_name() -> str:
    try:
        txt = Path("/etc/os-release").read_text(errors="replace")
    except OSError:
        return ""
    for line in txt.splitlines():
        if line.startswith("ID="):
            return line.split("=", 1)[1].strip().strip('"')
    return ""


def _detect_pkg_mgr() -> Optional[str]:
    for name, probe in (
        ("apt", "apt-get"), ("dnf", "dnf"), ("pacman", "pacman"), ("zypper", "zypper"),
    ):
        if shutil.which(probe):
            return name
    return None


def _qt_prefix() -> Optional[Path]:
    for env in ("QT_ROOT", "QTDIR", "CMAKE_PREFIX_PATH"):
        v = os.environ.get(env)
        if not v:
            continue
        for candidate in v.split(os.pathsep):
            p = Path(candidate)
            if (p / "lib" / "cmake" / "Qt6").is_dir() or (p / "bin" / "qmake6").exists():
                return p
    candidates = [
        ROOT / "build" / "qt" / QT_VERSION / QT_KIT_WINDOWS,
        Path.home() / "Qt" / QT_VERSION / QT_KIT_WINDOWS,
    ]
    # Any kit already unpacked under build/qt/<ver>/<kit> counts, but only on Windows: those kits are
    # MSVC builds and unusable on Linux/macOS.
    if os.name == "nt" and (ROOT / "build" / "qt").is_dir():
        candidates += sorted((ROOT / "build" / "qt").glob(f"*/{QT_KIT_WINDOWS}"))
        candidates += sorted((ROOT / "build" / "qt").glob("*/*"))
    if sys.platform == "darwin":
        brew = shutil.which("brew")
        if brew:
            prefix = run_capture([brew, "--prefix", "qt"]).strip()
            if prefix:
                candidates.insert(0, Path(prefix))
    for c in candidates:
        if (c / "lib" / "cmake" / "Qt6").is_dir() or (c / "bin" / "qmake6").exists():
            return c
    for p in (Path("/usr/lib/cmake/Qt6"), Path("/usr/lib/x86_64-linux-gnu/cmake/Qt6")):
        if p.is_dir():
            return p.parent.parent
    return None


def _mesa_dir_present(c: Optional[Path]) -> bool:
    return bool(c) and ((c / "vulkan_lvp.dll").exists() or (c / "lavapipe" / "vulkan_lvp.dll").exists())


def _vswhere() -> Optional[str]:
    on_path = shutil.which("vswhere")
    if on_path:
        return on_path
    for base in (os.environ.get("ProgramFiles(x86)"), os.environ.get("ProgramFiles")):
        if not base:
            continue
        p = Path(base) / "Microsoft Visual Studio" / "Installer" / "vswhere.exe"
        if p.exists():
            return str(p)
    return None


def _msvc_toolset_present() -> bool:
    """True when a VC toolset (and preferably clang-cl) is installed, even outside a dev prompt."""
    if os.environ.get("VCToolsInstallDir"):
        return True
    for base in (os.environ.get("ProgramFiles(x86)"), os.environ.get("ProgramFiles")):
        if not base:
            continue
        for edition in ("BuildTools", "Community", "Professional", "Enterprise"):
            vc = Path(base) / "Microsoft Visual Studio" / "2022" / edition / "VC" / "Auxiliary" / "Build"
            if (vc / "vcvars64.bat").exists():
                return True
    return False



@dataclass
class PlatformInfo:
    os: str                 # windows | linux | macos
    arch: str
    distro: str
    pkg_mgr: Optional[str]
    in_container: bool
    interactive: bool
    tools: dict = field(default_factory=dict)      # name -> description/path/None
    qt_prefix: Optional[Path] = None
    lavapipe_dir: Optional[Path] = None

    @property
    def is_windows(self) -> bool:
        return self.os == "windows"

    @property
    def is_macos(self) -> bool:
        return self.os == "macos"

    def exe(self, name: str) -> str:
        return name + ".exe" if self.is_windows else name

    # --- toolchain -------------------------------------------------------------------------------
    def vs_dev_prompt(self) -> bool:
        """True when this shell has the MSVC environment loaded (vcvars) or clang-cl available."""
        return bool(os.environ.get("VCToolsInstallDir") or os.environ.get("INCLUDE"))

    def configure_extra(self, build_dir: Path) -> list:
        """CMake flags for this platform. Mirrors the historical setup.py behaviour."""
        extra = ["-DCMAKE_BUILD_TYPE=Release"]   # a Windows Ninja/clang-cl configure once came up Debug
        # ps2xStudio (the editor tool) fetches four git branches at configure time; a network hiccup
        # there aborted a user's whole game build. The game does not need it.
        extra.append("-DPS2X_BUILD_STUDIO=" + ("ON" if os.environ.get("PS2X_SETUP_STUDIO") == "1" else "OFF"))
        if self.is_macos:
            extra += ["-DCMAKE_C_COMPILER=clang", "-DCMAKE_CXX_COMPILER=clang++"]
            # paraLLEl-GS does not build on macOS (Granite's sleep_until_nsecs has no Darwin path).
            if os.environ.get("PS2X_SETUP_PGS") != "1":
                extra.append("-DPS2X_DISABLE_PGS=ON")
            if os.environ.get("MACOSX_DEPLOYMENT_TARGET"):
                extra.append("-DCMAKE_OSX_DEPLOYMENT_TARGET=" + os.environ["MACOSX_DEPLOYMENT_TARGET"])
            if not (build_dir / "CMakeCache.txt").exists() and shutil.which("ninja"):
                extra += ["-G", "Ninja"]
        if not self.is_windows:
            return extra
        cache = build_dir / "CMakeCache.txt"
        if cache.exists():
            gen = ""
            for line in cache.read_text(errors="replace").splitlines():
                if line.startswith("CMAKE_GENERATOR:"):
                    gen = line.split("=", 1)[1]
                    break
            if "Visual Studio" not in gen:
                return extra
        # Prefer Ninja + clang-cl in a developer prompt: Ninja compiles every file in parallel,
        # whereas the Visual Studio generator hands the runner's ~1000 unity units to MSBuild.
        if (os.environ.get("PS2X_SETUP_GENERATOR", "ninja").lower() != "vs"
                and self.vs_dev_prompt() and shutil.which("ninja") and shutil.which("clang-cl")):
            return extra + ["-G", "Ninja", "-DCMAKE_C_COMPILER=clang-cl", "-DCMAKE_CXX_COMPILER=clang-cl"]
        return extra + ["-T", os.environ.get("PS2X_SETUP_TOOLSET", "ClangCL")]


def detect_platform() -> PlatformInfo:
    if os.name == "nt":
        osname = "windows"
    elif sys.platform == "darwin":
        osname = "macos"
    else:
        osname = "linux"
    arch = _platform.machine().lower() or "unknown"
    in_container = (not has_tty()) or Path("/.dockerenv").exists() or \
        bool(os.environ.get("BT3_IN_CONTAINER"))
    info = PlatformInfo(
        os=osname,
        arch=arch,
        distro=_distro_name() if osname == "linux" else "",
        pkg_mgr=_detect_pkg_mgr() if osname == "linux" else ("brew" if osname == "macos" else "winget"),
        in_container=in_container,
        interactive=has_tty() and not in_container,
    )
    cmv = _cmake_version()
    info.tools["cmake"] = (f"{cmv[0]}.{cmv[1]}" if cmv else None)
    info.tools["cmake_ok"] = "yes" if (cmv and cmv >= CMAKE_MIN) else "no"
    for name in ("ninja", "git", "clang", "clang-cl", "clang++", "bsdtar", "7z", "pkg-config", "ccache", "mold"):
        info.tools[name] = shutil.which(name)
    info.qt_prefix = _qt_prefix()
    info.tools["qt"] = str(info.qt_prefix) if info.qt_prefix else None
    if osname == "windows":
        info.tools["vswhere"] = _vswhere()
        info.tools["msvc"] = "yes" if _msvc_toolset_present() else None
        info.tools["vcvars"] = "loaded" if info.vs_dev_prompt() else None
        for c in (ROOT / "build" / "mesa" / "x64",
                  Path(os.environ["PS2X_MESA_DIR"]) if os.environ.get("PS2X_MESA_DIR") else None):
            if _mesa_dir_present(c):
                info.lavapipe_dir = c
                break
    return info


def print_platform_report(info: PlatformInfo) -> None:
    print(f"Platform : {info.os} ({info.arch})" + (f" distro={info.distro}" if info.distro else ""))
    print(f"Package  : {info.pkg_mgr or 'not detected'}"
          + ("  [container/non-interactive]" if info.in_container else ""))
    print(f"Build dir: {BUILD}")
    print(f"Work dir : {WORK}")
    print("Tools:")
    for name in ("cmake", "cmake_ok", "ninja", "git", "clang", "clang-cl", "bsdtar", "7z",
                 "pkg-config", "ccache", "mold", "vswhere", "msvc", "vcvars", "qt"):
        if name not in info.tools:
            continue
        value = info.tools[name]
        mark = "OK " if value else "-- "
        print(f"  {mark}{name:<11} {value or 'missing'}")


def stage_detect(ctx: "Context") -> None:
    step("stage 1: platform detection")
    print_platform_report(ctx.platform)
    if ctx.args.report == "json":
        print(json.dumps({
            "os": ctx.platform.os, "arch": ctx.platform.arch, "distro": ctx.platform.distro,
            "pkg_mgr": ctx.platform.pkg_mgr, "in_container": ctx.platform.in_container,
            "tools": {k: (str(v) if v is not None else None) for k, v in ctx.platform.tools.items()},
        }, indent=2))


# ------------------------------------------------------------------------------------------------
# Stage 2: dependencies
# ------------------------------------------------------------------------------------------------
@dataclass
class Dep:
    name: str
    check: Callable[[PlatformInfo], bool]
    hint: str            # what to install (shown to the user)
    install: Optional[Callable[["Context"], None]] = None   # filled in stage 2 execution


def _have(name: str) -> Callable[[PlatformInfo], bool]:
    return lambda info: bool(shutil.which(name))


def _download(url: str, dst: Path) -> None:
    import urllib.request
    print(f"+ download {url} -> {dst}")
    dst.parent.mkdir(parents=True, exist_ok=True)

    def hook(blocks, bs, total):
        if total > 0:
            print(f"\r  {min(100, blocks * bs * 100 // total):3d}%", end="", flush=True)

    urllib.request.urlretrieve(url, dst, reporthook=hook)
    print()


def _inst_winget(ctx: "Context", pkg_id: str, override: Optional[str] = None) -> None:
    exe = shutil.which("winget")
    if not exe:
        raise RuntimeError("winget not found (install 'App Installer' from the Microsoft Store)")
    cmd = [exe, "install", "--id", pkg_id, "--accept-package-agreements",
           "--accept-source-agreements", "--silent", "--disable-interactivity"]
    if override:
        cmd += ["--override", override]
    run(cmd)


def _inst_pip(ctx: "Context", module: str) -> None:
    run([sys.executable, "-m", "pip", "install", "--upgrade", module])


def _inst_aqt(ctx: "Context") -> None:
    run([sys.executable, "-m", "aqt", "install-qt", "windows", "desktop",
         QT_VERSION, QT_KIT_WINDOWS, "--outputdir", str(ROOT / "build" / "qt")])


def _inst_mesa(ctx: "Context") -> None:
    mesa_dir = ROOT / "build" / "mesa"
    seven = mesa_dir / "7zr.exe"
    if not seven.exists():
        _download(DEPS_7ZR_URL, seven)
    archive = mesa_dir / "mesa.7z"
    _download(f"https://github.com/pal1000/mesa-dist-win/releases/download/"
              f"{MESA_LAVAPIPE_VERSION}/mesa3d-{MESA_LAVAPIPE_VERSION}-release-msvc.7z", archive)
    run([seven, "x", archive, f"-o{mesa_dir}", "-y"])
    archive.unlink(missing_ok=True)


def _inst_pkg(ctx: "Context", group: str) -> None:
    """Install a distro package group with the detected manager (sudo when not root)."""
    mgr = ctx.platform.pkg_mgr or "apt"
    packages = LINUX_GROUPS.get(mgr, {}).get(group)
    if not packages:
        raise RuntimeError(f"no package mapping for {mgr}/{group}")
    cmd = {
        "apt": ["apt-get", "install", "-y"],
        "dnf": ["dnf", "install", "-y"],
        "pacman": ["pacman", "-S", "--noconfirm"],
        "zypper": ["zypper", "--non-interactive", "install"],
    }.get(mgr)
    if cmd is None:
        raise RuntimeError(f"unsupported package manager: {mgr}")
    full = cmd + packages.split()
    if hasattr(os, "geteuid") and os.geteuid() != 0:
        full = ["sudo"] + full
    run(full)


def _inst_brew(ctx: "Context", packages: str) -> None:
    run(["brew", "install"] + packages.split())


def _inst_xcode(ctx: "Context") -> None:
    run(["xcode-select", "--install"])


def deps_for(info: PlatformInfo) -> list[Dep]:
    """The dependency list for this platform. Checks are real (versions/kits), not just PATH probes."""
    if info.is_windows:
        cmv = _cmake_version()
        vs_components = ("--quiet --wait --norestart --nocache "
                         "--add Microsoft.VisualStudio.Component.VC.Tools.x86.x64 "
                         "--add Microsoft.VisualStudio.Component.VC.Llvm.Clang "
                         "--add Microsoft.VisualStudio.Component.VC.Llvm.ClangToolset "
                         "--add Microsoft.VisualStudio.Component.Windows11SDK.22621")
        return [
            Dep("Visual Studio Build Tools + ClangCL",
                lambda i: i.tools.get("msvc") == "yes" or bool(i.tools.get("vswhere")),
                f"winget install Microsoft.VisualStudio.2022.BuildTools --override \"{vs_components}\"",
                lambda ctx: _inst_winget(ctx, "Microsoft.VisualStudio.2022.BuildTools",
                                         override=vs_components)),
            Dep(f"CMake >= {CMAKE_MIN[0]}.{CMAKE_MIN[1]}",
                lambda i: bool(cmv and cmv >= CMAKE_MIN),
                "winget install Kitware.CMake",
                lambda ctx: _inst_winget(ctx, "Kitware.CMake")),
            Dep("Ninja", _have("ninja"), "winget install Ninja-build.Ninja",
                lambda ctx: _inst_winget(ctx, "Ninja-build.Ninja")),
            Dep("Python 3", _have("python"), "winget install Python.Python.3.12",
                lambda ctx: _inst_winget(ctx, "Python.Python.3.12")),
            Dep("aqtinstall (pip)",
                lambda i: bool(run_capture([sys.executable, "-m", "pip", "show", "aqtinstall"])),
                "python -m pip install aqtinstall",
                lambda ctx: _inst_pip(ctx, "aqtinstall")),
            Dep("pefile (pip)",
                lambda i: bool(run_capture([sys.executable, "-m", "pip", "show", "pefile"])),
                "python -m pip install pefile",
                lambda ctx: _inst_pip(ctx, "pefile")),
            Dep(f"Qt {QT_VERSION} ({QT_KIT_WINDOWS})", lambda i: bool(i.qt_prefix),
                f"aqt install-qt windows desktop {QT_VERSION} {QT_KIT_WINDOWS} --outputdir build/qt",
                _inst_aqt),
            Dep("Mesa lavapipe (Vulkan fallback)", lambda i: bool(i.lavapipe_dir),
                f"download mesa-dist-win {MESA_LAVAPIPE_VERSION} and extract to build/mesa",
                _inst_mesa),
        ]
    if info.is_macos:
        return [
            Dep("Xcode Command Line Tools", lambda i: bool(shutil.which("clang")),
                "xcode-select --install", _inst_xcode),
            Dep(f"CMake >= {CMAKE_MIN[0]}.{CMAKE_MIN[1]}",
                lambda i: bool(_cmake_version() and _cmake_version() >= CMAKE_MIN),
                "brew install cmake", lambda ctx: _inst_brew(ctx, "cmake")),
            Dep("Ninja", _have("ninja"), "brew install ninja", lambda ctx: _inst_brew(ctx, "ninja")),
            Dep("pkg-config", _have("pkg-config"), "brew install pkg-config",
                lambda ctx: _inst_brew(ctx, "pkg-config")),
            Dep("FFmpeg", lambda i: bool(shutil.which("pkg-config")) and
                subprocess.run(["pkg-config", "--exists", "libavcodec"], capture_output=True).returncode == 0,
                "brew install ffmpeg", lambda ctx: _inst_brew(ctx, "ffmpeg")),
            Dep("Qt 6", lambda i: bool(i.qt_prefix), "brew install qt",
                lambda ctx: _inst_brew(ctx, "qt")),
        ]
    return [
        Dep("build toolchain (clang/cmake/ninja/pkg-config)", lambda i: all(
                shutil.which(t) for t in ("clang", "cmake", "ninja", "pkg-config")),
            f"{info.pkg_mgr or 'apt'} install <toolchain packages>",
            lambda ctx: _inst_pkg(ctx, "toolchain")),
        Dep("FFmpeg dev libs", lambda i: bool(shutil.which("pkg-config")) and
            subprocess.run(["pkg-config", "--exists", "libavcodec"], capture_output=True).returncode == 0,
            f"{info.pkg_mgr or 'apt'} install <ffmpeg dev package>",
            lambda ctx: _inst_pkg(ctx, "ffmpeg")),
        Dep("Qt 6 (launcher)", lambda i: bool(i.qt_prefix),
            f"{info.pkg_mgr or 'apt'} install <qt6 base dev package>",
            lambda ctx: _inst_pkg(ctx, "qt")),
    ]

def stage_deps(ctx: "Context") -> None:
    """Report the platform dependencies, then (interactively) install what is missing."""
    step("stage 2: dependencies")
    deps = deps_for(ctx.platform)
    missing = [d for d in deps if not d.check(ctx.platform)]
    for d in deps:
        print(f"  {'OK ' if d not in missing else '-- '}{d.name}")
    if not missing:
        print("All dependencies present.")
        return
    print(f"\n{len(missing)} dependency(ies) missing:")
    for d in missing:
        print(f"  - {d.name}\n      install: {d.hint}")
    if ctx.args.dry_run or ctx.args.no_deps:
        print("(not installing: --dry-run/--no-deps)")
        return
    for d in missing:
        if d.install is None:
            die(f"cannot install automatically: {d.name}\n  install manually: {d.hint}", 2)
        if not ask_yes_no(ctx, f"Install {d.name} now?", default=True):
            die(f"missing dependency: {d.name}\n  install manually: {d.hint}", 2)
        try:
            d.install(ctx)
        except Exception as e:   # noqa: BLE001
            die(f"failed to install {d.name}: {e}\n  install manually: {d.hint}", 2)
        if not d.check(ctx.platform):
            # winget/brew installs land outside this process' PATH; the tool is usually fine from a new
            # shell, so warn with the exact command instead of pretending it worked.
            warn(f"{d.name} is still not visible in this shell; open a new one if the build cannot find it."
                 f"\n  expected: {d.hint}")
        else:
            print(f"  installed: {d.name}")


# ------------------------------------------------------------------------------------------------
# Stage 3: build pipeline
# ------------------------------------------------------------------------------------------------
def configured(build_dir: Path, info: PlatformInfo) -> bool:
    """True when the build dir holds a COMPLETED configure. CMakeCache.txt alone is not enough:
    a half-failed configure leaves the cache behind and `cmake --build` then dies."""
    if not (build_dir / "CMakeCache.txt").exists():
        return False
    cache_text = (build_dir / "CMakeCache.txt").read_text(errors="replace")
    if info.is_macos and os.environ.get("MACOSX_DEPLOYMENT_TARGET"):
        desired = os.environ["MACOSX_DEPLOYMENT_TARGET"]
        if not any(line.startswith("CMAKE_OSX_DEPLOYMENT_TARGET:") and line.endswith("=" + desired)
                   for line in cache_text.splitlines()):
            return False
    if info.is_macos:
        desired_pgs = "OFF" if os.environ.get("PS2X_SETUP_PGS") == "1" else "ON"
        if not any(line.startswith("PS2X_DISABLE_PGS:") and line.endswith("=" + desired_pgs)
                   for line in cache_text.splitlines()):
            return False
    if any((build_dir / f).exists() for f in ("build.ninja", "Makefile", "ALL_BUILD.vcxproj")):
        return True
    return any(build_dir.glob("*.sln"))


def cmake_configure(info: PlatformInfo, build_dir: Path) -> None:
    run(["cmake", "-S", ROOT, "-B", build_dir] + info.configure_extra(build_dir))


def cmake_build(info: PlatformInfo, build_dir: Path, target: str, jobs: str) -> None:
    cmd = ["cmake", "--build", build_dir, "--target", target, "-j", jobs]
    if info.is_windows:
        cmd += ["--config", "Release"]   # multi-config generators
    run(cmd)


def extract_inputs(ctx: "Context") -> None:
    """Step 1: obtain the two files source generation needs (the boot ELF and DBZP.BIN)."""
    if ctx.args.skip_setup:
        print("--skip-setup: reusing existing games/bt3/work/ and generated sources")
        return
    WORK.mkdir(parents=True, exist_ok=True)
    src = ctx.src
    if src.suffix.lower() == ".iso":
        kind, exe = find_extractor()
        if not exe:
            die("need bsdtar/tar (Windows 10+ ships tar.exe) or 7z to extract the ISO")
        members = ["SLUS_216.78", "BIN/DBZP.BIN"]
        step(f"extracting {', '.join(members)} from the ISO with {exe}")
        if kind == "tar":
            run([exe, "-xf", src, "-C", WORK, *members])
        else:
            run([exe, "x", "-y", f"-o{WORK}", src, *members], stdout=subprocess.DEVNULL)
        if not ctx.elf.is_file():
            die("SLUS_216.78 not found in ISO (is this the USA release?)")
        if not (WORK / "BIN" / "DBZP.BIN").is_file():
            die("BIN/DBZP.BIN not found in ISO (is this the USA release?)")
        make_writable(WORK)
    else:
        # A bare ELF build: the caller supplies SLUS_216.78 directly. BIN/DBZP.BIN still has to be
        # present in WORK.
        if WORK.exists():
            make_writable(WORK)
        shutil.copyfile(src, ctx.elf)
        make_writable(WORK)
        print("NOTE: you passed a bare ELF. The build also needs the ISO's")
        print(f"      BIN/DBZP.BIN next to it in {WORK}.")


def verify_elf(ctx: "Context") -> None:
    if ctx.args.skip_setup:
        return
    got = sha256_of(ctx.elf)
    if got != ELF_SHA256:
        print(f"ERROR: ELF sha256 mismatch.\n  expected: {ELF_SHA256}\n  got:      {got}")
        print("Only the USA release (SLUS-21678) is supported. Set PS2X_SETUP_FORCE=1 to continue anyway.")
        if os.environ.get("PS2X_SETUP_FORCE") != "1":
            sys.exit(1)


def gen_vu1(ctx: "Context") -> None:
    """Step 2b: the static VU1 recompiler input, cut from the ELF and translated to C++.
    Runs with --skip-setup too: it takes seconds and a tree without the file still builds."""
    step("generating VU1 programs from the ELF")
    sys.path.insert(0, str(HERE))
    from vu1_programs import generate as generate_vu1
    generate_vu1(ctx.elf, ROOT / "ps2xRuntime", WORK / "vu1")


def fetch_submodules() -> None:
    """The paraLLEl-GS backend lives in a git submodule; CMake builds it only when present."""
    if os.environ.get("PS2X_SETUP_NO_SUBMODULES") or not (ROOT / ".gitmodules").exists() or not shutil.which("git"):
        return
    try:
        run(["git", "-C", ROOT, "submodule", "update", "--init", "--recursive"])
    except Exception as e:   # noqa: BLE001
        print(f"== submodule fetch failed ({e}); building without the paraLLEl-GS backend")


def build_recompiler(ctx: "Context") -> Path:
    step("building recompiler")
    if not configured(BUILD, ctx.platform):
        cmake_configure(ctx.platform, BUILD)
    cmake_build(ctx.platform, BUILD, "ps2_recomp", str(os.cpu_count() or 4))
    return find_binary("ps2_recomp")


def generate_runner(ctx: "Context", recomp: Path) -> None:
    """Step 4: deduplicate/split the function map and generate the runner sources."""
    step("generating runner sources")
    sys.path.insert(0, str(HERE))
    from split_functions import split_csv
    split = WORK / "functions_split.csv"
    split_csv(ctx.elf, HERE / "functions.csv", split)
    out = WORK / "output"
    if out.exists():
        shutil.rmtree(out)
    cfg_text = (HERE / "config.toml.in").read_text()
    cfg_text = (cfg_text.replace("@ELF@", ctx.elf.as_posix())
                        .replace("@CSV@", split.as_posix())
                        .replace("@OUT@", out.as_posix() + "/"))
    (WORK / "config.toml").write_text(cfg_text)
    run([recomp, WORK / "config.toml"])

    # Step 5: post-generation patches + the overlay module from DBZP.BIN.
    run([sys.executable, HERE / "apply_patches.py", out])
    step("generating overlay sources from BIN/DBZP.BIN")
    run([sys.executable, HERE / "gen_overlay.py",
         "--recomp", recomp, "--dbzp", WORK / "BIN" / "DBZP.BIN",
         "--work", WORK / "overlay", "--runtime", ROOT / "ps2xRuntime"])
    run([sys.executable, HERE / "apply_overlay_patches.py", ROOT / "ps2xRuntime"])

    # Step 6: install into the runtime tree.
    step("installing runner sources")
    rt = ROOT / "ps2xRuntime"
    sync_tree(out, rt / "src" / "runner",
              exclude=("ps2_recompiled_functions.h", "ps2_recompiled_stubs.h"))
    for h in ("ps2_recompiled_functions.h", "ps2_recompiled_stubs.h"):
        shutil.copyfile(out / h, rt / "include" / h)


def build_runner(ctx: "Context", jobs: str) -> Path:
    """Step 7: build the game. Reconfigure explicitly when the runner source SET changed: the
    Visual Studio generator does not reliably re-glob within the same build invocation."""
    rt = ROOT / "ps2xRuntime"
    cache = BUILD / "CMakeCache.txt"
    need_cfg = not configured(BUILD, ctx.platform)
    if not need_cfg:
        ct = cache.stat().st_mtime
        for d in (rt / "src" / "runner", rt / "src" / "runner_overlay"):
            if d.exists() and d.stat().st_mtime > ct:
                need_cfg = True
                break
    if need_cfg:
        cmake_configure(ctx.platform, BUILD)
    step(f"building ps2EntryRunner (-j{jobs}, this takes a while)")
    cmake_build(ctx.platform, BUILD, "ps2EntryRunner", jobs)
    return find_binary("ps2EntryRunner")


def stage_build(ctx: "Context") -> None:
    step("stage 3: build")
    if ctx.args.skip_setup:
        if not (WORK / "SLUS_216.78").is_file():
            die("--skip-setup requires an existing games/bt3/work/ (no SLUS_216.78 found)")
    if not ctx.args.skip_setup:
        extract_inputs(ctx)
        verify_elf(ctx)
    gen_vu1(ctx)
    if not ctx.args.skip_setup:
        fetch_submodules()
        recomp = build_recompiler(ctx)
        generate_runner(ctx, recomp)
    if ctx.args.gen_only:
        print("--gen-only: runner + overlay sources generated (skipping runner build)")
        ctx.runner = None
        return
    ctx.runner = build_runner(ctx, ctx.jobs)


# ------------------------------------------------------------------------------------------------
# Stage 4: deploy (+ packaging, added in the packaging phase)
# ------------------------------------------------------------------------------------------------
def deploy_tree(runner: Path, out: Path) -> None:
    """Assemble the portable tree in OUT.

    layout: OUT/savedata/ (settings.toml; existing user saves are preserved), OUT/assets/ (fonts).
    No game data is deployed: the launcher's install wizard extracts SLUS_216.78 + BIN/ DATA/ IRX/
    SYSTEM.CNF from the user's own ISO into OUT/data on first run.
    """
    step(f"assembling deploy tree in {out}")
    out.mkdir(parents=True, exist_ok=True)
    save_dst = out / "savedata"
    save_dst.mkdir(parents=True, exist_ok=True)
    cfg_src = runner.parent / "settings.toml"
    cfg_dst = save_dst / "settings.toml"
    if cfg_src.exists() and not cfg_dst.exists():
        shutil.copy2(cfg_src, cfg_dst)
        print(f"  copied default settings -> {cfg_dst}")
    for a in ("assets",):
        src = runner.parent / a
        if src.exists():
            copytree_overlay(src, out / a)
    if os.name == "nt":
        for p in runner.parent.glob("*.dll"):
            shutil.copy2(p, out / p.name)
    shutil.copy2(runner, out / runner.name)
    shutil.copymode(runner, out / runner.name)
    print(f"  runner -> {out / runner.name}")
    print(f"Deploy tree ready: {out}")


def _release_out(ctx: "Context") -> Path:
    if ctx.args.output:
        return Path(ctx.args.output).resolve()
    sub = "release-windows" if ctx.platform.is_windows else "release"
    return BUILD / sub / "out"


def _is_qt_debug_dll(p: Path) -> bool:
    """Qt ships debug DLLs next to the release ones (Qt6Cored.dll). Only treat a file as debug when
    the release counterpart exists: some TLS backends legitimately end in 'd.dll'."""
    n = p.name
    if not n.endswith("d.dll"):
        return False
    return p.with_name(n[:-5] + ".dll").exists()


def build_launcher(ctx: "Context") -> Optional[Path]:
    """Configure + build the Qt launcher and return the built artifact (.exe, binary or .app)."""
    if ctx.args.skip_launcher or ctx.platform.is_macos:
        return None
    step("building the Qt launcher")
    src = ROOT / "ps2xRuntime" / "src" / "launcher"
    bdir = BUILD / ("launcher_qt" if ctx.platform.is_windows else "launcher")
    extra = ["-DCMAKE_BUILD_TYPE=Release"]
    if ctx.platform.qt_prefix:
        extra.append("-DCMAKE_PREFIX_PATH=" + str(ctx.platform.qt_prefix))
    if ctx.platform.is_windows:
        if (os.environ.get("PS2X_SETUP_GENERATOR", "ninja").lower() != "vs" and ctx.platform.vs_dev_prompt()
                and shutil.which("ninja") and shutil.which("clang-cl")):
            extra += ["-G", "Ninja", "-DCMAKE_C_COMPILER=clang-cl", "-DCMAKE_CXX_COMPILER=clang-cl"]
        else:
            extra += ["-T", os.environ.get("PS2X_SETUP_TOOLSET", "ClangCL")]
    run(["cmake", "-S", src, "-B", bdir] + extra)
    cmake_build(ctx.platform, bdir, "Launcher", ctx.jobs)
    exe = bdir / ctx.platform.exe("Launcher")
    if not exe.exists():
        die(f"Launcher not found after build ({exe})")
    return exe


def _vc_runtime_dll(name: str) -> Optional[Path]:
    for base in (os.environ.get("ProgramFiles(x86)"), os.environ.get("ProgramFiles")):
        if not base:
            continue
        for edition in ("BuildTools", "Community", "Professional", "Enterprise"):
            root = Path(base) / "Microsoft Visual Studio" / "2022" / edition / "VC" / "Redist" / "MSVC"
            if root.is_dir():
                hits = [h for h in sorted(root.rglob(name), reverse=True) if "x64" in h.parts]
                if hits:
                    return hits[0]
    sys32 = Path(os.environ.get("SystemRoot", r"C:\Windows")) / "System32" / name
    return sys32 if sys32.exists() else None


def copy_licences(stage: Path) -> None:
    """GPL-3.0 for the project and the LGPL-3.0 for the bundled paraLLEl-GS (the PE/floor gates and
    the packaging checks require both)."""
    for lic, name in ((ROOT / "LICENSE", "LICENSE"),
                      (ROOT / "ps2xRuntime" / "third_party" / "parallel-gs" / "COPYING.LGPLv3",
                       "COPYING.LGPLv3")):
        if lic.exists():
            shutil.copy2(lic, stage / name)
        else:
            warn(f"licence file not found: {lic}")


def bundle_windows(ctx: "Context", stage: Path, runner: Path, launcher: Path) -> None:
    """Flat self-contained layout: Qt + VC runtime + FFmpeg in lib/, critical DLLs next to the EXEs,
    qt.conf for plugin discovery, lavapipe as the software Vulkan fallback."""
    step("bundling the Windows runtime")
    stage_lib = stage / "lib"
    stage_lib.mkdir(parents=True, exist_ok=True)

    # The launcher boots <appDir>/bt3-runner.exe: rename the built ps2EntryRunner.exe.
    runner_name = "bt3-runner.exe"
    if (stage / runner_name).exists():
        pass
    elif (stage / "ps2EntryRunner.exe").exists():
        (stage / "ps2EntryRunner.exe").rename(stage / runner_name)
    else:
        shutil.copy2(runner, stage / runner_name)

    qt_bin = (ctx.platform.qt_prefix / "bin") if ctx.platform.qt_prefix else None
    if not qt_bin or not qt_bin.is_dir():
        die("Qt bin directory not found; install Qt (stage 2) or set QT_ROOT")
    for p in qt_bin.glob("Qt6*.dll"):
        if not _is_qt_debug_dll(p):
            shutil.copy2(p, stage_lib / p.name)

    plugins_src = None
    for cand in (ctx.platform.qt_prefix / "plugins", ctx.platform.qt_prefix / "share" / "qt6" / "plugins"):
        if cand.is_dir():
            plugins_src = cand
            break
    plugins_dst = stage_lib / "qt6" / "plugins"
    if plugins_src:
        plugins_dst.mkdir(parents=True, exist_ok=True)
        for p in plugins_src.rglob("*"):
            if p.is_dir():
                continue
            rel = p.relative_to(plugins_src)
            if rel.parts and rel.parts[0] == "sqldrivers":
                continue   # qsqlpsql needs a non-system LIBPQ.dll; unused
            if _is_qt_debug_dll(p):
                continue
            dst = plugins_dst / rel
            dst.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(p, dst)
    else:
        warn("Qt plugins directory not found; the platform plugin will be missing")

    # FFmpeg DLLs staged next to the runner by CMake POST_BUILD.
    for pattern in ("avcodec-*.dll", "avformat-*.dll", "avutil-*.dll",
                    "swresample-*.dll", "swscale-*.dll"):
        for p in stage.glob(pattern):
            shutil.move(str(p), str(stage_lib / p.name))

    for dll in ("vcruntime140.dll", "vcruntime140_1.dll", "msvcp140.dll",
                "msvcp140_1.dll", "msvcp140_2.dll"):
        src = _vc_runtime_dll(dll)
        if src:
            shutil.copy2(src, stage_lib / dll)
        else:
            warn(f"VC++ runtime {dll} not found; the target machine must install the VC++ redistributable")

    # Windows resolves DLLs from the EXE's directory before main(): flatten the critical ones so a
    # double-click works without a wrapper script.
    for dll in ("Qt6Core.dll", "Qt6Gui.dll", "Qt6Widgets.dll", "Qt6Network.dll",
                "Qt6Concurrent.dll", "Qt6OpenGL.dll", "Qt6OpenGLWidgets.dll",
                "msvcp140.dll", "msvcp140_1.dll", "msvcp140_2.dll",
                "vcruntime140.dll", "vcruntime140_1.dll"):
        src = stage_lib / dll
        if src.exists():
            shutil.copy2(src, stage / dll)

    (stage / "qt.conf").write_text("[Paths]\nPrefix = .\nPlugins = lib/qt6/plugins\n", encoding="ascii")

    copy_licences(stage)

    lvp = ctx.platform.lavapipe_dir
    if lvp and (lvp / "vulkan_lvp.dll").exists():
        lvp_dst = stage / "lavapipe"
        lvp_dst.mkdir(exist_ok=True)
        shutil.copy2(lvp / "vulkan_lvp.dll", lvp_dst / "vulkan_lvp.dll")
        icd = lvp / "lvp_icd.x86_64.json"
        if icd.exists():
            shutil.copy2(icd, lvp_dst / "lvp_icd.x86_64.json")
    else:
        warn("lavapipe not found; the Windows Vulkan fallback will be unavailable (stage 2 installs it)")

    if launcher is not None:
        shutil.copy2(launcher, stage / "Launcher.exe")
        assets = launcher.parent / "assets"
        if assets.is_dir():
            copytree_overlay(assets, stage / "assets")


LINUX_LIB_BLACKLIST = (
    "libc.so", "libm.so", "libpthread.so", "libdl.so", "librt.so", "libutil.so", "libresolv.so",
    "libnsl.so", "libstdc++.so", "libgcc_s.so", "ld-linux",
)


def _ldd_deps(path: Path) -> list[Path]:
    if not shutil.which("ldd"):
        return []
    out = run_capture(["ldd", str(path)])
    deps = []
    for line in out.splitlines():
        if "=>" in line:
            target = line.split("=>", 1)[1].strip().split(" ")[0]
        else:
            target = line.strip().split(" ")[0]
        if target.startswith("/") and Path(target).exists():
            deps.append(Path(target))
    return deps


def _bundle_closure(binaries: list[Path], stage_lib: Path) -> None:
    """Copy the transitive ldd closure of the binaries into lib/, minus the glibc/C++ core (the
    release relies on the distro's own runtime; bundling it caused GLIBC_PRIVATE clashes)."""
    stage_lib.mkdir(parents=True, exist_ok=True)
    seen: set[str] = set()
    queue = list(binaries)
    while queue:
        cur = queue.pop()
        for dep in _ldd_deps(cur):
            name = dep.name
            if name in seen or name.startswith(LINUX_LIB_BLACKLIST):
                continue
            seen.add(name)
            shutil.copy2(dep, stage_lib / name)
            queue.append(stage_lib / name)


def bundle_linux(ctx: "Context", stage: Path, runner: Path, launcher: Optional[Path]) -> None:
    step("bundling the Linux runtime")
    stage_lib = stage / "lib"
    stage_lib.mkdir(parents=True, exist_ok=True)

    bin_runner = stage / "bt3-runner"
    shutil.copy2(runner, bin_runner)
    bin_runner.chmod(bin_runner.stat().st_mode | stat.S_IEXEC | stat.S_IXGRP | stat.S_IXOTH)
    targets = [bin_runner]

    if launcher is not None:
        bin_launcher = stage / "Launcher"
        shutil.copy2(launcher, bin_launcher)
        bin_launcher.chmod(bin_launcher.stat().st_mode | stat.S_IEXEC | stat.S_IXGRP | stat.S_IXOTH)
        targets.append(bin_launcher)
        assets = launcher.parent / "assets"
        if assets.is_dir():
            copytree_overlay(assets, stage / "assets")

    _bundle_closure(targets, stage_lib)

    # Qt platform plugins are dlopened, so ldd does not see them: copy them explicitly plus their own
    # dependencies.
    plugin_src = None
    for cand in (Path("/usr/lib/x86_64-linux-gnu/qt6/plugins"), Path("/usr/lib/qt6/plugins")):
        if cand.is_dir():
            plugin_src = cand
            break
    plugins_dst = stage_lib / "qt6" / "plugins" / "platforms"
    if plugin_src and (plugin_src / "platforms").is_dir():
        plugins_dst.mkdir(parents=True, exist_ok=True)
        extra_bins = []
        for name in ("libqxcb.so", "libqoffscreen.so"):
            src = plugin_src / "platforms" / name
            if src.exists():
                shutil.copy2(src, plugins_dst / name)
                extra_bins.append(plugins_dst / name)
        if extra_bins:
            _bundle_closure(extra_bins, stage_lib)
    else:
        warn("Qt platform plugins not found; the launcher will not start without them")

    copy_licences(stage)

    (stage / "logs").mkdir(exist_ok=True)
    (stage / "savedata" / "BASLUS-21678DBZT3").mkdir(parents=True, exist_ok=True)
    installer = ROOT / "tools" / "release" / "install-game.sh.in"
    if installer.exists():
        dst = stage / "install game.sh"
        shutil.copy2(installer, dst)
        dst.chmod(dst.stat().st_mode | stat.S_IEXEC | stat.S_IXGRP | stat.S_IXOTH)


def seed_savedata(ctx: "Context", stage: Path) -> None:
    """settings.toml (only when absent), fps60 pacing table and the memory-card slot."""
    savedata = stage / "savedata"
    savedata.mkdir(parents=True, exist_ok=True)
    default = ROOT / "tools" / "release" / "settings.toml.default"
    cfg = savedata / "settings.toml"
    if default.exists() and not cfg.exists():
        shutil.copy2(default, cfg)
    fps60 = HERE / "fps60_sites.txt"
    if fps60.exists():
        shutil.copy2(fps60, savedata / "fps60_sites.txt")
    (savedata / "BASLUS-21678DBZT3").mkdir(exist_ok=True)


def run_gate(ctx: "Context", stage: Path) -> None:
    if ctx.platform.is_windows:
        gate = ROOT / "tools" / "release-windows" / "check_windows_deps.py"
        if gate.exists():
            step("running the PE dependency gate")
            run([sys.executable, str(gate), str(stage)])
        else:
            warn("PE gate script not found; skipping")
    elif ctx.platform.os == "linux":
        gate = ROOT / "tools" / "release" / "check_floor.sh"
        if gate.exists() and shutil.which("bash"):
            step("running the glibc floor gate")
            run(["bash", str(gate), str(stage)])


def package_artifact(ctx: "Context", out_root: Path, stage: Path) -> None:
    """Assemble the portable tree and produce the archive + sha256 for this OS."""
    import datetime
    import tarfile
    import zipfile

    tree_name = "Dragon Ball Budokai Tenkaichi 3 Recompiled"
    out_root.mkdir(parents=True, exist_ok=True)
    tree = out_root / tree_name
    if tree.exists():
        shutil.rmtree(tree)
    copytree_overlay(stage, tree)

    if ctx.platform.is_windows:
        archive = out_root / "BT3-Recomp-x86_64.zip"
        step(f"packaging {archive.name}")
        with zipfile.ZipFile(archive, "w", compression=zipfile.ZIP_DEFLATED, compresslevel=9) as z:
            for p in sorted(tree.rglob("*")):
                if p.is_file():
                    z.write(p, p.relative_to(out_root).as_posix())
    else:
        archive = out_root / "BT3-Recomp-x86_64.tar.gz"
        step(f"packaging {archive.name}")
        with tarfile.open(archive, "w:gz") as t:
            t.add(tree, arcname=tree_name)

    shutil.rmtree(tree)
    digest = sha256_of(archive)
    base = archive.name
    for suffix in (".tar.gz", ".zip"):
        if base.endswith(suffix):
            base = base[: -len(suffix)]
            break
    (out_root / (base + ".sha256")).write_text(f"{digest}  {archive.name}\n")
    print(f"  {archive}  ({archive.stat().st_size / (1 << 20):.1f} MB)")
    print(f"  sha256: {digest}")

    if not ctx.args.no_desktop_copy:
        desktop = Path.home() / "Desktop"
        if desktop.is_dir() and ask_yes_no(ctx, f"Copy the artifact to {desktop}?", default=False):
            shutil.copy2(archive, desktop / archive.name)


def stage_package(ctx: "Context") -> None:
    step("stage 4: deploy/package")
    if ctx.runner is None:
        ctx.runner = find_binary("ps2EntryRunner")

    if ctx.args.deploy and not ctx.args.package:
        deploy_tree(ctx.runner, Path(ctx.args.deploy).resolve())
        return

    out_root = _release_out(ctx)
    stage = out_root / "stage"
    if stage.exists():
        shutil.rmtree(stage)
    stage.mkdir(parents=True, exist_ok=True)
    deploy_tree(ctx.runner, stage)
    seed_savedata(ctx, stage)
    if ctx.args.deploy:
        deploy_tree(ctx.runner, Path(ctx.args.deploy).resolve())

    if ctx.platform.is_macos:
        bundler = ROOT / "tools" / "macos" / "deploy.py"
        if not bundler.exists():
            die("macOS bundler not found (tools/macos/deploy.py)")
        app = out_root / "BT3-Recomp.app"
        run([sys.executable, str(bundler), "--skip-build", "--output", str(app), "--jobs", ctx.jobs])
        print(f"App bundle ready: {app}")
        return

    launcher = build_launcher(ctx)
    if ctx.platform.is_windows:
        bundle_windows(ctx, stage, ctx.runner, launcher)
    else:
        bundle_linux(ctx, stage, ctx.runner, launcher)

    if not ctx.args.no_gate:
        run_gate(ctx, stage)

    if ctx.args.package:
        package_artifact(ctx, out_root, stage)
# ------------------------------------------------------------------------------------------------
# CLI + stage runner
# ------------------------------------------------------------------------------------------------
@dataclass
class Context:
    args: argparse.Namespace
    platform: PlatformInfo
    interactive: bool
    jobs: str
    src: Optional[Path] = None
    elf: Path = field(default_factory=lambda: WORK / "SLUS_216.78")
    runner: Optional[Path] = None
    run_mode: int = 1   # highest stage number requested


def parse_args(argv=None) -> argparse.Namespace:
    ap = argparse.ArgumentParser(
        description="Build (deploy and package) Dragon Ball Z: Budokai Tenkaichi 3.")
    ap.add_argument("src", nargs="?", metavar="<iso|elf>",
                    help="BT3 USA ISO or bare SLUS_216.78 ELF (not needed with --skip-setup)")
    ap.add_argument("--jobs", default=DEFAULT_JOBS, metavar="N",
                    help=f"parallel jobs for the ps2EntryRunner build (default {DEFAULT_JOBS})")
    ap.add_argument("--stage", metavar="N", help="run only this stage (1-4)")
    ap.add_argument("--stages", metavar="A-B", help="run a stage range, e.g. 3-4")
    ap.add_argument("--list-stages", action="store_true", help="print the stages and exit")
    ap.add_argument("--dry-run", action="store_true",
                    help="stage 1 + a report of what would be done; no changes")
    ap.add_argument("--report", choices=("text", "json"), default="text",
                    help="format of the stage 1 report")
    ap.add_argument("-y", "--yes", action="store_true", help="answer yes to every prompt")
    ap.add_argument("--non-interactive", action="store_true", help="never prompt")
    ap.add_argument("--install-deps", action="store_true", help="install missing dependencies")
    ap.add_argument("--no-deps", action="store_true", help="never install dependencies")
    ap.add_argument("--deps-only", action="store_true", help="stop after stage 2")
    ap.add_argument("--deploy", metavar="OUT",
                    help="after the build, assemble the playable tree into OUT")
    ap.add_argument("--package", action="store_true",
                    help="also produce the release artifact for this OS (+ checksum)")
    ap.add_argument("--output", metavar="DIR",
                    help="where the stage tree and the artifact go (default build/release-<os>/out)")
    ap.add_argument("--skip-launcher", action="store_true",
                    help="do not build the Qt launcher (developer tree without the UI)")
    ap.add_argument("--no-gate", dest="no_gate", action="store_true",
                    help="skip the release gate (PE imports / glibc floor)")
    ap.add_argument("--no-desktop-copy", dest="no_desktop_copy", action="store_true",
                    help="never offer to copy the artifact to the Desktop")
    ap.add_argument("--skip-setup", action="store_true",
                    help="skip ISO/recompile/patches; only rebuild the runner (+deploy)")
    ap.add_argument("--gen-only", action="store_true",
                    help="stop after recompile/generation/patches; do not build the runner")
    args = ap.parse_args(argv)
    if args.skip_setup and args.gen_only:
        die("--skip-setup and --gen-only are mutually exclusive")
    if args.install_deps and args.no_deps:
        die("--install-deps and --no-deps are mutually exclusive")
    return args


def wanted_stages(args: argparse.Namespace) -> set:
    if args.deps_only:
        return {"1", "2"}
    if args.stage:
        return {"1", args.stage}
    if args.stages:
        try:
            a, b = args.stages.split("-", 1)
            a, b = int(a), int(b)
        except ValueError:
            die(f"bad --stages value: {args.stages} (use A-B)")
        if a > b:
            a, b = b, a
        return {str(n) for n in range(max(1, a), min(4, b) + 1)} | {"1"}
    return {"1", "2", "3", "4"}


def resolve_source(ctx: "Context") -> None:
    """Fill ctx.src (and prompt for it when interactive)."""
    if ctx.args.skip_setup or ctx.args.dry_run:
        if ctx.args.src:
            ctx.src = Path(ctx.args.src).expanduser()
        return
    raw = ctx.args.src
    if not raw and ctx.interactive:
        p = ask_path(ctx, "BT3 USA ISO required. Paste the path (drag & drop works):", "file")
        if p:
            ctx.src = p
    elif raw:
        ctx.src = Path(raw).expanduser()
    if ctx.src is None:
        if ctx.interactive:
            die("no ISO/ELF provided")
        die("missing the BT3 ISO or SLUS_216.78 ELF path")
    if not ctx.src.exists():
        die(f"{ctx.src} does not exist")


def main(argv=None) -> None:
    args = parse_args(argv)
    if args.list_stages:
        for num, desc in STAGES:
            print(f"  --stage {num}   {desc}")
        return

    info = detect_platform()
    interactive = info.interactive and not args.non_interactive
    ctx = Context(args=args, platform=info, interactive=interactive, jobs=str(args.jobs))

    # --dry-run implies --no-deps and stops before stage 3.
    if args.dry_run:
        args.no_deps = True

    stages = wanted_stages(args)
    ctx.run_mode = max(int(s) for s in stages)

    stage_detect(ctx)
    if "2" in stages:
        stage_deps(ctx)

    if args.dry_run:
        if "3" in stages:
            print("\ndry-run: would build (stage 3) and deploy"
                  + (" and package" if args.package else "") + ".")
        return

    if "3" in stages and not args.deps_only:
        resolve_source(ctx)
        if ctx.src is not None and ctx.src.suffix.lower() != ".iso" and not args.skip_setup:
            # bare ELF: keep the historical behaviour of copying it into WORK
            pass
        stage_build(ctx)

    if "4" in stages and not args.deps_only:
        if ctx.runner is None and args.deploy:
            # --stage 4 (or --skip-setup) with an existing build: locate the runner.
            ctx.runner = find_binary("ps2EntryRunner")
        stage_package(ctx)

    if ctx.runner is not None and not args.deploy and not args.package:
        env_line = ("set PS2X_CD_IMAGE=<path to your BT3 ISO>& " if info.is_windows else
                    'env PS2X_CD_IMAGE="<path to your BT3 ISO>" ')
        step("done")
        print(f"Run with:\n\n  cd {ctx.runner.parent}\n  {env_line}\\\n      {ctx.runner} {ctx.elf}\n")


if __name__ == "__main__":
    main()
