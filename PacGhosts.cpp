//
// Created by Marcinek on 01.06.2020.
//

#include "PacGhosts.h"
#include<cstdlib>
#include<time.h>
#include <iostream>
PacGhosts::PacGhosts(PacBoard &x):tab(x) {

    direction.up=true;
    direction.down=true;
    direction.right=true;
    direction.left=true;
    height=tab.getHeight();
    width=tab.getWidth();
    ghostCoord[0].Row=16;
    ghostCoord[0].Col=5;
    ghostCoord[1].Row=16;
    ghostCoord[1].Col=24;
    ghostCoord[2].Row=10;
    ghostCoord[2].Col=15;
    ghostCoord[3].Row=1;
    ghostCoord[3].Col=15;
    nr=rand()%2+1;
    licznik=1;


  board[ghostCoord[0].Row][ghostCoord[0].Col].hasGhost=true;
   board[ghostCoord[1].Row][ghostCoord[1].Col].hasGhost=true;
   board[ghostCoord[2].Row][ghostCoord[2].Col].hasGhost=true;
   board[ghostCoord[3].Row][ghostCoord[3].Col].hasGhost=true;


}

void PacGhosts::ghostsMovement(int nrOfGhost) {
licznik=1;
   if(tab.getCharInfo(ghostCoord[nrOfGhost].Row,ghostCoord[nrOfGhost].Col-1)=='*' || board[ghostCoord[nrOfGhost].Row][ghostCoord[nrOfGhost].Col-1].hasGhost)
   {
    direction.left=false;
    licznik++;
   }
 if(tab.getCharInfo(ghostCoord[nrOfGhost].Row,ghostCoord[nrOfGhost].Col+1)=='*'||  board[ghostCoord[nrOfGhost].Row][ghostCoord[nrOfGhost].Col+1].hasGhost)
   {
       direction.right=false;
       licznik++;
   }
   if(tab.getCharInfo(ghostCoord[nrOfGhost].Row+1,ghostCoord[nrOfGhost].Col)=='*' ||  board[ghostCoord[nrOfGhost].Row +1][ghostCoord[nrOfGhost].Col].hasGhost)
    {
        direction.down=false;
        licznik++;
    }
   if(tab.getCharInfo(ghostCoord[nrOfGhost].Row-1,ghostCoord[nrOfGhost].Col)=='*'||  board[ghostCoord[nrOfGhost].Row -1][ghostCoord[nrOfGhost].Col].hasGhost)
    {
        direction.up=false;
        licznik++;
    }
if(licznik==5)
{
    return;
}
}

bool PacGhosts::isGhost(int row,int col) {
 if(board[row][col].hasGhost)
 {
     return true;
 }
 return false;
}


void PacGhosts::ghostMove(int nrOfGhost ) {
   ghostsMovement(nrOfGhost);
       srand(time(NULL));

while(true) {
    nr=rand()%4+1;
    board[ghostCoord[nrOfGhost].Row][ghostCoord[nrOfGhost].Col].hasGhost = false;
    if (direction.up == true && nr == 1) {
        ghostCoord[nrOfGhost].Row--;
        board[ghostCoord[nrOfGhost].Row][ghostCoord[nrOfGhost].Col].hasGhost = true;
        direction.up = true;
        direction.right = true;
        direction.left = true;
        direction.down = false;
        if(licznik==4)
        {
            direction.down=true;
        }
        return;
    }
    if (direction.right == true && nr == 2) {
        ghostCoord[nrOfGhost].Col++;
        board[ghostCoord[nrOfGhost].Row][ghostCoord[nrOfGhost].Col].hasGhost = true;
        direction.down = true;
        direction.right = true;
        direction.up = true;
        direction.left = false;
        if(licznik==4)
        {
            direction.left=true;
        }
        return;

    }
    if (direction.down == true && nr == 3) {
        ghostCoord[nrOfGhost].Row++;
        board[ghostCoord[nrOfGhost].Row][ghostCoord[nrOfGhost].Col].hasGhost = true;
        direction.down = true;
        direction.right = true;
        direction.left = true;
        direction.up = false;
        if(licznik==4)
        {
            direction.up=true;
        }
        return;
    }
    if (direction.left == true && nr == 4) {
        ghostCoord[nrOfGhost].Col--;
        board[ghostCoord[nrOfGhost].Row][ghostCoord[nrOfGhost].Col].hasGhost = true;
        direction.up = true;
        direction.down = true;
        direction.left = true;
        direction.right = false;
        if(licznik==4)
        {
            direction.right=true;
        }
        return;
    }
    nr=rand()%4+1;
}


}

