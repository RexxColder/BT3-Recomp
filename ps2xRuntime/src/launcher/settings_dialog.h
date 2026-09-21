#pragma once

#include <QWidget>
#include <functional>

class QListWidget;
class QStackedWidget;
class BindingsTab;

// [inwindow] Settings is an in-window VIEW (not a popup): the launcher swaps its
// whole content for this widget and back. onBack returns to the launcher page.
// [sidebar] Left list + stacked pages instead of a QTabWidget.
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
    QListWidget *m_side = nullptr;
    QStackedWidget *m_pages = nullptr;
    BindingsTab *m_bindings = nullptr;
};
