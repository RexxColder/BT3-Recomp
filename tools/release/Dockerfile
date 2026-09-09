# Baseline build container. Ubuntu 22.04 (glibc 2.35) defines the runtime
# floor for every shipped binary and bundled shared library, so the deploy
# runs on any distro with glibc >= 2.35 (Ubuntu 22.04+/Debian 12+/Fedora
# 36+/all rolling) without bundling the C/C++ core.
FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive \
    TZ=UTC \
    LANG=C.UTF-8

RUN apt-get update && apt-get install -y --no-install-recommends \
        build-essential \
        clang \
        cmake \
        ninja-build \
        pkg-config \
        git \
        ca-certificates \
        curl \
        zstd \
        file \
        ccache \
        mold \
        # games/bt3/setup.py --gen-only: python3 + ISO extraction (bsdtar reads
        # ISO9660 directly; 7z as fallback; make -> bsdtar/7z come from apt)
        python3 \
        libarchive-tools \
        p7zip-full \
        make \
        # FFmpeg 4.4 (runner links libavcodec.so.58/libavformat.so.58)
        libavcodec-dev \
        libavformat-dev \
        libavutil-dev \
        libswresample-dev \
        libswscale-dev \
        # raylib 5.5 desktop deps (X11 + OpenGL)
        libx11-dev \
        libxrandr-dev \
        libxi-dev \
        libxcursor-dev \
        libxinerama-dev \
        libgl1-mesa-dev \
        libglu1-mesa-dev \
        # launcher (Qt 6.2, Widgets only; QFileDialog needs no extras)
        qt6-base-dev \
    && rm -rf /var/lib/apt/lists/*

# Never build as root inside the dev workspace: the host mounts are owned by
# the invoking user. ENTRYPOINT re-execs as that uid/gid when provided.
COPY entrypoint.sh /usr/local/bin/release-entrypoint
RUN chmod +x /usr/local/bin/release-entrypoint
ENTRYPOINT ["/usr/local/bin/release-entrypoint"]