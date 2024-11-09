#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>

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
signals:
    void question(QByteArray);
public slots:
    void answer(QString);
};
#endif // INTERFACE_H
