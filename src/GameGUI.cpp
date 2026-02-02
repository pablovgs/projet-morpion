#include "GameGUI.hpp"

GameGUI::GameGUI() : window(sf::VideoMode(600, 600), "Morpion POO - SFML") {}

void GameGUI::drawGrid() {
    for (int i = 1; i < 3; i++) {
        // Lignes blanches pour séparer les cases
        sf::RectangleShape lineH(sf::Vector2f(600, 5));
        lineH.setPosition(0, i * cellSize);
        window.draw(lineH);

        sf::RectangleShape lineV(sf::Vector2f(5, 600));
        lineV.setPosition(i * cellSize, 0);
        window.draw(lineV);
    }
}

void GameGUI::drawPieces() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char s = engine.getGrid().getCellSymbol(i, j);
            if (s == 'X') {
                // On dessine une croix
                sf::RectangleShape r1(sf::Vector2f(150, 5));
                r1.setRotation(45);
                r1.setPosition(j * cellSize + 50, i * cellSize + 40);
                window.draw(r1);
                sf::RectangleShape r2(sf::Vector2f(150, 5));
                r2.setRotation(135);
                r2.setPosition(j * cellSize + 150, i * cellSize + 40);
                window.draw(r2);
            } else if (s == 'O') {
                // On dessine un cercle
                sf::CircleShape circle(60);
                circle.setOutlineThickness(5);
                circle.setFillColor(sf::Color::Transparent);
                circle.setPosition(j * cellSize + 40, i * cellSize + 40);
                window.draw(circle);
            }
        }
    }
}

void GameGUI::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) 
                window.close();
            
            if (event.type == sf::Event::MouseButtonPressed && !engine.isGameOver()) {
                int row = event.mouseButton.y / cellSize;
                int col = event.mouseButton.x / cellSize;
                engine.playTurn(row, col);

                // Si le coup vient de terminer la partie, on change le titre
                if (engine.isGameOver()) {
                    if (engine.checkWin()) {
                        window.setTitle("Victoire de " + engine.getCurrentPlayer()->getName() + " ! [R] pour rejouer");
                    } else {
                        window.setTitle("Match Nul ! [R] pour rejouer");
                    }
                }
            }

            // Appuie sur R pour recommencer
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::R && engine.isGameOver()) {
                    engine.reset();
                    window.setTitle("Morpion POO - SFML");
                }
            }
        }

        window.clear(sf::Color(40, 40, 40));
        drawGrid();
        drawPieces();
        window.display();
    }
}