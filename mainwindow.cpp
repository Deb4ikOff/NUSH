#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "assets/libs/algorithm/nush.cpp"

#include <QFileDialog>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Encode_clicked()
{
    Processor NUSH;
    std::string msg = ui->textEdit_Input->toPlainText().toStdString();
    std::string key = ui->lineEdit_Key->text().toStdString();
    std::string result = "";

    while (msg.length() % 8 != 0) msg += ' ';
    while (key.length() % 16 != 0) key += '#';

    std::string tmp = "";
    for (size_t i = 0; i < msg.length(); i++) {
        if (i % 8 != 0 || i == 0) tmp += msg[i];
        else {
            result += NUSH.encode(tmp, key);
            tmp = std::string(1, msg[i]);
        }
    }
    result += NUSH.encode(tmp, key);

    ui->textEdit_Output->setText(QString::fromStdString(result));
    ui->textEdit_DEBUG->setText(QString::fromStdString(NUSH.logs.str()));
}


void MainWindow::on_pushButton_Reveal_toggled(bool checked)
{
    if (checked) {
        ui->pushButton_Reveal->setIcon(QIcon(":/icons/assets/icons/open.png"));
        ui->lineEdit_Key->setEchoMode(QLineEdit::Normal);
    }
    else {
        ui->pushButton_Reveal->setIcon(QIcon(":/icons/assets/icons/close.png"));
        ui->lineEdit_Key->setEchoMode(QLineEdit::Password);
    }
}


void MainWindow::on_pushButton_Decode_clicked()
{
    Processor NUSH;
    std::string msg = ui->textEdit_Input->toPlainText().toStdString();
    if (msg[msg.length() - 1] == '\n') msg.pop_back();
    std::string key = ui->lineEdit_Key->text().toStdString();

    std::string result = "";

    while (key.length() % 16 != 0) key += '#';

    std::string tmp = "";
    for (size_t i = 0; i < msg.length(); i++) {
        if (i % 16 != 0 || i == 0) tmp += msg[i];
        else {
            result += NUSH.decode(tmp, key);
            tmp = std::string(1, msg[i]);
        }
    }
    result += NUSH.decode(tmp, key);


    ui->textEdit_Output->setText(QString::fromStdString(result));
    ui->textEdit_DEBUG->setText(QString::fromStdString(NUSH.logs.str()));
}


void MainWindow::on_radioButton_inputFromKeyboard_toggled(bool checked)
{
    if (checked) {
        ui->pushButton_openFile->setEnabled(false);
        ui->textEdit_Input->setEnabled(true);
    }
}


void MainWindow::on_radioButton_inputFromFile_toggled(bool checked)
{
    if (checked) {
        ui->pushButton_openFile->setEnabled(true);
        ui->textEdit_Input->setEnabled(false);
    }
}


void MainWindow::on_pushButton_openFile_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open file"), nullptr, "Text Files(*.txt)");
    ui->textEdit_DEBUG->setText(path);
    ui->lineEdit->setText(path);
    std::ifstream fin(path.toStdString());

    std::string text = "";
    std::string line = "";

    while (std::getline(fin, line)) text += line + '\n';

    ui->textEdit_Input->setText(QString::fromStdString(text));
    fin.close();
}


void MainWindow::on_pushButton_Save_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save file"), nullptr, "Text Files(*.txt)");
    std::ofstream fout(filename.toStdString());
    fout << ui->textEdit_Output->toPlainText().toStdString();
    fout.close();
}

void MainWindow::on_pushButton_Clear_clicked()
{
    ui->textEdit_Input->setText("");
    ui->textEdit_Output->setText("");
    ui->textEdit_DEBUG->setText("");
    ui->lineEdit->setText("");
}


void MainWindow::on_actionExit_triggered()
{
    exit(0);
}

