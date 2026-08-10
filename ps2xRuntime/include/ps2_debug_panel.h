#ifndef PS2_DEBUG_PANEL_H
#define PS2_DEBUG_PANEL_H

#include <cstdint>

class PS2Runtime;

class PS2DebugPanel
{
public:
    void initialize();
    void shutdown();
    void draw(PS2Runtime &runtime);

    bool isVisible() const { return m_visible; }
    void setVisible(bool visible) { m_visible = visible; }
    void toggleVisible() { m_visible = !m_visible; }

private:
    bool m_initialized = false;
    bool m_visible = true;
    bool m_showRegisters = true;
    unsigned int m_memoryAddress = 0x00100000u;
    unsigned int m_memoryBytes = 0x100u;

    // Pad configurator state (consumed by drawControllersTab).
    int m_padEditPlayer = 0;
    int m_padCaptureAction = -1; // index into PadAction while capturing a bind; -1 = idle
};

#endif // PS2_DEBUG_PANEL_H
