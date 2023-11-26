#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "core2048.hpp"


std::random_device rd;
std::mt19937 rng;

GameBoard::GameBoard() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = 0;
        }
    }
    score = 0;
    highestScore = 0;
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , highestScore(0)
    , currentScore(0)
    , gameStarted(false)
{
    ui->setupUi(this);
    game.initializeBoard();

    button = new QPushButton("Start", this);
    button->setGeometry(60,400,200,50);

    srand(uint(QTime(0,0,0).secsTo(QTime::currentTime())));
    connect(button, SIGNAL(clicked()), this, SLOT(slotStart()));

    highestScoreLabel = new QLabel("Highest Score: 0", this);
    statusBar()->addWidget(highestScoreLabel);
    currentScoreLabel = new QLabel("Current Score: 0", this);
    statusBar()->addWidget(currentScoreLabel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateScoreLabel() {
    int currentScore = game.getScore();
    currentScoreLabel->setText("Current Score: " + QString::number(currentScore));
}

void MainWindow::updateHighestScoreLabel() {
    int currentHighestScore = game.getHighestScore();
    highestScoreLabel->setText("Highest Score: " + QString::number(currentHighestScore));
}

void GameBoard::updateHighestScore(int newScore) {
    if (newScore > highestScore) {
        highestScore = newScore;
    }
}

int GameBoard::getHighestScore() const {
    return highestScore;
}

void MainWindow::paintEvent(QPaintEvent *event){
    (void)event;
    QPainter p(this);
    p.setPen(Qt::black);
    p.setFont(QFont("Arial", 20));

    QString strscore;
    p.drawText(60, 350, "Score: " + strscore.setNum(game.getScore()));

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            p.setPen(Qt::transparent);
            if (game.board[j][i] == 0){
                p.setBrush(Qt::lightGray);
                p.drawRect(i*60+40,j*60+120,55,55);
            }
            else if (game.board[j][i] == 2){
                p.setBrush(Qt::yellow);
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("Arial", 20));
                p.drawText(QRect(i*60+40,j*60+120,55,55), QString::number(2), QTextOption(Qt::AlignCenter));
            }
            else if (game.board[j][i] == 4){
                p.setBrush(Qt::darkYellow);
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("Arial", 20));
                p.drawText(QRect(i*60+40,j*60+120,55,55), QString::number(4), QTextOption(Qt::AlignCenter));
            }
            else if (game.board[j][i] == 8){
                p.setBrush(Qt::green);
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("Arial", 20));
                p.drawText(QRect(i*60+40,j*60+120,55,55), QString::number(8), QTextOption(Qt::AlignCenter));
            }
            else if (game.board[j][i] == 16){
                p.setBrush(Qt::darkGreen);
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("Arial", 20));
                p.drawText(QRect(i*60+40,j*60+120,55,55), QString::number(16), QTextOption(Qt::AlignCenter));
            }
            else if (game.board[j][i] == 32){
                p.setBrush(Qt::cyan);
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("Arial", 20));
                p.drawText(QRect(i*60+40,j*60+120,55,55), QString::number(32), QTextOption(Qt::AlignCenter));
            }
            else if (game.board[j][i] == 64){
                p.setBrush(Qt::darkCyan);
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("Arial", 20));
                p.drawText(QRect(i*60+40,j*60+120,55,55), QString::number(64), QTextOption(Qt::AlignCenter));
            }
            else if (game.board[j][i] == 128){
                p.setBrush(Qt::magenta);
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("Arial", 20));
                p.drawText(QRect(i*60+40,j*60+120,55,55), QString::number(128), QTextOption(Qt::AlignCenter));
            }
            else if (game.board[j][i] == 256){
                p.setBrush(Qt::darkMagenta);
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::white);
                p.setFont(QFont("Arial", 20));
                p.drawText(QRect(i*60+40,j*60+120,55,55), QString::number(256), QTextOption(Qt::AlignCenter));
            }
            else if (game.board[j][i] == 512){
                p.setBrush(Qt::red);
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::white);
                p.setFont(QFont("Arial", 20));
                p.drawText(QRect(i*60+40,j*60+120,55,55), QString::number(512), QTextOption(Qt::AlignCenter));
            }
            else if (game.board[j][i] == 1024){
                p.setBrush(Qt::darkRed);
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::white);
                p.setFont(QFont("Arial", 20));
                p.drawText(QRect(i*60+40,j*60+120,55,55), QString::number(1024), QTextOption(Qt::AlignCenter));
            }
            else if (game.board[j][i] == 2048){
                p.setBrush(Qt::blue);
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::white);
                p.setFont(QFont("Arial", 20));
                p.drawText(QRect(i*60+40,j*60+120,55,55), QString::number(2048), QTextOption(Qt::AlignCenter));
            }
            else if (game.board[j][i] == 4096){
                p.setBrush(Qt::darkBlue);
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::white);
                p.setFont(QFont("Arial", 20));
                p.drawText(QRect(i*60+40,j*60+120,55,55), QString::number(4096), QTextOption(Qt::AlignCenter));
            }
            else if (game.board[j][i] == 8192){
                p.setBrush(Qt::gray);
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::white);
                p.setFont(QFont("Arial", 20));
                p.drawText(QRect(i*60+40,j*60+120,55,55), QString::number(8192), QTextOption(Qt::AlignCenter));
            }
            else if (game.board[j][i] == 16384){
                p.setBrush(Qt::darkGray);
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::white);
                p.setFont(QFont("Arial", 20));
                p.drawText(QRect(i*60+40,j*60+120,55,55), QString::number(16384), QTextOption(Qt::AlignCenter));
            }
            else if (game.board[j][i] == 32768){
                p.setBrush(Qt::lightGray);
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::white);
                p.setFont(QFont("Arial", 20));
                p.drawText(QRect(i*60+40,j*60+120,55,55), "32768", QTextOption(Qt::AlignCenter));
            }
            else if (game.board[j][i] == 65536){
                p.setBrush(Qt::white);
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("Arial", 20));
                p.drawText(QRect(i*60+40,j*60+120,55,55), "65536", QTextOption(Qt::AlignCenter));
            }
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if (!gameStarted) {
        return;
    }
    if (game.isGameOver()){
        int score = game.getScore();

        QMessageBox msgBox;
        msgBox.setText("Game Over");
        msgBox.setInformativeText("Your Score: " + QString::number(score));
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);

        int ret = msgBox.exec();

        if (ret == QMessageBox::Ok) {
            slotStart();
        }
    }
    bool isMoved = false;
    switch (event->key()){
        case Qt::Key_W:
            //std::cout<< "Key W pressed."<<std::endl;
            isMoved = game.moveUp();
            game.operatemoveUp(isMoved);
            break;
        case Qt::Key_S:
            //std::cout<< "Key S pressed."<<std::endl;
            isMoved = game.moveDown();
            game.operatemoveDown(isMoved);
            break;
        case Qt::Key_A:
            //std::cout<< "Key A pressed."<<std::endl;
            isMoved = game.moveLeft();
            game.operatemoveLeft(isMoved);
            break;
        case Qt::Key_D:
            //std::cout<< "Key D pressed."<<std::endl;
            isMoved = game.moveRight();
            game.operatemoveRight(isMoved);
            break;
        default:
            return;
    }
    updateScoreLabel();  
    updateHighestScoreLabel();
    update();
}

void MainWindow::slotStart(){
    QMessageBox::information(this, "Start", "Game Start!");
    game.initializeBoard();
    button->setText("Restart");
    updateHighestScoreLabel();
    update(); 
    gameStarted = true;
}

void MainWindow::myRand(){
    if (game.isBoardFull()){
        QMessageBox::information(this, "Game Over", "The score is: " + QString::number(game.getScore()));
        return;
    }
}

// Game logic functions
void GameBoard::initializeBoard() {
    for (int i = 0; i < 4; i++) {
        // Initialize each row with 0s
        for (int j = 0; j < 4; j++) {
            board[i][j] = 0;
        }
    }
    score = 0;
    // Initialize the board with two random tiles
    addNewTile();
    addNewTile();
}

bool GameBoard::canMerge(int current, int next) {
    return (next == 0 || current == next);
}

bool GameBoard::moveUp() {
    bool moved = false;
    for (int col = 0; col < 4; ++col) {
        for (int row = 1; row < 4; ++row) {
            if (board[row][col] != 0) {
                int currentRow = row;
                while (currentRow > 0 && canMerge(board[currentRow][col], board[currentRow - 1][col])) {
                    std::swap(board[currentRow][col], board[currentRow - 1][col]);
                    moved = true;
                    --currentRow;
                }
            }
        }
    }
    return moved;
}

bool GameBoard::moveDown() {
    bool moved = false;

    for (int col = 0; col < 4; ++col) {
        for (int row = 2; row >= 0; --row) {
            if (board[row][col] != 0) {
                int currentRow = row;
                while (currentRow < 3 && canMerge(board[currentRow][col], board[currentRow + 1][col])) {
                    std::swap(board[currentRow][col], board[currentRow + 1][col]);
                    moved = true;
                    ++currentRow;
                }
            }
        }
    }

    return moved;
}

bool GameBoard::moveLeft() {
    bool moved = false;

    for (int row = 0; row < 4; ++row) {
        for (int col = 1; col < 4; ++col) {
            if (board[row][col] != 0) {
                int currentCol = col;
                while (currentCol > 0 && canMerge(board[row][currentCol], board[row][currentCol - 1])) {
                    std::swap(board[row][currentCol], board[row][currentCol - 1]);
                    moved = true;
                    --currentCol;
                }
            }
        }
    }

    return moved;
}

bool GameBoard::moveRight() {
    bool moved = false;

    for (int row = 0; row < 4; ++row) {
        for (int col = 2; col >= 0; --col) {
            if (board[row][col] != 0) {
                int currentCol = col;
                while (currentCol < 3 && canMerge(board[row][currentCol], board[row][currentCol + 1])) {
                    std::swap(board[row][currentCol], board[row][currentCol + 1]);
                    moved = true;
                    ++currentCol;
                }
            }
        }
    }

    return moved;
}

bool GameBoard::isGameOver() {
    // Check if the game is over
    bool isOver = true;
    if (!isBoardFull()) {
        isOver = false;
    } else {
        // Check if there are any possible moves
        for (int i = 0; i < 4; i++) {
            // Check if there are any possible moves in each row
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == board[i][j + 1]) {
                    isOver = false;
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            // Check if there are any possible moves in each column
            for (int j = 0; j < 3; j++) {
                if (board[j][i] == board[j + 1][i]) {
                    isOver = false;
                }
            }
        }
    }
    return isOver;
}

int GameBoard::getScore() {
    // Return the score
    return score;
}

void GameBoard::operatemoveUp(bool isMoved) {
    if (isMoved) {
        for (int col = 0; col < 4; ++col) {
            for (int row = 1; row < 4; ++row) {
                if (board[row][col] != 0) {
                    int currentRow = row;
                    while (currentRow > 0 && (board[currentRow - 1][col] == 0 || board[currentRow - 1][col] == board[row][col])) {
                        if (board[currentRow - 1][col] == 0) {
                            std::swap(board[currentRow][col], board[currentRow - 1][col]);
                        } else {
                            mergeCells(currentRow, col, currentRow - 1, col);
                        }
                        --currentRow;
                    }
                }
            }
        }
        addNewTile();
    }
}

void GameBoard::operatemoveDown(bool isMoved) {
    if (isMoved){
        for (int col = 0; col < 4; ++col){
            for (int row = 2; row >= 0; --row) {
                if (board[row][col] != 0) {
                    int currentRow = row;
                    while (currentRow < 3 && (board[currentRow + 1][col] == 0 || board[currentRow + 1][col] == board[row][col])) {
                        if (board[currentRow + 1][col] == 0) {
                            std::swap(board[currentRow][col], board[currentRow + 1][col]);
                        } else {
                            mergeCells(currentRow, col, currentRow + 1, col);
                        }
                        ++currentRow;
                    }
                }
            }
        }
        addNewTile();
    }
}

void GameBoard::operatemoveLeft(bool isMoved) {
    if (isMoved){
        for (int row = 0; row < 4; ++row) {
            for (int col = 1; col < 4; ++col) {
                if (board[row][col] != 0) {
                    int currentCol = col;
                    while (currentCol > 0 && (board[row][currentCol - 1] == 0 || board[row][currentCol - 1] == board[row][col])) {
                        if (board[row][currentCol - 1] == 0) {
                            std::swap(board[row][currentCol], board[row][currentCol - 1]);
                        } else {
                            mergeCells(row, currentCol, row, currentCol - 1);
                        }
                        --currentCol;
                    }
                }
            }
        }
        addNewTile();
    }
}

void GameBoard::operatemoveRight(bool isMoved) {
    if (isMoved) {
        for (int row = 0; row < 4; ++row) {
            for (int col = 2; col >= 0; --col) {
                if (board[row][col] != 0) {
                    int currentCol = col;
                    while (currentCol < 3 && (board[row][currentCol + 1] == 0 || board[row][currentCol + 1] == board[row][col])) {
                        if (board[row][currentCol + 1] == 0) {
                            std::swap(board[row][currentCol], board[row][currentCol + 1]);
                        } else {
                            mergeCells(row, currentCol, row, currentCol + 1);
                        }
                        ++currentCol;
                    }
                }
            }
        }
        addNewTile();
    }
}


// Helper functions
void GameBoard::addNewTile() {
        // Add a new tile (2 or 4) to the board
        int tileValue;

        // 90% chance of getting a 2, 10% chance of getting a 4
        std::uniform_int_distribution<int> distribution(0, 9);
        int randValue = distribution(rng);

        if (randValue < 9) {
            tileValue = 2;
        } else {
            tileValue = 4;
        }

        // Find a random empty tile and add the new tile
        std::uniform_int_distribution<int> rowDistribution(0, 3);
        std::uniform_int_distribution<int> colDistribution(0, 3);
        int randRow, randCol;

        do {
            randRow = rowDistribution(rng);
            randCol = colDistribution(rng);
        } while (board[randRow][randCol] != 0);

        // Add the new tile to the board
        board[randRow][randCol] = tileValue;
    }

bool GameBoard::isBoardFull() {
    // Check if the board is full
    bool isFull = true;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j ++) {
            if (board[i][j] == 0) {
                isFull = false;
            }
        }
    }
    return isFull;
}


void GameBoard::mergeCells(int currentRow, int currentCol, int nextRow, int nextCol) {
    board[nextRow][nextCol] *= 2;  
    board[currentRow][currentCol] = 0;
    score += board[nextRow][nextCol]; // Increment the score after merging cells
    updateHighestScore(score); 
}
