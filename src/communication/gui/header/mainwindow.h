#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QtWidgets/QMainWindow>
#include <QLabel>

#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class mainwindow;
}
    QT_END_NAMESPACE

    class mainwindow : public QMainWindow
    {
        Q_OBJECT

    public:
        explicit mainwindow(QWidget *parent = nullptr);

    public slots:
        void DisplaySubscription(const QString &log);

    private:
        std::unique_ptr<Ui::mainwindow> ui = nullptr;
        QLabel* label = nullptr;
};
#endif // MAINWINDOW_H
