#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "core2048.hpp"

#include <QMainWindow>
#include <QPushButton>
#include <QTime>
#include <QPainter>
#include <QKeyEvent>
#include <QMessageBox>
#include <QLabel>
#include <QSettings>
#include <QFileDialog>
#include <QTextStream>
#include <QDir>
#include <QFile>
#include <map>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);
    void paintEvent(QPaintEvent *event);
    
    QPushButton *button;
    GameBoard game; 
    void openFile();
    void saveFile();

public slots:
    void slotStart();    


private:
    Ui::MainWindow *ui;
    int highestScore;
    int currentScore;
    void updateHighestScoreLabel();
    void updateHighestScore(int score); 
    QLabel* highestScoreLabel;
    void updateScoreLabel();
    QLabel* currentScoreLabel;
    bool gameStarted;
};
#endif // MAINWINDOW_H