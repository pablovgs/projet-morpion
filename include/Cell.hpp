#ifndef CELL_HPP
#define CELL_HPP

// Classe de base pour une case de la grille
class Cell {
protected:
    char symbol; // ' ', 'X' ou 'O'

public:
    Cell();
    virtual ~Cell() {} // Toujours un destructeur virtuel en POO !
    char getSymbol() const;
    virtual void setSymbol(char s);
};

// On crée des classes filles pour montrer qu'on maîtrise l'héritage
class XCell : public Cell { public: XCell(); };
class OCell : public Cell { public: OCell(); };

#endif