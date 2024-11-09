/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *optionsBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *initRadio;
    QRadioButton *editRadio;
    QRadioButton *evalRadio;
    QRadioButton *resizeRadio;
    QRadioButton *outputRadio;
    QTextBrowser *outbutBrowser;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QLineEdit *xEdit;
    QLineEdit *idxEdit;
    QLineEdit *valEdit;
    QLineEdit *sizeEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1008, 618);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        optionsBox = new QGroupBox(centralwidget);
        optionsBox->setObjectName("optionsBox");
        optionsBox->setGeometry(QRect(10, 10, 431, 381));
        verticalLayout = new QVBoxLayout(optionsBox);
        verticalLayout->setObjectName("verticalLayout");
        initRadio = new QRadioButton(optionsBox);
        initRadio->setObjectName("initRadio");

        verticalLayout->addWidget(initRadio);

        editRadio = new QRadioButton(optionsBox);
        editRadio->setObjectName("editRadio");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(editRadio->sizePolicy().hasHeightForWidth());
        editRadio->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(editRadio);

        evalRadio = new QRadioButton(optionsBox);
        evalRadio->setObjectName("evalRadio");

        verticalLayout->addWidget(evalRadio);

        resizeRadio = new QRadioButton(optionsBox);
        resizeRadio->setObjectName("resizeRadio");

        verticalLayout->addWidget(resizeRadio);

        outputRadio = new QRadioButton(optionsBox);
        outputRadio->setObjectName("outputRadio");

        verticalLayout->addWidget(outputRadio);

        outbutBrowser = new QTextBrowser(centralwidget);
        outbutBrowser->setObjectName("outbutBrowser");
        outbutBrowser->setGeometry(QRect(10, 390, 961, 141));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(840, 320, 121, 41));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(630, 130, 361, 151));
        xEdit = new QLineEdit(centralwidget);
        xEdit->setObjectName("xEdit");
        xEdit->setGeometry(QRect(460, 200, 71, 28));
        idxEdit = new QLineEdit(centralwidget);
        idxEdit->setObjectName("idxEdit");
        idxEdit->setEnabled(true);
        idxEdit->setGeometry(QRect(450, 140, 61, 28));
        valEdit = new QLineEdit(centralwidget);
        valEdit->setObjectName("valEdit");
        valEdit->setGeometry(QRect(530, 140, 81, 28));
        sizeEdit = new QLineEdit(centralwidget);
        sizeEdit->setObjectName("sizeEdit");
        sizeEdit->setGeometry(QRect(460, 270, 61, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1008, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        optionsBox->setTitle(QCoreApplication::translate("MainWindow", "\320\236\320\277\321\206\320\270\320\270", nullptr));
        initRadio->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\320\270\321\206\320\270\320\260\320\273\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        editRadio->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 a n-\320\263\320\276 \320\270\320\273\320\270 \320\272\320\276\321\200\320\275\321\217 \n"
"(\320\264\320\273\321\217 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \321\201\321\202\320\260\321\200\321\210\320\265\320\263\320\276 \320\272\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202\320\260: \320\270\320\275\320\264\320\265\320\272\321\201 = -1)", nullptr));
        evalRadio->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\207\320\270\321\201\320\273\320\265\320\275\320\270\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217 \320\277\320\276\320\273\320\270\320\275\320\276\320\274\320\260 \321\201 \320\267\320\260\320\264\320\260\320\275\320\275\321\213\320\274 x", nullptr));
        resizeRadio->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \321\200\320\260\320\267\320\274\320\265\321\200\320\275\320\276\321\201\321\202\320\270 \320\274\320\260\321\201\321\201\320\270\320\262\320\260 \320\272\320\276\321\200\320\275\320\265\320\271 \320\277\320\276\320\273\320\270\320\275\320\276\320\274\320\260", nullptr));
        outputRadio->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\262\320\276\320\264 \320\277\320\276\320\273\320\270\320\275\320\276\320\274\320\260", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214", nullptr));
        textEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\236\320\272\320\275\320\276 \320\270\320\275\320\270\321\206\320\270\320\260\320\273\320\270\320\267\320\260\321\206\320\270\320\270 \320\277\320\276\320\273\320\270\320\275\320\276\320\274\320\260", nullptr));
        xEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "x = ...", nullptr));
        idxEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\270\320\275\320\264\320\265\320\272\321\201", nullptr));
        valEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265", nullptr));
        sizeEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\321\200\320\260\320\267\320\274\320\265\321\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
