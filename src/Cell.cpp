#include "Cell.hpp"

Cell::Cell() : symbol(' ') {}
char Cell::getSymbol() const { return symbol; }
void Cell::setSymbol(char s) { symbol = s; }

XCell::XCell() { symbol = 'X'; }
OCell::OCell() { symbol = 'O'; }