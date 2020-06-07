//
// Created by Marcinek on 01.06.2020.
//

#include "PacGameMenager.h"

PacGameMenager::PacGameMenager(PacMan &pac, PacGhosts &ghost, PacBoard &tab):pacMan(pac),ghosts(ghost),board(tab)
{
    height=board.getHeight();
    width=board.getWidth();
    points=0;
    lives=3;
    status=Running;
}

void PacGameMenager::play() {
    for(int row=0; row<height; row++)
    {
        for(int col=0; col<width; col++)
        {
            if(pacMan.getCharInfo(row, col) && ghosts.isGhost(row, col))
            {
                lives--;
            }
            if(pacMan.getCharInfo(row,col) && board.getCharInfo(row,col)=='f')
            {
                points++;
                board.setFoodFalse(row,col);
            }
        }

    }
    if(lives<=0)
    {
        status=Lost;
    }
}

GameStatus PacGameMenager::getGameStatus() {
    return status;
}

int PacGameMenager::getLives() {
    return lives;
}

int PacGameMenager::getPoints() {
    return points;
}
