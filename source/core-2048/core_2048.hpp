#ifndef CORE2048_HPP
#define CORE2048_HPP

#include <iostream>
#include <iomanip>
#include <chrono>
#include <algorithm>
#include <random>

class GameBoard {
public:
    int board[4][4];
    int score;
    bool isWin = false;
    bool isChoose = false;
    // Constructor
    GameBoard();

    // Display
    void displayWelcomeMessage();
    void displayBoard();
    void clearScreen();
    void displayHelpMessage();
    int getHighestScore() const;
    void updateHighestScore(int newScore);

    // Game Control
    void restart();
    void quit();

    // Game Logic
    void initializeBoard();
    bool canMerge(int row, int col);
    bool moveUp();
    bool moveDown();
    bool moveLeft();
    bool moveRight();
    bool isGameOver();
    int getScore();
    void operatemoveUp(bool isMoved);
    void operatemoveDown(bool isMoved);
    void operatemoveLeft(bool isMoved);
    void operatemoveRight(bool isMoved);
    bool isBoardFull();
    void judgeWin();
    int highestScore;

private:
    // Helper functions
    void addNewTile();
    void mergeCells(int currentRow, int currentCol, int nextRow, int nextCol);

};

#endif // CORE2048_HPP
