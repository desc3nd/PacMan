#include <iostream>
#include<SFML/Graphics.hpp>
#include"PacBoard.h"
#include"PacMan.h"
#include"PacGhosts.h"
#include "PacView.h"
#include "PacSFMLGraphic.h"
#include "PacSFMLEvent.h"
#include"PacGameMenager.h"
#include "PacSFMLMusic.h"
int main()
{
    PacBoard board;
    srand(time(NULL));
    PacMan Pacman(board);
    PacGhosts ghost(board);
    PacView View(Pacman, ghost, board);
    PacGameMenager gameMenager(Pacman,ghost,board);
    PacSFMLGraphic graphic(board, Pacman, ghost,gameMenager);
    PacSFMLEvent ctrl(graphic,Pacman);
    PacSFMLMusic music(board,Pacman,ghost,gameMenager);
    sf::Clock clk1;
    sf::RenderWindow win(sf::VideoMode(graphic.getScreenWidth(), graphic.getScreenHeight()), "PACMAN");
    win.setVerticalSyncEnabled(true);
    sf::Event event;
    music.playMusic();
    board.Debug_Display();
    while (win.isOpen())
    {
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed )
            {
                win.close();
            }
            ctrl.startGame();
            if(ctrl.getEnterStatus())
            {
                ctrl.PacManMove();
                graphic.drawBoard();
            }
        }
        if(clk1.getElapsedTime().asSeconds()>gameMenager.getRefreshSpeed() && ctrl.getEnterStatus() &&  gameMenager.getGameStatus()!=Lost)
        {
            for(int i=0; i<ghost.getNumberOfGhosts();i++)
            {
                ghost.ghostMove(i);
                graphic.drawBoard();
                gameMenager.play();
            }
            ctrl.SelfMove();
            gameMenager.eatableGhosts();
            clk1.restart();
            graphic.drawBoard();
        }
        music.stopStartMusic();
        music.soundEffect();
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
        if(ctrl.getAgainStatus() && gameMenager.getGameStatus()==Win)
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

}