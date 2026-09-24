#pragma once

// Small ImGui widget set shared by the front-end pages. Same visual language as the in-game
// overlay (ps2_settings_overlay.cpp) on purpose: one HUD, two hosts.

#include "imgui.h"

#include <cmath>
#include <cstdio>

namespace fe
{
    inline ImVec4 dbz(float r, float g, float b, float a = 1.0f) { return ImVec4(r, g, b, a); }
    inline ImVec4 accent(float a = 1.0f) { return dbz(1.00f, 0.62f, 0.10f, a); }
    inline ImVec4 gold(float a = 1.0f) { return dbz(1.00f, 0.80f, 0.30f, a); }
    inline ImVec4 okCol() { return dbz(0.25f, 0.73f, 0.31f); }
    inline ImVec4 warnCol() { return dbz(0.82f, 0.60f, 0.13f); }
    inline ImVec4 badCol() { return dbz(0.97f, 0.32f, 0.29f); }

    inline void sectionHeader(const char *label)
    {
        ImGui::Spacing();
        ImGui::PushStyleColor(ImGuiCol_Text, accent());
        ImGui::TextUnformatted(label);
        ImGui::PopStyleColor();
        ImGui::SameLine(ImGui::GetContentRegionAvail().x - 100.0f);
        ImGui::PushStyleColor(ImGuiCol_Separator, accent(0.35f));
        ImGui::Separator();
        ImGui::PopStyleColor();
    }

    inline void hint(const char *text)
    {
        ImGui::PushStyleColor(ImGuiCol_TextDisabled, dbz(0.29f, 0.39f, 0.44f));
        ImGui::TextWrapped("%s", text);
        ImGui::PopStyleColor();
    }

    inline void hintPending(const char *text)
    {
        ImGui::PushStyleColor(ImGuiCol_TextDisabled, warnCol());
        ImGui::TextWrapped("%s", text);
        ImGui::PopStyleColor();
    }

    // Checkbox with an ON/OFF badge, the same read as the overlay's toggleSwitch.
    inline bool toggleSwitch(const char *label, bool *v)
    {
        ImGui::PushID(label);
        const bool changed = ImGui::Checkbox(label, v);
        ImGui::SameLine();
        const bool on = *v;
        ImGui::PushStyleColor(ImGuiCol_Button, on ? accent() : dbz(0.25f, 0.25f, 0.32f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, on ? gold() : dbz(0.30f, 0.30f, 0.38f));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, on ? gold() : dbz(0.30f, 0.30f, 0.38f));
        ImGui::PushStyleColor(ImGuiCol_Text, on ? dbz(0.10f, 0.07f, 0.03f) : dbz(0.85f, 0.85f, 0.85f));
        ImGui::SmallButton(on ? "ON" : "OFF");
        ImGui::PopStyleColor(4);
        ImGui::PopID();
        return changed;
    }

    inline bool comboRow(const char *label, int *value, const char *const *items, int count,
                         int width = 220.0f)
    {
        ImGui::SetNextItemWidth(width);
        const bool changed = ImGui::Combo(label, value, items, count);
        ImGui::SetNextItemWidth(width);
        return changed;
    }

    inline bool sliderRow(const char *label, float *value, float lo, float hi, const char *fmt,
                          float width = 260.0f)
    {
        ImGui::SetNextItemWidth(width);
        return ImGui::SliderFloat(label, value, lo, hi, fmt);
    }

    inline bool intSliderRow(const char *label, int *value, int lo, int hi, const char *fmt,
                             float width = 260.0f)
    {
        ImGui::SetNextItemWidth(width);
        return ImGui::SliderInt(label, value, lo, hi, fmt);
    }

    inline bool comboRowStr(const char *label, int *value, const char *const *items, int count,
                            const char *current, float width = 260.0f)
    {
        ImGui::SetNextItemWidth(width);
        bool changed = false;
        if (ImGui::BeginCombo(label, current))
        {
            for (int i = 0; i < count; ++i)
            {
                const bool sel = (*value == i);
                if (ImGui::Selectable(items[i], sel))
                {
                    *value = i;
                    changed = true;
                }
                if (sel)
                    ImGui::SetItemDefaultFocus();
            }
            ImGui::EndCombo();
        }
        return changed;
    }

    inline void statusRow(const char *label, ImVec4 color, const char *value)
    {
        ImGui::TextUnformatted(label);
        ImGui::SameLine(190.0f);
        ImGui::TextColored(color, "%s", value);
    }

    inline void kv(const char *label, const char *value)
    {
        ImGui::TextUnformatted(label);
        ImGui::SameLine(190.0f);
        ImGui::TextDisabled("%s", value);
    }

    inline bool primaryButton(const char *label, const ImVec2 &size, bool enabled = true)
    {
        ImGui::PushStyleColor(ImGuiCol_Button, dbz(0.18f, 0.55f, 0.30f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, dbz(0.25f, 0.73f, 0.40f));
        ImGui::PushStyleColor(ImGuiCol_Text, dbz(0.02f, 0.06f, 0.03f));
        ImGui::BeginDisabled(!enabled);
        const bool pressed = ImGui::Button(label, size);
        ImGui::EndDisabled();
        ImGui::PopStyleColor(3);
        return pressed;
    }

    inline void formatBytes(unsigned long long bytes, char *out, size_t cap)
    {
        if (bytes >= 1024ull * 1024ull * 1024ull)
            std::snprintf(out, cap, "%.2f GB", bytes / (1024.0 * 1024.0 * 1024.0));
        else if (bytes >= 1024ull * 1024ull)
            std::snprintf(out, cap, "%.1f MB", bytes / (1024.0 * 1024.0));
        else if (bytes >= 1024ull)
            std::snprintf(out, cap, "%.1f KB", bytes / 1024.0);
        else
            std::snprintf(out, cap, "%llu B", bytes);
    }
}
