// core2048.cpp

#include "core2048.hpp"

// Constructor definition
GameBoard::GameBoard() {
    // Display the welcome message
    displayWelcomeMessage();

    // Wait for the user to press B
    while (true) {
        char input;
        std::cin >> input;
        if (input == 'b' || input == 'B') {
            // Clear input buffer to prevent interference from previous inputs
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break; // End loop, user has pressed B
        }
        else if (input == 'q' || input == 'Q') {
            quit();
        }
        else if (input == 'r' || input == 'R') {
            restart();
        }
        else if (input == 'h' || input == 'H') {
            displayHelpMessage();
        }
        else {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
        
    }

    // Game logic starts here
    std::cout << "Game has started!" << std::endl;

    // Initialize the board and score in the constructor
    initializeBoard();
    score = 0;
}

// Display functions
void GameBoard::displayWelcomeMessage() {
    //clear screen
    // Display the welcome message
    std::cout << "Welcome to 2048!" << std::endl;
    std::cout << "Press B to begin." << std::endl;
    std::cout << "Use the W, A, S, D keys or arrow keys to move the tiles." << std::endl;
    std::cout << "Press Q to quit." << std::endl;
    std::cout << "Press R to restart." << std::endl;
    std::cout << "For more information, press H." << std::endl;
}

void GameBoard::displayBoard() {
    // Clear the screen
    clearScreen();  
    // Display the board
    std::cout << "-----------------------------" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "|";
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) {
                std::cout << "      |";
            } else {
                std::cout << std::setw(6) << board[i][j] << "|";
            }
        }
        std::cout << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }
    // Display the score
    std::cout << "Score: " << score << std::endl;
}

void GameBoard::clearScreen() {
    std::cout << "\033[2J\033[1;1H";  // ANSI escape code to clear the screen
}

void GameBoard::displayHelpMessage() {
    // Display the help message
    std::cout << "Instructions:" << std::endl;
    std::cout << "Press B to begin." << std::endl;
    std::cout << "Use the W, A, S, D keys or arrow keys to move the tiles." << std::endl;
    std::cout << "Press Q to quit." << std::endl;
    std::cout << "Press R to restart." << std::endl;
    // Display the product information
    std::cout << "Product information:" << std::endl;
    std::cout << "2048-cli version 1.0.0" << std::endl;
    std::cout << "Written by: Bowen LIU" << std::endl;
    std::cout << "If you want to go back to the game, press R." << std::endl;
}

// Game control functions
void GameBoard::restart() {    
    // Clear the board
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = 0;
        }
    }

    // Clear the screen
    clearScreen();
    
    std::cout << "Game has restarted!" << std::endl;

        // Display the welcome message
    displayWelcomeMessage();

    // Wait for the user to press B
    while (true) {
        char input;
        std::cin >> input;
        if (input == 'b' || input == 'B') {
            // Clear input buffer to prevent interference from previous inputs
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break; // End loop, user has pressed B
        }
        else if (input == 'q' || input == 'Q') {
            quit();
        }
        else if (input == 'r' || input == 'R') {
            restart();
        }
        else if (input == 'h' || input == 'H') {
            displayHelpMessage();
        }
        else {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
        
    }

    // Game logic starts here
    std::cout << "Game has started!" << std::endl;

    // Initialize the board and score in the constructor
    initializeBoard();
    score = 0;
}

void GameBoard::quit() {
    // Quit the game
    std::exit(0);
}


// Game logic functions
void GameBoard::initializeBoard() {
    for (int i = 0; i < 4; i++) {
        // Initialize each row with 0s
        for (int j = 0; j < 4; j++) {
            board[i][j] = 0;
        }
    }
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
    else {
        std::cout << "Invalid move. Please try again." << std::endl;
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
    else {
        std::cout << "Invalid move. Please try again." << std::endl;
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
    else {
        std::cout << "Invalid move. Please try again." << std::endl;
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
    else {
        std::cout << "Invalid move. Please try again." << std::endl;
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
}

void GameBoard::judgeWin(){
    // Check if the user has already made a choice, if yes, exit early
    if (isChoose) {
        return;
    }

    // If any tile is higher than 2048, hint the user winning the game, and ask if they want to continue
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] >= 8) {  // Check if any tile is higher than or equal to 2048
                isWin = true;
                break;  // No need to continue checking once a win is found
            }
        }
        if (isWin) {
            break;  // No need to continue checking rows once a win is found
        }
    }
    
    if (isWin) {
        std::cout << "You win! Do you want to continue? (Y/N)" << std::endl;
        char input;
        std::cin >> input;
        if (input == 'n' || input == 'N') {
            quit();
        }
        else if (input == 'y' || input == 'Y') {
            std::cout << "Game has continued!" << std::endl;
            displayBoard();
        }
        isChoose = true;  // Mark that the user has made a choice
    }
}




int main() {
    GameBoard game; // Instantiate the game board

    // Game loop
    while (!game.isGameOver()) {        
        // Display the current state of the board and score

        game.displayBoard();

        //If the one of the tile is higher than 2048, hint the user wining the game, and ask if they want to continue
        
        game.judgeWin();

        // Listen for user input
        char input;
        std::cin >> input;
        if (input == 'q' || input == 'Q') {
            game.quit();
        } else if (input == 'r' || input == 'R') {
            game.restart();
        } else if (input == 'h' || input == 'H') {
            game.displayHelpMessage();
        } else if (input == 'w' || input == 'W' ) {
            bool isMoved = game.moveUp();
            game.operatemoveUp(isMoved);
        } else if (input == 'a' || input == 'A' ) {
            bool isMoved = game.moveLeft();
           game.operatemoveLeft(isMoved);
        } else if (input == 's' || input == 'S' ) {
            bool isMoved = game.moveDown();
            game.operatemoveDown(isMoved);
        } else if (input == 'd' || input == 'D' ) {
            bool isMoved = game.moveRight();
            game.operatemoveRight(isMoved);
        }
    }

    // Display the final score and game over message
    game.displayBoard();
    std::cout << "Game over!" << std::endl;
    std::cout << "Please press R to restart or Q to quit." << std::endl;

    return 0;
}
