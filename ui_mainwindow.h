/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDocumentation;
    QAction *actionSupport;
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionExit;
    QWidget *centralwidget;
    QGroupBox *groupBox_4;
    QGroupBox *groupBox;
    QLabel *label_6;
    QLineEdit *lineEdit_Key;
    QPushButton *pushButton_Encode;
    QPushButton *pushButton_Decode;
    QPushButton *pushButton_Reveal;
    QGroupBox *groupBox_7;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QPushButton *pushButton_openFile;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_inputFromKeyboard;
    QRadioButton *radioButton_inputFromFile;
    QPushButton *pushButton_Clear;
    QGroupBox *groupBox_6;
    QTextEdit *textEdit_DEBUG;
    QGroupBox *groupBox_2;
    QTextEdit *textEdit_Input;
    QGroupBox *groupBox_3;
    QTextEdit *textEdit_Output;
    QPushButton *pushButton_Save;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 548);
        MainWindow->setMinimumSize(QSize(800, 548));
        MainWindow->setMaximumSize(QSize(800, 548));
        QFont font;
        font.setFamily(QString::fromUtf8("Lucida Console"));
        font.setPointSize(9);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/assets/icons/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("background: #c5c5c5;\n"
"color: #000;\n"
"font-family: \"Lucida Console\";\n"
"font-size: 8;"));
        actionDocumentation = new QAction(MainWindow);
        actionDocumentation->setObjectName(QString::fromUtf8("actionDocumentation"));
        actionSupport = new QAction(MainWindow);
        actionSupport->setObjectName(QString::fromUtf8("actionSupport"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 0, 341, 521));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Lucida Console"));
        groupBox_4->setFont(font1);
        groupBox_4->setStyleSheet(QString::fromUtf8("background: none;"));
        groupBox_4->setAlignment(Qt::AlignCenter);
        groupBox = new QGroupBox(groupBox_4);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 321, 201));
        groupBox->setFont(font1);
        groupBox->setStyleSheet(QString::fromUtf8(""));
        groupBox->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 110, 71, 21));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_Key = new QLineEdit(groupBox);
        lineEdit_Key->setObjectName(QString::fromUtf8("lineEdit_Key"));
        lineEdit_Key->setGeometry(QRect(90, 110, 221, 21));
        lineEdit_Key->setStyleSheet(QString::fromUtf8("color: #000;"));
        lineEdit_Key->setEchoMode(QLineEdit::Password);
        pushButton_Encode = new QPushButton(groupBox);
        pushButton_Encode->setObjectName(QString::fromUtf8("pushButton_Encode"));
        pushButton_Encode->setGeometry(QRect(10, 140, 231, 21));
        pushButton_Encode->setStyleSheet(QString::fromUtf8("background: #eee;"));
        pushButton_Decode = new QPushButton(groupBox);
        pushButton_Decode->setObjectName(QString::fromUtf8("pushButton_Decode"));
        pushButton_Decode->setGeometry(QRect(10, 170, 231, 21));
        pushButton_Decode->setStyleSheet(QString::fromUtf8("background: #eee;"));
        pushButton_Reveal = new QPushButton(groupBox);
        pushButton_Reveal->setObjectName(QString::fromUtf8("pushButton_Reveal"));
        pushButton_Reveal->setGeometry(QRect(290, 110, 21, 21));
        pushButton_Reveal->setStyleSheet(QString::fromUtf8("background: none;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/assets/icons/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Reveal->setIcon(icon1);
        pushButton_Reveal->setCheckable(true);
        pushButton_Reveal->setFlat(true);
        groupBox_7 = new QGroupBox(groupBox);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 20, 301, 81));
        groupBox_7->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(groupBox_7);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 50, 81, 21));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit = new QLineEdit(groupBox_7);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(100, 50, 141, 21));
        lineEdit->setReadOnly(true);
        pushButton_openFile = new QPushButton(groupBox_7);
        pushButton_openFile->setObjectName(QString::fromUtf8("pushButton_openFile"));
        pushButton_openFile->setEnabled(false);
        pushButton_openFile->setGeometry(QRect(250, 50, 41, 21));
        pushButton_openFile->setStyleSheet(QString::fromUtf8("background: #eee;"));
        layoutWidget = new QWidget(groupBox_7);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 281, 21));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_inputFromKeyboard = new QRadioButton(layoutWidget);
        radioButton_inputFromKeyboard->setObjectName(QString::fromUtf8("radioButton_inputFromKeyboard"));
        radioButton_inputFromKeyboard->setChecked(true);

        horizontalLayout->addWidget(radioButton_inputFromKeyboard);

        radioButton_inputFromFile = new QRadioButton(layoutWidget);
        radioButton_inputFromFile->setObjectName(QString::fromUtf8("radioButton_inputFromFile"));

        horizontalLayout->addWidget(radioButton_inputFromFile);

        pushButton_Clear = new QPushButton(groupBox);
        pushButton_Clear->setObjectName(QString::fromUtf8("pushButton_Clear"));
        pushButton_Clear->setGeometry(QRect(250, 140, 61, 51));
        pushButton_Clear->setStyleSheet(QString::fromUtf8("background: #eee;"));
        groupBox_6 = new QGroupBox(groupBox_4);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 230, 321, 281));
        groupBox_6->setAlignment(Qt::AlignCenter);
        textEdit_DEBUG = new QTextEdit(groupBox_6);
        textEdit_DEBUG->setObjectName(QString::fromUtf8("textEdit_DEBUG"));
        textEdit_DEBUG->setGeometry(QRect(10, 20, 301, 251));
        textEdit_DEBUG->setStyleSheet(QString::fromUtf8("background: #fff;"));
        textEdit_DEBUG->setLineWrapMode(QTextEdit::NoWrap);
        textEdit_DEBUG->setReadOnly(true);
        textEdit_DEBUG->setTabStopDistance(60.000000000000000);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(360, 0, 431, 241));
        groupBox_2->setStyleSheet(QString::fromUtf8("background: none;"));
        groupBox_2->setAlignment(Qt::AlignCenter);
        textEdit_Input = new QTextEdit(groupBox_2);
        textEdit_Input->setObjectName(QString::fromUtf8("textEdit_Input"));
        textEdit_Input->setGeometry(QRect(10, 20, 411, 211));
        textEdit_Input->setStyleSheet(QString::fromUtf8("background: #fff;"));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(360, 250, 431, 241));
        groupBox_3->setStyleSheet(QString::fromUtf8("background: none;"));
        groupBox_3->setAlignment(Qt::AlignCenter);
        textEdit_Output = new QTextEdit(groupBox_3);
        textEdit_Output->setObjectName(QString::fromUtf8("textEdit_Output"));
        textEdit_Output->setGeometry(QRect(10, 20, 411, 211));
        textEdit_Output->setStyleSheet(QString::fromUtf8("background: #fff;"));
        pushButton_Save = new QPushButton(centralwidget);
        pushButton_Save->setObjectName(QString::fromUtf8("pushButton_Save"));
        pushButton_Save->setGeometry(QRect(360, 500, 431, 21));
        pushButton_Save->setStyleSheet(QString::fromUtf8("background: #eee;"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 18));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuFile->setStyleSheet(QString::fromUtf8(""));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionDocumentation);
        menuHelp->addAction(actionSupport);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\250\320\270\321\204\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274\320\276\320\274 NUSH", nullptr));
        actionDocumentation->setText(QCoreApplication::translate("MainWindow", "Documentation", nullptr));
        actionSupport->setText(QCoreApplication::translate("MainWindow", "Support", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionSave_as->setText(QCoreApplication::translate("MainWindow", "Save as", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Control panel", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Enter Key:", nullptr));
        pushButton_Encode->setText(QCoreApplication::translate("MainWindow", "Encode", nullptr));
        pushButton_Decode->setText(QCoreApplication::translate("MainWindow", "Decode", nullptr));
        pushButton_Reveal->setText(QString());
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "Input from...", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Input File:", nullptr));
        pushButton_openFile->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        radioButton_inputFromKeyboard->setText(QCoreApplication::translate("MainWindow", "Keyboard", nullptr));
        radioButton_inputFromFile->setText(QCoreApplication::translate("MainWindow", "File", nullptr));
        pushButton_Clear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "DEBUG", nullptr));
        textEdit_DEBUG->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Lucida Console'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Input", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Output", nullptr));
        textEdit_Output->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Lucida Console'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        pushButton_Save->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
