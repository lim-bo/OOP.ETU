#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>
#include "polynom.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_initRadio_clicked();
    void on_editRadio_clicked();
    void on_evalRadio_clicked();
    void on_resizeRadio_clicked();
    void on_outputRadio_clicked();
    void on_pushButton_clicked();
private:
    Ui::MainWindow *ui;
    unsigned choice;
    Polynomial pol;
};
#endif // INTERFACE_H
