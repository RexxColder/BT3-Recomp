#include "frontend/fe_picker.h"

#include "frontend/fe_ui.h"

#include "imgui.h"

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <system_error>

namespace
{
    std::string toLower(std::string s)
    {
        std::transform(s.begin(), s.end(), s.begin(),
                       [](unsigned char c) { return (char)std::tolower(c); });
        return s;
    }
}

namespace frontend
{
    void FilePicker::open(const std::string &title, std::filesystem::path startDir,
                          std::vector<std::string> extensions)
    {
        m_open = true;
        m_accepted = false;
        m_title = title;
        m_dir = startDir;
        m_selected.clear();
        m_result.clear();
        m_exts = std::move(extensions);
        std::snprintf(m_pathBuffer, sizeof m_pathBuffer, "%s", m_dir.string().c_str());
        listDir();
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
        if (!std::filesystem::is_directory(m_dir, ec))
        {
            // The typed path was not a directory: fall back to its parent.
            const std::filesystem::path parent = m_dir.parent_path();
            if (!parent.empty() && std::filesystem::is_directory(parent, ec))
                m_dir = parent;
            else
                return;
        }
        std::snprintf(m_pathBuffer, sizeof m_pathBuffer, "%s", m_dir.string().c_str());

        for (const auto &de : std::filesystem::directory_iterator(m_dir, ec))
        {
            Entry e;
            e.name = de.path().filename().string();
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

        ImGui::OpenPopup("##fe_picker");
        bool result = false;
        if (ImGui::BeginPopupModal("##fe_picker", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
        {
            ImGui::TextColored(fe::gold(), "%s", m_title.c_str());
            ImGui::Separator();

            ImGui::SetNextItemWidth(520.0f);
            if (ImGui::InputText("##path", m_pathBuffer, sizeof m_pathBuffer))
            {
                const std::filesystem::path typed(m_pathBuffer);
                std::error_code ec;
                if (std::filesystem::is_directory(typed, ec))
                {
                    m_dir = typed;
                    listDir();
                }
            }
            ImGui::SameLine();
            if (ImGui::Button("Ir"))
            {
                m_dir = std::filesystem::path(m_pathBuffer);
                listDir();
            }
            ImGui::SameLine();
            if (ImGui::Button(".."))
            {
                const std::filesystem::path parent = m_dir.parent_path();
                if (!parent.empty())
                {
                    m_dir = parent;
                    listDir();
                }
            }

            ImGui::Separator();
            ImGui::BeginChild("##fe_picker_list", ImVec2(520.0f, 320.0f), ImGuiChildFlags_Borders);
            for (const Entry &e : m_entries)
            {
                ImGui::PushID(e.name.c_str());
                if (e.dir)
                {
                    if (ImGui::Selectable(("[DIR] " + e.name).c_str()))
                    {
                        m_dir = m_dir / e.name;
                        listDir();
                    }
                }
                else
                {
                    char label[320];
                    std::snprintf(label, sizeof label, "%s   (%.1f MB)", e.name.c_str(),
                                  e.size / 1048576.0);
                    const bool sel = m_selected == (m_dir / e.name);
                    if (ImGui::Selectable(label, sel))
                        m_selected = m_dir / e.name;
                    if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
                    {
                        m_result = m_selected.string();
                        m_accepted = true;
                    }
                }
                ImGui::PopID();
            }
            ImGui::EndChild();

            ImGui::Separator();
            char picked[520];
            std::snprintf(picked, sizeof picked, "%s",
                          m_selected.empty() ? "(nada seleccionado)" : m_selected.string().c_str());
            ImGui::TextDisabled("%s", picked);
            ImGui::TextDisabled("Doble click para elegir. %zu entradas.", m_entries.size());

            ImGui::BeginDisabled(m_selected.empty());
            if (ImGui::Button("Seleccionar"))
            {
                m_result = m_selected.string();
                m_accepted = true;
            }
            ImGui::EndDisabled();
            ImGui::SameLine();
            if (ImGui::Button("Cancelar"))
                m_open = false;
            ImGui::EndPopup();

            if (!m_open || m_accepted)
            {
                m_open = false;
                result = m_accepted;
                m_accepted = false;
            }
        }
        return result;
    }
}
