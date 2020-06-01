//
// Created by Marcinek on 01.06.2020.
//

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
//    if(klawisz!='w' || klawisz!='a' || klawisz!='s' || klawisz!='d' )
//    {
//        return;
//    }

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

    board[pacCoord.Row][pacCoord.Col].hasPacman=true;

}

void PacMan::DebugDisplayPac() {
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

bool PacMan::getCharInfo(int row, int col) {
   if(board[row][col].hasPacman)
   {
       return true;
   }
   return false;
}
