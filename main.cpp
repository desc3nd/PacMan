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
    PacGameMenager gameMenager(Pacman,ghost,board);
    PacSFMLGraphic graphic(board, Pacman, ghost,gameMenager);
    PacSFMLEvent ctrl(graphic,Pacman);
    sf::Clock clk1;
    sf::Clock clk2;
    sf::RenderWindow win(sf::VideoMode(graphic.getScreenWidth(), graphic.getScreenHeight()), "PACMAN");
    win.setVerticalSyncEnabled(true);
    sf::Event event;
    while (win.isOpen()) {
        while (win.pollEvent(event)) {

            if (event.type == sf::Event::Closed ) {
                win.close();
            }
            ctrl.startGame();
            if(ctrl.getEnterStatus())
            {
                ctrl.PacManMove();
                graphic.drawBoard();
            }
        }
        if(clk1.getElapsedTime().asSeconds()>0.4 && ctrl.getEnterStatus() &&  gameMenager.getGameStatus()!=Lost)
        {
            for(int i=0; i<6;i++)
            {
                ghost.ghostMove(i);
                gameMenager.play();
            }
            ctrl.SelfMove();

            clk1.restart();
            graphic.drawBoard();
        }
        gameMenager.play();
        if(gameMenager.getGameStatus()==Lost)
        {
            graphic.drawGameOver();
            ctrl.restart();
        }
        if(ctrl.getAgainStatus() && gameMenager.getGameStatus()==Lost)
        {
            board.DefaultSettings();
            Pacman.DefaultSettings();
            ghost.DefaultSettings();
            gameMenager.DefaultSettings();
            ctrl.DefaultSettings();
            graphic.drawBoard();
        }
        if(gameMenager.getPoints()>=330)
        {
            board.DefaultSettings();
            Pacman.DefaultSettings();
            ghost.DefaultSettings();
            gameMenager.DefaultSettings();
            ctrl.DefaultSettings();
            graphic.drawBoard();
        }
        win.clear(sf::Color::Black);
        win.draw(graphic);
        win.display();
    }
    std::cout<<gameMenager.getPoints();
    View.Display();
    board.Debug_Display();
}