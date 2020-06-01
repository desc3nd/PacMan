#include <iostream>
#include<SFML/Graphics.hpp>
#include"PacBoard.h"
#include"PacMan.h"
#include"PacGhosts.h"
#include "PacView.h"
#include "PacSFMLGraphic.h"
int main() {
    PacBoard board;
//board.Debug_Display();
    PacMan Pacman(board);
    Pacman.DebugDisplayPac();
    Pacman.PacMovement('w');
    Pacman.PacMovement('w');
    Pacman.PacMovement('w');
    Pacman.PacMovement('w');
    std::cout << std::endl;
    std::cout << std::endl;
    Pacman.DebugDisplayPac();
    PacGhosts ghost(board);
    PacView View(Pacman, ghost, board);
    View.Display();
    PacSFMLGraphic graphic(board, Pacman, ghost);
    sf::RenderWindow win(sf::VideoMode(graphic.getScreenWidth(), graphic.getScreenHeight()), "PACMAN");
    win.setVerticalSyncEnabled(true);
    sf::Event event;
    while (win.isOpen()) {
        while (win.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                win.close();
            }

        }
        win.clear(sf::Color::Black);
        win.draw(graphic);
        win.display();
    }
}