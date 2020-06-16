

#include "PacGhosts.h"
#include<cstdlib>
#include<time.h>
#include <iostream>
PacGhosts::PacGhosts(PacBoard &x):tab(x)
{
    loop=0;
    amountOfGhosts=6;
    height=tab.getHeight();
    width=tab.getWidth();
    for(int i=0; i < amountOfGhosts; i++)
    {
        width=tab.getWidth();
        height=tab.getHeight();
        direction[i].up=true;
        direction[i].down=true;
        direction[i].right=true;
        direction[i].left=true;
        licznik[i]=1;
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
    ghostCoord[5].Row=32;
    ghostCoord[5].Col=15;
    board[ghostCoord[0].Row][ghostCoord[0].Col].hasGhost=true;
    board[ghostCoord[1].Row][ghostCoord[1].Col].hasGhost=true;
    board[ghostCoord[2].Row][ghostCoord[2].Col].hasGhost=true;
    board[ghostCoord[3].Row][ghostCoord[3].Col].hasGhost=true;
    board[ghostCoord[4].Row][ghostCoord[4].Col].hasGhost=true;
    board[ghostCoord[5].Row][ghostCoord[5].Col].hasGhost=true;
}

void PacGhosts::checkDirection(int nrOfGhost)
{

    if(loop>1)
    {
        loop=0;
        if(tab.getCharInfo(ghostCoord[nrOfGhost].Row,ghostCoord[nrOfGhost].Col-1)=='*')
        {
            direction[nrOfGhost].left=false;
        }
        if(tab.getCharInfo(ghostCoord[nrOfGhost].Row,ghostCoord[nrOfGhost].Col+1)=='*')
        {
            direction[nrOfGhost].right=false;
        }
        if(tab.getCharInfo(ghostCoord[nrOfGhost].Row+1,ghostCoord[nrOfGhost].Col)=='*')
        {
            direction[nrOfGhost].down=false;
        }
        if(tab.getCharInfo(ghostCoord[nrOfGhost].Row-1,ghostCoord[nrOfGhost].Col)=='*')
        {
            direction[nrOfGhost].up=false;
        }
        return;
    }

    if(nrOfGhost < 0 || nrOfGhost>=7)
    {
        return;
    }
    if(licznik[nrOfGhost]>=4)
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
   if(licznik[nrOfGhost]>=4)
    {
       direction[nrOfGhost].left=true;
       direction[nrOfGhost].right=true;
       direction[nrOfGhost].down=true;
       direction[nrOfGhost].up=true;
       loop++;
       checkDirection(nrOfGhost);
    }

}

bool PacGhosts::isGhost(int row,int col) const
{
    if(row<0 || col<0 || col>=width  || row>=height)
    {
        std::cerr<<"blad w podanych parametrach przy isghosts";
        return false;
    }
 if(board[row][col].hasGhost)
 {
     return true;
 }
 return false;
}

void PacGhosts::ghostMove(int nrOfGhost )
{
    board[ghostCoord[nrOfGhost].Row][ghostCoord[nrOfGhost].Col].hasGhost = false;
    checkDirection(nrOfGhost);
   if(licznik[nrOfGhost]>=5)
   {
       return;
   }
while(true)
{
    nr=rand()%4+1;
    board[ghostCoord[nrOfGhost].Row][ghostCoord[nrOfGhost].Col].hasGhost = false;
    if (direction[nrOfGhost].up == true && nr == 1)
    {
        ghostCoord[nrOfGhost].Row--;
        board[ghostCoord[nrOfGhost].Row][ghostCoord[nrOfGhost].Col].hasGhost = true;
        tp(nrOfGhost);
        direction[nrOfGhost].up = true;
        direction[nrOfGhost].right = true;
        direction[nrOfGhost].left = true;
        direction[nrOfGhost].down = false;
        return;
    }
    if (direction[nrOfGhost].right == true && nr == 2)
    {
        ghostCoord[nrOfGhost].Col++;
        board[ghostCoord[nrOfGhost].Row][ghostCoord[nrOfGhost].Col].hasGhost = true;
        tp(nrOfGhost);
        direction[nrOfGhost].up = true;
        direction[nrOfGhost].right = true;
        direction[nrOfGhost].down = true;
        direction[nrOfGhost].left = false;
        return;

    }
    if (direction[nrOfGhost].down == true && nr == 3)
    {
        ghostCoord[nrOfGhost].Row++;
        board[ghostCoord[nrOfGhost].Row][ghostCoord[nrOfGhost].Col].hasGhost = true;
        tp(nrOfGhost);
        direction[nrOfGhost].down = true;
        direction[nrOfGhost].right = true;
        direction[nrOfGhost].left = true;
        direction[nrOfGhost].up = false;
        return;
    }
    if (direction[nrOfGhost].left == true && nr == 4)
    {
        ghostCoord[nrOfGhost].Col--;
        board[ghostCoord[nrOfGhost].Row][ghostCoord[nrOfGhost].Col].hasGhost = true;
        tp(nrOfGhost);
        direction[nrOfGhost].up = true;
        direction[nrOfGhost].down = true;
        direction[nrOfGhost].left = true;
        direction[nrOfGhost].right = false;
        return;
    }
}


}

void PacGhosts::tp(int nrOfGhost)
{
    if(board[15][1].hasGhost)
    {
        board[15][1].hasGhost=false;
        ghostCoord[nrOfGhost].Row=15;
        ghostCoord[nrOfGhost].Col=28;

    }
    if(board[15][28].hasGhost)
    {
        board[15][28].hasGhost=false;
        ghostCoord[nrOfGhost].Row=15;
        ghostCoord[nrOfGhost].Col=1;
    }


}
//
//void PacGhosts::checkLicznik(int nrOfGhost) {
//    if(licznik[nrOfGhost]==4)
//    {
//        direction[nrOfGhost].left=true;
//        direction[nrOfGhost].right=true;
//        direction[nrOfGhost].down=true;
//        direction[nrOfGhost].up=true;
//        checkDirection(nrOfGhost);
//    }
//
//}

void PacGhosts::DefaultSettings()
{

    for(int i=0; i < amountOfGhosts; i++)
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
    ghostCoord[5].Row=32;
    ghostCoord[5].Col=15;
    for(int i=0; i < amountOfGhosts; i++)
    {
        direction[i].up=true;
        direction[i].down=true;
        direction[i].right=true;
        direction[i].left=true;
        licznik[i]=1;
        board[ghostCoord[i].Row][ghostCoord[i].Col].hasGhost=true;

    }

}

void PacGhosts::DebugGhost() const
{
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

int PacGhosts::getAmountOfGhosts() const
{
    return amountOfGhosts;
}

