#include "interface.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    choice = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_initRadio_clicked()
{
    this->choice = 1;
    ui->idxEdit->setDisabled(true);
    ui->xEdit->setDisabled(true);
    ui->sizeEdit->setDisabled(true);
    ui->valEdit->setDisabled(true);
    ui->textEdit->setEnabled(true);
    ui->pushButton->setEnabled(true);
}


void MainWindow::on_editRadio_clicked()
{
    this->choice = 2;
    ui->idxEdit->setEnabled(true);
    ui->xEdit->setDisabled(true);
    ui->valEdit->setEnabled(true);
    ui->textEdit->setDisabled(true);
    ui->sizeEdit->setDisabled(true);
    ui->pushButton->setEnabled(true);
}


void MainWindow::on_evalRadio_clicked()
{
    this->choice = 3;
    ui->idxEdit->setDisabled(true);
    ui->xEdit->setEnabled(true);
    ui->valEdit->setDisabled(true);
    ui->textEdit->setDisabled(true);
    ui->sizeEdit->setDisabled(true);
    ui->pushButton->setEnabled(true);
}


void MainWindow::on_resizeRadio_clicked()
{
    this->choice = 4;
    ui->idxEdit->setDisabled(true);
    ui->xEdit->setDisabled(true);
    ui->valEdit->setDisabled(true);
    ui->textEdit->setDisabled(true);
    ui->sizeEdit->setEnabled(true);
    ui->pushButton->setEnabled(true);
}


void MainWindow::on_outputRadio_clicked()
{
    this->choice = 5;
    ui->idxEdit->setDisabled(true);
    ui->xEdit->setDisabled(true);
    ui->valEdit->setDisabled(true);
    ui->textEdit->setDisabled(true);
    ui->sizeEdit->setDisabled(true);
    ui->pushButton->setDisabled(false);
}


void MainWindow::on_pushButton_clicked()
{
    QJsonDocument msg;
    QJsonObject request;
    request["option"] = QJsonValue(int(choice));
    switch (choice) {
    case 1:
    {
        request["values"] = QJsonArray::fromStringList(ui->textEdit->toPlainText().split("\n"));
        msg.setObject(request);
        emit question(msg.toJson());
        break;
    }
    case 2:
    {
        QJsonArray vals = {ui->idxEdit->text().toInt(), ui->valEdit->text()};
        request["values"] = vals;
        msg.setObject(request);
        emit question(msg.toJson());
        break;
    }
    case 3:
    {
        request["x"] = QJsonValue(ui->xEdit->text());
        msg.setObject(request);
        emit question(msg.toJson());
        break;
    }
    case 4:
    {
        request["size"] = QJsonValue(ui->sizeEdit->text().toInt());
        msg.setObject(request);
        emit question(msg.toJson());
        break;
    }
    case 5:
    {
        msg.setObject(request);
        emit question(msg.toJson());
        break;
    }
    default:
        ui->statusbar->showMessage("Выберите команду", 5000);
    }
}

void MainWindow::answer(QString recieved) {
    QStringList data = {recieved.mid(0, recieved.indexOf(" ")), recieved.mid(recieved.indexOf(" ") + 1)};
    switch (data[0].toInt()) {
    case 3:
    case 5:
        ui->outbutBrowser->setText(data[1]);
        break;
    case 1:
    case 2:
    case 4:
        ui->statusbar->showMessage("Успешно", 5000);
        break;
    default:
        ui->statusbar->showMessage("Ошибка", 5000);
    }
}

