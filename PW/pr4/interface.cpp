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
    ui->pushButton->setDisabled(true);

    ui->outbutBrowser->setText(QString::fromStdString(this->pol.StringRepresentWithCoeff()) + "\n" +
                               QString::fromStdString(this->pol.StringRepresentWithRoots()));
}


void MainWindow::on_pushButton_clicked()
{
    switch (choice) {
    case 1:
    {
        QString input = ui->textEdit->toPlainText();
        QStringList lines = input.split("\n");
        number eldCoeff(lines[0].toStdString());
        Array rts(lines.size() - 1);
        for (unsigned i = 1; i < lines.size(); i++) {
            rts.setAt(i - 1, number(lines[i].toStdString()));
        }
        this->pol = Polynomial(eldCoeff, rts);
        ui->statusbar->showMessage("Успешная инициализация полинома", 5000);
        break;
    }
    case 2:
    {
        QString idxS = ui->idxEdit->text(), valS = ui->valEdit->text();
        if (idxS.toInt() == -1) {
            pol.setHigherCoeff(number(valS.toStdString()));
        } else {
            pol.setRoot(idxS.toUInt(), number(valS.toStdString()));
        }
        ui->statusbar->showMessage("Успешно", 5000);
        break;
    }
    case 3:
    {
        QString xS = ui->xEdit->text();
        number result = pol.evaluate(number(xS.toStdString()));
        ui->outbutBrowser->setText(QString::fromStdString(result.string()));
        ui->statusbar->showMessage("Успешно", 5000);
        break;
    }
    case 4:
    {
        QString sizeS = ui->sizeEdit->text();
        pol.resizeRoots(sizeS.toUInt());
        ui->statusbar->showMessage("Успешно", 5000);
        break;
    }
    default:
        ui->statusbar->showMessage("Выберите команду", 5000);
        return;
    }
}

