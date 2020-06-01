//
// Created by Marcinek on 01.06.2020.
//

#include "PacGhosts.h"

PacGhosts::PacGhosts(PacBoard &x):tab(x) {
    height=tab.getHeight();
    width=tab.getWidth();
    ghostCoord[0].Row=15;
    ghostCoord[0].Col=12;
    ghostCoord[1].Row=15;
    ghostCoord[1].Col=14;
    ghostCoord[2].Row=16;
    ghostCoord[2].Col=14;
   board[ghostCoord[0].Row][ghostCoord[0].Col].hasGhost=true;
   board[ghostCoord[1].Row][ghostCoord[1].Col].hasGhost=true;
   board[ghostCoord[2].Row][ghostCoord[2].Col].hasGhost=true;


}

void PacGhosts::ghostsMovement(int nrOfGhost) {
    board[ghostCoord[nrOfGhost].Row][ghostCoord[nrOfGhost].Col].hasGhost=true;
   if(tab.getCharInfo(ghostCoord[nrOfGhost].Row-1,ghostCoord[nrOfGhost].Col)=='_') //góra
   {
       ghostCoord[nrOfGhost].Row--;
       board[ghostCoord[nrOfGhost].Row][ghostCoord[nrOfGhost].Col].hasGhost=true;
   }
    if(tab.getCharInfo(ghostCoord[nrOfGhost].Row,ghostCoord[nrOfGhost].Col+1)=='_') //prawo
    {
        ghostCoord[nrOfGhost].Col++;
        board[ghostCoord[nrOfGhost].Row][ghostCoord[nrOfGhost].Col].hasGhost=true;
    }
    if(tab.getCharInfo(ghostCoord[nrOfGhost].Row+1,ghostCoord[nrOfGhost].Col-1)=='_') //lewo
    {
        ghostCoord[nrOfGhost].Col--;
        board[ghostCoord[nrOfGhost].Row][ghostCoord[nrOfGhost].Col].hasGhost=true;
    }
    if(tab.getCharInfo(ghostCoord[nrOfGhost].Row+1,ghostCoord[nrOfGhost].Col)=='_') //dol
    {
        ghostCoord[nrOfGhost].Row++;
        board[ghostCoord[nrOfGhost].Row][ghostCoord[nrOfGhost].Col].hasGhost=true;
    }
}

bool PacGhosts::isGhost(int row,int col) {
 if(board[row][col].hasGhost)
 {
     return true;
 }
 return false;
}
