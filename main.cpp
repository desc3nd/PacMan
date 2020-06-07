#include <iostream>
#include<SFML/Graphics.hpp>
#include"PacBoard.h"
#include"PacMan.h"
#include"PacGhosts.h"
#include "PacView.h"
#include "PacSFMLGraphic.h"
#include "PacSFMLEvent.h"
#include"PacGameMenager.h"
int main() {
    PacBoard board;
    srand(time(NULL));
//board.Debug_Display();
    PacMan Pacman(board);
    PacGhosts ghost(board);
    PacView View(Pacman, ghost, board);
    View.Display();
    PacSFMLGraphic graphic(board, Pacman, ghost);
    PacSFMLEvent LetsDoThis(graphic,Pacman);
    sf::Clock clk1;
    sf::Clock clk2;
    PacGameMenager gameMenager(Pacman,ghost,board);
    sf::RenderWindow win(sf::VideoMode(graphic.getScreenWidth(), graphic.getScreenHeight()), "PACMAN");
    win.setVerticalSyncEnabled(true);
    sf::Event event;
    while (win.isOpen()) {
        while (win.pollEvent(event)) {
            LetsDoThis.PacManMove();
            if (event.type == sf::Event::Closed) {
                win.close();
            }

        }
        if(clk1.getElapsedTime().asSeconds()>1)
        {
            ghost.ghostMove(0);
            ghost.ghostMove(1);
            ghost.ghostMove(2);
          ghost.ghostMove(3);
            LetsDoThis.SelfMove();
            gameMenager.play();
            graphic.drawBoard();
            clk1.restart();

        }
        win.clear(sf::Color::Black);
        win.draw(graphic);
        win.display();
    }
    std::cout<<gameMenager.getPoints();
    View.Display();
    board.Debug_Display();
}