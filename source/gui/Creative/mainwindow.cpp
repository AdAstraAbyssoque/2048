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
    setFocus();

    QMenuBar *menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    QMenu *fileMenu = menuBar->addMenu("File");

    QAction *openAction = fileMenu->addAction("Open");
    QAction *saveAction = fileMenu->addAction("Save");

    connect(openAction, &QAction::triggered, this, &MainWindow::openFile);
    connect(saveAction, &QAction::triggered, this, &MainWindow::saveFile);

    button = new QPushButton("Start", this);
    button->setGeometry(60,400,200,50);

    srand(uint(QTime(0,0,0).secsTo(QTime::currentTime())));
    connect(button, SIGNAL(clicked()), this, SLOT(slotStart()));

    highestScoreLabel = new QLabel("Highest Score: 0", this);
    statusBar()->addWidget(highestScoreLabel);
    currentScoreLabel = new QLabel("Current Score: 0", this);
    statusBar()->addWidget(currentScoreLabel);

    setWindowTitle("2048 Game");
    setFixedSize(300, 500);

    QFrame *backgroundFrame = new QFrame(this);
    backgroundFrame->setGeometry(75, 20, 170, 80);
    backgroundFrame->setStyleSheet("background-color: #CCCCCC; border-radius: 10px;");

    QLabel *titleLabel = new QLabel("2048", this);
    titleLabel->setFont(QFont("Arial", 40, QFont::Bold));
    titleLabel->setStyleSheet("QLabel { color : #776e65; }"); 
    titleLabel->setGeometry(100, 10, 200, 100); 


}

void MainWindow::openFile() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", QDir::homePath(), "Text Files (*.txt)");
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Could not open file");
        return;
    }
    QTextStream in(&file);
    QString line = in.readLine();
    QStringList list = line.split(" ");
    int index = 0;
    for (int i = 0; i < 4; i++) {
        // Initialize each row with 0s
        for (int j = 0; j < 4; j++) {
            game.board[i][j] = list[index].toInt();
            index++;
        }
    }
    game.score = list[index].toInt();
    game.highestScore = list[index + 1].toInt();
    gameStarted = true;
    updateScoreLabel();
    updateHighestScoreLabel();
    update();
}

void MainWindow::saveFile() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", QDir::homePath(), "Text Files (*.txt)");
    if (!fileName.endsWith(".txt")) {
        fileName += ".txt";
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Could not save file");
        return;
    }
    QTextStream out(&file);
    QString line = "";
    for (int i = 0; i < 4; i++) {
        // Initialize each row with 0s
        for (int j = 0; j < 4; j++) {
            line += QString::number(game.board[i][j]) + " ";
        }
    }
    line += QString::number(game.score);
    out << line;
    line += QString::number(game.highestScore);
    out << line;
    file.close();
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

std::map<int, QColor> colorMap = {
    {0, Qt::lightGray},
    {2, Qt::yellow},
    {4, Qt::darkYellow},
    {8, Qt::green},
    {16, Qt::darkGreen},
    {32, Qt::cyan},
    {64, Qt::darkCyan},
    {128, Qt::magenta},
    {256, Qt::darkMagenta},
    {512, Qt::red},
    {1024, Qt::darkRed},
    {2048, Qt::blue},
    {4096, Qt::darkBlue},
    {8192, Qt::gray},
    {16384, Qt::darkGray},
    {32768, Qt::lightGray},
    {65536, Qt::white}
};

void MainWindow::paintEvent(QPaintEvent *event){
    (void)event;
    QPainter p(this);
    p.setPen(Qt::black);
    p.setFont(QFont("Arial", 20));

        for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            p.setPen(Qt::transparent);
            int value = game.board[j][i];
            
            if (colorMap.find(value) != colorMap.end()) {
                p.setBrush(colorMap[value]);
                p.drawRoundedRect(i * 60 + 40, j * 60 + 120, 55, 55, 10, 10);

                if (value != 0) {
                    p.setPen(Qt::black);
                    p.setFont(QFont("Arial", 14));
                    QString customText;
                    switch (value) {
                        case 2:
                            customText = "Hello\nWorld";
                            break;
                        case 4:
                            customText = "Oper\nator";
                            break;
                        case 8:
                            customText = "Func\ntion";
                            break;
                        case 16:
                            customText = "Array";
                            break;
                        case 32:
                            customText = "Recur\nsion";
                            break;
                        case 64:
                            customText = "Struct";
                            break;
                        case 128:
                            customText = "Stream";
                            break;
                        case 256:
                            customText = "Pointer";
                            break;
                        case 512:
                            customText = "Con\ntainers";
                            break;
                        case 1024:
                            customText = "Algo\nrithm";
                            break;
                        case 2048:
                            customText = "Qt";
                            break;
                        case 4096:
                            customText = "STL";
                            break;
                        case 8192:
                            customText = "C++";
                            break;
                        case 16384:
                            customText = "C";
                            break;
                        case 32768:
                            customText = "Java";
                            break;
                        case 65536:
                            customText = "Python";
                            break;
                        default:
                            customText = QString::number(value);
                            break;
                    }

                    p.drawText(QRect(i * 60 + 40, j * 60 + 120, 55, 55), customText, QTextOption(Qt::AlignCenter));
                }
            } else {
                p.setBrush(Qt::lightGray);
                p.drawRect(i * 60 + 40, j * 60 + 120, 55, 55);
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