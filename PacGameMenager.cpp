//
// Created by Marcinek on 01.06.2020.
//

#include "PacGameMenager.h"

PacGameMenager::PacGameMenager(PacMan &pac, PacGhosts &ghost, PacBoard &tab):pacMan(pac),ghosts(ghost),board(tab)
{
    height=board.getHeight();
    width=board.getWidth();
    points=0;
    status=Running;
    refreshSpeed=0.5;
}

void PacGameMenager::play() {
    for(int row=0; row<height; row++)
    {
        for(int col=0; col<width; col++)
        {
            if(pacMan.getCharInfo(row, col) && ghosts.isGhost(row, col))
            {
                status=Lost;
            }
            if(pacMan.getCharInfo(row,col) && board.getCharInfo(row,col)=='f')
            {
                points++;
                board.setFoodFalse(row,col);
            }
        }

    }

}

GameStatus PacGameMenager::getGameStatus() {
    return status;
}

int PacGameMenager::getPoints() {
    return points;
}

int PacGameMenager::getRefreshSpeed() {
    return refreshSpeed;
}

void PacGameMenager::DefaultSettings() {
    status=Running;
    if(points<330)
    {
        points=0;
    }



}



