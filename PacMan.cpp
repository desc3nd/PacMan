
#include "PacMan.h"
#include<iostream>

PacMan::PacMan(PacBoard &x):tab(x) {
    pacCoord.Col=15;
    pacCoord.Row=21;
    board[pacCoord.Row][pacCoord.Col].hasPacman=true;
    width=tab.getWidth();
    height=tab.getHeight();


}

void PacMan::PacMovement(char klawisz)
{

board[pacCoord.Row][pacCoord.Col].hasPacman=false;

    if(klawisz=='w')
    {
        if(tab.getCharInfo(pacCoord.Row-1,pacCoord.Col)=='*')
        {
            board[pacCoord.Row][pacCoord.Col].hasPacman=true;
            return;
        }
        pacCoord.Row--;
    }
    if(klawisz=='a')
    {
        if(tab.getCharInfo(pacCoord.Row,pacCoord.Col-1)=='*')
        {
            board[pacCoord.Row][pacCoord.Col].hasPacman=true;
            return;
        }
        pacCoord.Col--;
    }
    if(klawisz=='s')
    {
        if(tab.getCharInfo(pacCoord.Row+1,pacCoord.Col)=='*')
        {
            board[pacCoord.Row][pacCoord.Col].hasPacman=true;
            return;
        }
        pacCoord.Row++;
    }
    if(klawisz=='d')
    {
        if(tab.getCharInfo(pacCoord.Row,pacCoord.Col+1)=='*')
        {
            board[pacCoord.Row][pacCoord.Col].hasPacman=true;
            return;
        }
        pacCoord.Col++;
    }
    tp();
    board[pacCoord.Row][pacCoord.Col].hasPacman=true;

}

void PacMan::DebugDisplayPac() const {
    for(int row=0; row<width;row++)
    {
        for( int col=0; col<height; col++)
        {
            if(board[row][col].hasPacman)
            {
                std::cout<<"M";
            }
            else{std::cout<<"_";}
        }
    std::cout<<std::endl;
    }
}

bool PacMan::isPacman(int row, int col) const {
   if(board[row][col].hasPacman)
   {
       return true;
   }
   return false;
}
void PacMan::tp() {
    if(pacCoord.Row==15 && pacCoord.Col==1)
    {
        pacCoord.Row=15;
        pacCoord.Col=27;
    }
    if(pacCoord.Row==15 && pacCoord.Col==28)
    {
        pacCoord.Row=15;
        pacCoord.Col=2;
    }


}

void PacMan::DefaultSettings() {
    board[pacCoord.Row][pacCoord.Col].hasPacman=false;
    pacCoord.Col=15;
    pacCoord.Row=21;
    board[pacCoord.Row][pacCoord.Col].hasPacman=true;

}

