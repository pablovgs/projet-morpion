#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include "Grid.hpp"
#include "Player.hpp"

class GameEngine {
private:
    Grid grid;
    Player* p1;
    Player* p2;
    Player* currentPlayer;
    bool gameOver;

public:
    GameEngine();
    ~GameEngine();

    bool playTurn(int row, int col);
    bool checkWin() const;
    bool checkDraw() const;
    
    // Accesseurs
    Grid& getGrid() { return grid; }
    Player* getCurrentPlayer() const { return currentPlayer; }
    bool isGameOver() const { return gameOver; }
    void reset();
};

#endif