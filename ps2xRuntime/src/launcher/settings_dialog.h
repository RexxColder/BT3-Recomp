#pragma once

#include <QDialog>

class QGraphicsOpacityEffect;
class QPropertyAnimation;
class QTabWidget;
class BindingsTab;

class SettingsDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SettingsDialog(QWidget *parent = nullptr);

protected:
    void showEvent(QShowEvent *) override;
    void closeEvent(QCloseEvent *) override;

private slots:
    void onSave();
    void onClose();

private:
    QTabWidget *m_tabs = nullptr;
    BindingsTab *m_bindings = nullptr;
    QGraphicsOpacityEffect *m_fx = nullptr;
    QPropertyAnimation *m_anim = nullptr;
    bool m_animClosing = false;
};