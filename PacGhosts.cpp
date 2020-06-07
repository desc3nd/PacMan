//
// Created by Marcinek on 01.06.2020.
//

#include "PacGhosts.h"
#include<cstdlib>
#include<time.h>
#include <iostream>
PacGhosts::PacGhosts(PacBoard &x):tab(x) {
for(int i=0;i<7;i++)
{
    width=tab.getWidth();
    height=tab.getHeight();
    direction[i].up=true;
    direction[i].down=true;
    direction[i].right=true;
    direction[i].left=true;
    licznik[i]=1;
}
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
    ghostCoord[4].Row=27;
    ghostCoord[4].Col=16;
    ghostCoord[5].Row=32;
    ghostCoord[5].Col=15;
    nr=rand()%4+1;
  board[ghostCoord[0].Row][ghostCoord[0].Col].hasGhost=true;
   board[ghostCoord[1].Row][ghostCoord[1].Col].hasGhost=true;
   board[ghostCoord[2].Row][ghostCoord[2].Col].hasGhost=true;
   board[ghostCoord[3].Row][ghostCoord[3].Col].hasGhost=true;
    board[ghostCoord[4].Row][ghostCoord[4].Col].hasGhost=true;
    board[ghostCoord[5].Row][ghostCoord[5].Col].hasGhost=true;



}

void PacGhosts::ghostsMovement(int nrOfGhost) {
    if(licznik[nrOfGhost]==4)
    {
        licznik[nrOfGhost]=0;
    }
    else
    {
        licznik[nrOfGhost]=1;
    }

   if(tab.getCharInfo(ghostCoord[nrOfGhost].Row,ghostCoord[nrOfGhost].Col-1)=='*' || board[ghostCoord[nrOfGhost].Row][ghostCoord[nrOfGhost].Col-1].hasGhost)
   {
    direction[nrOfGhost].left=false;
    licznik[nrOfGhost]++;
   }
 if(tab.getCharInfo(ghostCoord[nrOfGhost].Row,ghostCoord[nrOfGhost].Col+1)=='*'||  board[ghostCoord[nrOfGhost].Row][ghostCoord[nrOfGhost].Col+1].hasGhost)
   {
       direction[nrOfGhost].right=false;
       licznik[nrOfGhost]++;
   }
   if(tab.getCharInfo(ghostCoord[nrOfGhost].Row+1,ghostCoord[nrOfGhost].Col)=='*' ||  board[ghostCoord[nrOfGhost].Row +1][ghostCoord[nrOfGhost].Col].hasGhost)
    {
        direction[nrOfGhost].down=false;
        licznik[nrOfGhost]++;
    }
   if(tab.getCharInfo(ghostCoord[nrOfGhost].Row-1,ghostCoord[nrOfGhost].Col)=='*'||  board[ghostCoord[nrOfGhost].Row -1][ghostCoord[nrOfGhost].Col].hasGhost)
    {
        direction[nrOfGhost].up=false;
        licznik[nrOfGhost]++;
    }
   if(licznik[nrOfGhost]==4)
   {
       direction[nrOfGhost].left=true;
       direction[nrOfGhost].right=true;
       direction[nrOfGhost].down=true;
       direction[nrOfGhost].up=true;
       ghostsMovement(nrOfGhost);
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
   if(licznik[nrOfGhost]>=5)
   {
       return;
   }
       srand(time(nullptr));

while(true) {
    nr=rand()%4+1;
    board[ghostCoord[nrOfGhost].Row][ghostCoord[nrOfGhost].Col].hasGhost = false;
    if (direction[nrOfGhost].up == true && nr == 1) {
        ghostCoord[nrOfGhost].Row--;
        board[ghostCoord[nrOfGhost].Row][ghostCoord[nrOfGhost].Col].hasGhost = true;
        tp(nrOfGhost);
        direction[nrOfGhost].up = true;
        direction[nrOfGhost].right = true;
        direction[nrOfGhost].left = true;
        direction[nrOfGhost].down = false;
        if(licznik[nrOfGhost]==4)
        {
            direction[nrOfGhost].down=true;
        }
        return;
    }
    if (direction[nrOfGhost].right == true && nr == 2) {
        ghostCoord[nrOfGhost].Col++;
        board[ghostCoord[nrOfGhost].Row][ghostCoord[nrOfGhost].Col].hasGhost = true;
      tp(nrOfGhost);
        direction[nrOfGhost].up = true;
        direction[nrOfGhost].right = true;
        direction[nrOfGhost].down = true;
        direction[nrOfGhost].left = false;
        if(licznik[nrOfGhost]==4)
        {
            direction[nrOfGhost].left=true;
        }
        return;

    }
    if (direction[nrOfGhost].down == true && nr == 3) {
        ghostCoord[nrOfGhost].Row++;
        board[ghostCoord[nrOfGhost].Row][ghostCoord[nrOfGhost].Col].hasGhost = true;
        tp(nrOfGhost);
        direction[nrOfGhost].down = true;
        direction[nrOfGhost].right = true;
        direction[nrOfGhost].left = true;
        direction[nrOfGhost].up = false;
        if(licznik[nrOfGhost]==4)
        {
            direction[nrOfGhost].up=true;
        }
        return;
    }
    if (direction[nrOfGhost].left == true && nr == 4) {
        ghostCoord[nrOfGhost].Col--;
        board[ghostCoord[nrOfGhost].Row][ghostCoord[nrOfGhost].Col].hasGhost = true;
       tp(nrOfGhost);
        direction[nrOfGhost].up = true;
        direction[nrOfGhost].down = true;
        direction[nrOfGhost].left = true;
        direction[nrOfGhost].right = false;
        if(licznik[nrOfGhost]==4)
        {
            direction[nrOfGhost].right=true;
        }
        return;
    }
}


}

void PacGhosts::tp(int nrOfGhost) {
    if(board[15][0].hasGhost)
    {
        board[15][0].hasGhost=false;
        ghostCoord[nrOfGhost].Row=15;
        ghostCoord[nrOfGhost].Col=28;

    }
    if(board[15][29].hasGhost)
    {
        board[15][29].hasGhost=false;
        ghostCoord[nrOfGhost].Row=15;
        ghostCoord[nrOfGhost].Col=1;
    }


}

void PacGhosts::checkLicznik(int nrOfGhost) {
    if(licznik[nrOfGhost]==4)
    {
        direction[nrOfGhost].left=true;
        direction[nrOfGhost].right=true;
        direction[nrOfGhost].down=true;
        direction[nrOfGhost].up=true;
        ghostsMovement(nrOfGhost);
    }

}

void PacGhosts::DefaultSettings() {

    for(int i=0;i<5;i++)
    {
        board[ghostCoord[i].Row][ghostCoord[i].Col].hasGhost=false;
    }

    ghostCoord[0].Row=16;
    ghostCoord[0].Col=5;
    ghostCoord[1].Row=16;
    ghostCoord[1].Col=24;
    ghostCoord[2].Row=10;
    ghostCoord[2].Col=15;
    ghostCoord[3].Row=1;
    ghostCoord[3].Col=15;
    ghostCoord[4].Row=27;
    ghostCoord[4].Col=16;
    for(int i=0;i<4;i++)
    {
        direction[i].up=true;
        direction[i].down=true;
        direction[i].right=true;
        direction[i].left=true;
        licznik[i]=1;
        board[ghostCoord[i].Row][ghostCoord[i].Col].hasGhost=true;

    }

}

void PacGhosts::DebugGhost() {
    for(int row=0;row<height;row++)
    {
        for(int col=0;col<width;col++)
        {
            if(board[row][col].hasGhost)
            {
                std::cout<<"G";
            }
            else{
                std::cout<<"_";
            }
        }
        std::cout<<std::endl;
    }

}

