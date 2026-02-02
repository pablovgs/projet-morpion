#include "Grid.hpp"

Grid::Grid() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cases[i][j] = new Cell(); 
        }
    }
}

Grid::~Grid() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            delete cases[i][j];
        }
    }
}

char Grid::getCellSymbol(int row, int col) const {
    if (row >= 0 && row < 3 && col >= 0 && col < 3) {
        return cases[row][col]->getSymbol();
    }
    return ' ';
}

bool Grid::updateCell(int row, int col, char symbol) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3) {
        if (cases[row][col]->getSymbol() == ' ') {
            cases[row][col]->setSymbol(symbol);
            return true;
        }
    }
    return false;
}

void Grid::reset() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cases[i][j]->setSymbol(' ');
        }
    }
}