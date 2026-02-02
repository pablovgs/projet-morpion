#ifndef GAMEGUI_HPP
#define GAMEGUI_HPP

#include <SFML/Graphics.hpp>
#include "GameEngine.hpp"

class GameGUI {
private:
    sf::RenderWindow window;
    GameEngine engine;
    const int cellSize = 200;

    void drawGrid();
    void drawPieces();

public:
    GameGUI();
    void run();
};

#endif