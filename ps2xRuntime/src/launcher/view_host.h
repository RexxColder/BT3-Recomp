#pragma once

#include <functional>

class QWidget;

// [inwindow] A tiny host so a nested view (e.g. a Video-tab settings view opened from
// inside the Settings view) can ask the launcher to push/pop a page without knowing
// about LauncherWindow. LauncherWindow installs the handlers at construction.
namespace viewhost
{
    void setHandlers(std::function<void(QWidget *)> show, std::function<void()> pop);
    void show(QWidget *view);   // push + show a view
    void pop();                 // return to the previous view/page
}
