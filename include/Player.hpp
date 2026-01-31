#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>

class Player {
protected:
    std::string name;
    char symbol;

public:
    Player(std::string n, char s);
    virtual ~Player() {}
    std::string getName() const;
    char getSymbol() const;
};

// Joueur Humain (comme demandé dans l'énoncé)
class HumanPlayer : public Player {
public:
    HumanPlayer(std::string n, char s);
};

#endif