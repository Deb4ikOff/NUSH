#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pushButton_Encode_clicked();

    void on_pushButton_Reveal_toggled(bool checked);

    void on_pushButton_Decode_clicked();

    void on_radioButton_inputFromKeyboard_toggled(bool checked);

    void on_radioButton_inputFromFile_toggled(bool checked);

    void on_pushButton_openFile_clicked();

    void on_pushButton_Save_clicked();

    void on_pushButton_Clear_clicked();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
