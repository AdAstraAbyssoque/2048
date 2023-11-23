#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CORE2048.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonRestart_clicked();
    void on_pushButtonQuit_clicked();

private:
    Ui::MainWindow *ui;
    GameBoard gameBoard; // Your existing GameBoard class
};

#endif // MAINWINDOW_H
