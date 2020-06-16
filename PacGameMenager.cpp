
#include "PacGameMenager.h"
PacGameMenager::PacGameMenager(PacMan &pac, PacGhosts &ghost, PacBoard &tab):pacMan(pac),ghosts(ghost),board(tab)
{
    height=board.getHeight();
    width=board.getWidth();
    points=0;
    foodLeft=332;
    status=Running;
    refreshSpeed=0.2;
    eatable=false;
    eatableGhostsTime=40;
    nrOfLoop=30;
}

void PacGameMenager::checkRelationAndRules()
{
    for(int row=0; row<height; row++)
    {
        for(int col=0; col<width; col++)
        {
            if(pacMan.isPacman(row, col) && ghosts.isGhost(row, col) && eatable)
            {
                points=points+100;
                ghosts.DefaultSettings();

            }
            if(pacMan.isPacman(row, col) && ghosts.isGhost(row, col) && !eatable)
            {
                status=Lost;
            }
            if(pacMan.isPacman(row, col) && board.getCharInfo(row, col) == 'p')
            {
                points=points+50;
                eatableGhostsTime = 0;
                board.setPremiumFoodFalse(row,col);
                foodLeft--;
            }
            if(pacMan.isPacman(row, col) && board.getCharInfo(row, col) == 'f')
            {
                points++;
                board.setFoodFalse(row,col);
                foodLeft--;
            }

        }

    }

}

GameStatus PacGameMenager::getGameStatus()
{
    if(foodLeft<=0)
    {
        status=Win;
    }
    return status;
}

int PacGameMenager::getPoints() const
{
    return points;
}

float PacGameMenager::getRefreshSpeed() const
{
    return refreshSpeed;
}

void PacGameMenager::DefaultSettings()
{
    if(status==Lost)
    {
        points=0;
    }
    foodLeft=332;
    status=Running;
}

void PacGameMenager::eatableGhosts()
{

    eatableGhostsTime++;
    if(eatableGhostsTime<=nrOfLoop)
    {
      eatable=true;
    }
    else
    {
        eatable=false;
    }

}

bool PacGameMenager::getEatableStatus() const
{
    return eatable;
}



