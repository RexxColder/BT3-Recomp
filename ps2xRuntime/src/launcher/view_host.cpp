#include "view_host.h"

#include <QWidget>

namespace viewhost
{
    namespace
    {
        std::function<void(QWidget *)> g_show;
        std::function<void()> g_pop;
    }

    void setHandlers(std::function<void(QWidget *)> show, std::function<void()> pop)
    {
        g_show = std::move(show);
        g_pop = std::move(pop);
    }

    void show(QWidget *view)
    {
        if (g_show && view)
            g_show(view);
    }

    void pop()
    {
        if (g_pop)
            g_pop();
    }
}
