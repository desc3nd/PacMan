#include <iostream>
#include<SFML/Graphics.hpp>
#include"PacBoard.h"
#include"PacMan.h"
#include"PacGhosts.h"
#include "PacView.h"
#include "PacSFMLGraphic.h"
#include "PacSFMLEvent.h"
int main() {
    PacBoard board;
    srand(time(NULL));
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
    PacSFMLEvent LetsDoThis(graphic,Pacman);
    sf::Clock clk;
    sf::RenderWindow win(sf::VideoMode(graphic.getScreenWidth(), graphic.getScreenHeight()), "PACMAN");
    win.setVerticalSyncEnabled(true);
    sf::Event event;
    while (win.isOpen()) {
        while (win.pollEvent(event)) {
            LetsDoThis.PacManMove();
            graphic.drawBoard();
            if (event.type == sf::Event::Closed) {
                win.close();
            }

        }
        if(clk.getElapsedTime().asSeconds()>0.5)
        {
            ghost.ghostsMovement(0);
            ghost.ghostsMovement(2);
            ghost.ghostsMovement(1);
            LetsDoThis.SelfMove();
            graphic.drawBoard();
            clk.restart();
        }
        win.clear(sf::Color::Black);
        win.draw(graphic);
        win.display();
    }
    View.Display();
}