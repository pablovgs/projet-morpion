#ifndef GRID_HPP
#define GRID_HPP

#include "Cell.hpp"

class Grid {
private:
    // Un tableau de 3x3 contenant des pointeurs vers nos cellules
    Cell* cases[3][3]; 

public:
    Grid();
    virtual ~Grid();

    bool updateCell(int row, int col, char symbol);
    char getCellSymbol(int row, int col) const;
    void reset();
};

#endif