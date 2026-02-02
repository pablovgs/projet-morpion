#include "GameEngine.hpp"

GameEngine::GameEngine() : gameOver(false) {
    p1 = new HumanPlayer("Joueur 1", 'X');
    p2 = new HumanPlayer("Joueur 2", 'O');
    currentPlayer = p1;
}

GameEngine::~GameEngine() {
    delete p1;
    delete p2;
}

bool GameEngine::playTurn(int row, int col) {
    if (gameOver) return false;

    // On demande à la grille de se mettre à jour
    if (grid.updateCell(row, col, currentPlayer->getSymbol())) {
        if (checkWin() || checkDraw()) {
            gameOver = true;
        } else {
            // Changement de tour
            currentPlayer = (currentPlayer == p1) ? p2 : p1;
        }
        return true;
    }
    return false;
}

bool GameEngine::checkWin() const {
    char s = currentPlayer->getSymbol();
    for (int i = 0; i < 3; i++) {
        // Vérification Horizontale
        if (grid.getCellSymbol(i, 0) == s && grid.getCellSymbol(i, 1) == s && grid.getCellSymbol(i, 2) == s) return true;
        // Vérification Verticale
        if (grid.getCellSymbol(0, i) == s && grid.getCellSymbol(1, i) == s && grid.getCellSymbol(2, i) == s) return true;
    }
    return false;
}

bool GameEngine::checkDraw() const {
    if (checkWin()) return false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid.getCellSymbol(i, j) == ' ') return false;
        }
    }
    return true;
}

void GameEngine::reset() {
    grid.reset();
    currentPlayer = p1;
    gameOver = false;
}