
#include <iostream>
#include "PacSFMLMusic.h"

PacSFMLMusic::PacSFMLMusic(PacBoard &Board, PacMan &pac, PacGhosts &ghost, PacGameMenager &menager):board(Board),pacMan(pac),ghosts(ghost),ctrl(menager)
{
    height=board.getHeight();
    width=board.getWidth();
    if(!buffer[0].loadFromFile("blech.wav") || !buffer[1].loadFromFile("pipe.wav") || !buffer[2].loadFromFile("fail.wav") || !buffer[3].loadFromFile("win.wav") || !buffer[4].loadFromFile("theme.wav"))
    {
        std::cerr<<"problem z muza";
    }
    sound[0].setBuffer(buffer[0]);
    sound[1].setBuffer(buffer[1]);
    sound[2].setBuffer(buffer[2]);
    sound[3].setBuffer(buffer[3]);
    sound[4].setBuffer(buffer[4]);
}

void PacSFMLMusic::soundEffect() {
    for(int row=0; row<height; row++)
    {
        for(int col=0; col<width; col++)
        {
            if(pacMan.isPacman(row, col) && ghosts.isGhost(row, col) && ctrl.getEatableStatus())
            {
                sound[3].play();
            }
            if(pacMan.isPacman(row, col) && ghosts.isGhost(row, col) && !ctrl.getEatableStatus())
            {
                sound[2].play();
            }
            if(pacMan.isPacman(row, col) && board.getCharInfo(row, col) == 'p')
            {
                sound[0].play();
            }
            if(pacMan.isPacman(row, col) && board.getCharInfo(row, col) == 'f')
            {
                sound[1].play();
            }
        }
    }
}

void PacSFMLMusic::playMusic() {
    sound[4].setVolume(50.f);
    sound[4].setLoop(true);
    sound[4].play();
}
