#include "frontend/fe_picker.h"

#include "frontend/fe_ui.h"

#include "imgui.h"

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <system_error>

#if defined(_WIN32)
#  define WIN32_LEAN_AND_MEAN
#  define NOMINMAX
#  include <windows.h>
#endif

namespace
{
    std::string toLower(std::string s)
    {
        std::transform(s.begin(), s.end(), s.begin(),
                       [](unsigned char c) { return (char)std::tolower(c); });
        return s;
    }

    bool isDir(const std::filesystem::path &p)
    {
        std::error_code ec;
        return std::filesystem::is_directory(p, ec);
    }

    // Shorten a path for a one-line label: C:\Users\Rexx\Downloads -> C:\...\Downloads
    std::string shortPath(const std::filesystem::path &p)
    {
        const std::string s = p.string();
        if (s.size() <= 42)
            return s;
        return s.substr(0, 3) + "..." + s.substr(s.size() - 38);
    }

#if defined(_WIN32)
    // Volume label ("Windows", "DATA"), so two drives are told apart by more than their letter.
    std::string volumeLabel(const std::string &root)
    {
        char name[256] = "";
        const DWORD n = GetVolumeInformationA(root.c_str(), name, sizeof name, nullptr, nullptr,
                                              nullptr, nullptr, 0);
        if (n && name[0])
            return name;
        return std::string();
    }

    // Every drive Windows currently has mounted. The old picker started at C:\ and offered no way
    // out of it, which is exactly the case this replaces.
    void appendWindowsDrives(std::vector<std::pair<std::string, std::filesystem::path>> &out)
    {
        DWORD mask = GetLogicalDrives();
        for (int i = 0; i < 26; ++i)
        {
            if (!(mask & (1u << i)))
                continue;
            const std::string root = std::string(1, (char)('A' + i)) + ":\\";
            const UINT type = GetDriveTypeA(root.c_str());
            if (type == DRIVE_NO_ROOT_DIR)
                continue;   // an empty card reader slot, not a volume
            std::string label = volumeLabel(root);
            if (type == DRIVE_CDROM)
                label = label.empty() ? "CD/DVD" : label;
            else if (label.empty())
                label = type == DRIVE_REMOVABLE ? "Removible" : "Unidad";
            out.push_back({root + "  " + label, std::filesystem::path(root)});
        }
    }
#else
    void appendWindowsDrives(std::vector<std::pair<std::string, std::filesystem::path>> &) {}
#endif
}

namespace frontend
{
    void FilePicker::open(const std::string &title, std::filesystem::path startDir,
                          std::vector<std::string> extensions)
    {
        m_open = true;
        m_accepted = false;
        m_justOpened = true;   // the modal is opened by draw(), not here: it needs a frame
        m_title = title;
        m_exts = std::move(extensions);
        m_selected.clear();
        m_result.clear();
        buildPlaces();
        goTo(startDir);
    }

    void FilePicker::buildPlaces()
    {
        m_places.clear();
        std::vector<std::pair<std::string, std::filesystem::path>> drives;
        appendWindowsDrives(drives);
        for (auto &d : drives)
            m_places.push_back({d.first, d.second});

        // The user folders people actually keep dumps in, when they exist.
        std::error_code ec;
        std::filesystem::path home;
#if defined(_WIN32)
        if (const char *h = std::getenv("USERPROFILE"))
            home = h;
        else if (const char *h = std::getenv("HOME"))
            home = h;
#else
        if (const char *h = std::getenv("HOME"))
            home = h;
#endif
        if (home.empty())
            home = std::filesystem::current_path(ec);
        struct { const char *label; const char *sub; } shortcuts[] = {
            {"Descargas", "Downloads"}, {"Escritorio", "Desktop"}, {"Documentos", "Documents"},
            {"Videos", "Videos"},
        };
        for (const auto &s : shortcuts)
        {
            const std::filesystem::path p = home / s.sub;
            if (isDir(p))
                m_places.push_back({s.label, p});
        }
    }

    void FilePicker::goTo(const std::filesystem::path &p)
    {
        std::error_code ec;
        std::filesystem::path target = p;
        if (isDir(target))
        {
            m_dir = target;
        }
        else
        {
            // A file, or something that does not exist: start from the deepest parent that does.
            std::filesystem::path parent = target.parent_path();
            if (parent.empty())
                parent = std::filesystem::path(target).root_path();
            while (!parent.empty() && !isDir(parent))
                parent = parent.parent_path();
            if (parent.empty())
                parent = std::filesystem::current_path(ec);
            m_dir = parent;
        }
        m_selected.clear();
        listDir();
    }

    void FilePicker::acceptCurrent()
    {
        if (m_selected.empty())
            return;
        m_result = m_selected.string();
        m_accepted = true;
    }

    bool FilePicker::matches(const Entry &e) const
    {
        if (e.dir)
            return true;
        if (m_exts.empty())
            return true;
        const std::string lower = toLower(e.name);
        for (const std::string &x : m_exts)
            if (lower.size() >= x.size() && lower.compare(lower.size() - x.size(), x.size(), x) == 0)
                return true;
        return false;
    }

    void FilePicker::listDir()
    {
        m_entries.clear();
        std::error_code ec;
        if (!isDir(m_dir))
        {
            m_dir = m_dir.root_path();
            if (!isDir(m_dir))
                return;
        }
        std::snprintf(m_pathBuffer, sizeof m_pathBuffer, "%s", m_dir.string().c_str());

        for (const auto &de : std::filesystem::directory_iterator(m_dir, ec))
        {
            if (ec)
                break;
            Entry e;
            e.name = de.path().filename().string();
            if (e.name.empty() || e.name == "." || e.name == "..")
                continue;
            e.dir = de.is_directory(ec);
            if (!e.dir)
            {
                const std::uintmax_t sz = de.file_size(ec);
                if (!ec)
                    e.size = (unsigned long long)sz;
            }
            if (matches(e))
                m_entries.push_back(e);
        }
        std::sort(m_entries.begin(), m_entries.end(), [](const Entry &a, const Entry &b)
        {
            if (a.dir != b.dir)
                return a.dir;
            return toLower(a.name) < toLower(b.name);
        });
    }

    bool FilePicker::draw()
    {
        if (!m_open)
            return false;

        // Open on the frame the modal is asked for, not every frame: a repeated OpenPopup resets
        // the modal's state and swallows the click that was meant to close it.
        if (m_justOpened)
        {
            m_justOpened = false;
            ImGui::OpenPopup("##fe_picker");
        }

        bool result = false;
        const bool visible = ImGui::BeginPopupModal("##fe_picker", nullptr,
                                                    ImGuiWindowFlags_AlwaysAutoResize);
        if (visible)
        {
            ImGui::TextColored(fe::gold(), "%s", m_title.c_str());
            ImGui::Separator();

            // Places: every mounted volume first, then the user folders.
            if (!m_places.empty())
            {
                ImGui::TextDisabled("Ir a:");
                for (std::size_t i = 0; i < m_places.size(); ++i)
                {
                    if (i > 0)
                        ImGui::SameLine();
                    ImGui::PushID(static_cast<int>(i));
                    if (ImGui::SmallButton(m_places[i].label.c_str()))
                        goTo(m_places[i].path);
                    ImGui::PopID();
                }
                ImGui::Separator();
            }

            ImGui::SetNextItemWidth(560.0f);
            if (ImGui::InputText("##path", m_pathBuffer, sizeof m_pathBuffer))
            {
                const std::filesystem::path typed(m_pathBuffer);
                if (isDir(typed))
                    goTo(typed);
            }
            ImGui::SameLine();
            if (ImGui::Button("Ir"))
                goTo(std::filesystem::path(m_pathBuffer));
            ImGui::SameLine();
            if (ImGui::Button("Subir"))
            {
                const std::filesystem::path parent = m_dir.parent_path();
                if (!parent.empty())
                    goTo(parent);
            }
            ImGui::SameLine();
            ImGui::TextDisabled("  %s", shortPath(m_dir).c_str());

            ImGui::Separator();
            ImGui::BeginChild("##fe_picker_list", ImVec2(620.0f, 300.0f), ImGuiChildFlags_Borders);
            {
                ImDrawList *dl = ImGui::GetWindowDrawList();
                const ImU32 dirCol = ImGui::GetColorU32(fe::gold());
                const ImU32 fileCol = ImGui::GetColorU32(fe::dbz(0.62f, 0.68f, 0.78f));
                const ImU32 dimCol = ImGui::GetColorU32(fe::dbz(0.45f, 0.48f, 0.55f));
                const float rowH = ImGui::GetTextLineHeight();
                const std::filesystem::path listedDir = m_dir;

                for (const Entry &e : m_entries)
                {
                    ImGui::PushID(e.name.c_str());
                    // The row is an empty selectable and the glyph plus the text are painted on its
                    // draw list: Russo One has no folder or page character, and a "[DIR]" prefix
                    // read like a log line rather than a file browser.
                    const bool sel = !e.dir && m_selected == (m_dir / e.name);
                    ImGui::Selectable("##row", sel);
                    const ImVec2 a = ImGui::GetItemRectMin();
                    const ImVec2 b = ImGui::GetItemRectMax();
                    const float cy = (a.y + b.y) * 0.5f;
                    const float ix = a.x + 11.0f;

                    if (e.dir)
                    {
                        // Folder: body plus a tab on the top left.
                        const ImVec2 bodyMin(a.x + 4.0f, cy - rowH * 0.34f);
                        const ImVec2 bodyMax(a.x + 19.0f, cy + rowH * 0.40f);
                        dl->AddRectFilled(bodyMin, ImVec2(a.x + 12.0f, cy - rowH * 0.44f), dirCol);
                        dl->AddRectFilled(ImVec2(a.x + 4.0f, cy - rowH * 0.34f), bodyMax, dirCol);
                        dl->AddRectFilled(ImVec2(a.x + 4.0f, cy - rowH * 0.34f),
                                          ImVec2(a.x + 19.0f, cy - rowH * 0.20f), dirCol);
                    }
                    else
                    {
                        // Page: a rectangle with the top-right corner folded over.
                        const ImVec2 p0(a.x + 6.0f, cy - rowH * 0.44f);
                        const ImVec2 p1(a.x + 17.0f, cy + rowH * 0.44f);
                        const float fold = rowH * 0.22f;
                        dl->AddRectFilled(p0, p1, fileCol);
                        dl->AddTriangleFilled(ImVec2(p1.x - fold, p0.y), ImVec2(p1.x, p0.y),
                                              ImVec2(p1.x, p0.y + fold), dimCol);
                    }

                    const char *name = e.name.c_str();
                    dl->AddText(ImVec2(ix + 14.0f, a.y + (rowH - ImGui::GetFontSize()) * 0.5f),
                                sel ? dirCol : ImGui::GetColorU32(ImGuiCol_Text), name);
                    if (!e.dir)
                    {
                        char sz[64];
                        if (e.size >= 1073741824ull)
                            std::snprintf(sz, sizeof sz, "%.2f GB", e.size / 1073741824.0);
                        else
                            std::snprintf(sz, sizeof sz, "%.1f MB", e.size / 1048576.0);
                        const float w = ImGui::CalcTextSize(sz).x;
                        dl->AddText(ImVec2(b.x - 10.0f - w, a.y + (rowH - ImGui::GetFontSize()) * 0.5f),
                                    dimCol, sz);
                    }

                    if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
                    {
                        if (e.dir)
                            goTo(m_dir / e.name);
                        else
                        {
                            m_selected = m_dir / e.name;
                            acceptCurrent();
                        }
                    }
                    else if (ImGui::IsItemClicked(ImGuiMouseButton_Left))
                    {
                        if (e.dir)
                            goTo(m_dir / e.name);   // single click walks into the folder
                        else
                            m_selected = m_dir / e.name;
                    }
                    ImGui::PopID();
                    if (m_dir != listedDir)
                        break;   // the entry list was just rebuilt; stop iterating it
                }
            }
            ImGui::EndChild();

            ImGui::Separator();
            if (m_selected.empty())
                ImGui::TextDisabled("Double-click a file to choose it.");
            else
                ImGui::TextWrapped("%s", m_selected.string().c_str());
            ImGui::TextDisabled("%zu entradas%s", m_entries.size(),
                                m_exts.empty() ? "" : " (filtradas)");

            ImGui::BeginDisabled(m_selected.empty());
            if (ImGui::Button("Seleccionar"))
                acceptCurrent();
            ImGui::EndDisabled();
            ImGui::SameLine();
            if (ImGui::Button("Cancel"))
                m_open = false;
            // Inside the if, like comboRowStr: a Begin* that returns false opened no window.
            // BeginPopupModal even ends the popup itself when its own Begin fails, so ending it
            // here too was a double-end.
            ImGui::EndPopup();
        }

        if (m_accepted)
        {
            m_open = false;
            result = true;
            m_accepted = false;
        }
        return result;
    }
}
