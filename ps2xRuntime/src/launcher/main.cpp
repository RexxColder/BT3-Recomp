#include "dbz_theme.h"
#include "launcher_window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName(QStringLiteral("bt3-launcher"));

    QApplication::setStyle(QStringLiteral("Fusion"));
    app.setStyleSheet(dbz::stylesheet());

    const QString font = dbz::loadHudFont();
    if (!font.isEmpty())
    {
        QFont f(font, 11);
        app.setFont(f);
    }

    LauncherWindow win;
    win.show();
    return app.exec();
}