#pragma once

#include <QWidget>
#include <functional>

class QTabWidget;
class BindingsTab;

// [inwindow] Settings is an in-window VIEW (not a popup): the launcher swaps its
// whole content for this widget and back. onBack returns to the launcher page.
class SettingsView : public QWidget
{
    Q_OBJECT
public:
    explicit SettingsView(QWidget *parent = nullptr);

    std::function<void()> onBack;

private slots:
    void onSave();
    void onClose();

private:
    QTabWidget *m_tabs = nullptr;
    BindingsTab *m_bindings = nullptr;
};
