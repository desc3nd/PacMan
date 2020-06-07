//
// Created by Marcinek on 31.05.2020.
//
#include<iostream>
#include "PacBoard.h"

PacBoard::PacBoard() //(40szerokosc 30 wys
 {
height=34;//32
width=30;
for(int col=0;col<30;col++)
{
    board[0][col].hasTrap=true;
    board[33][col].hasTrap=true;
}
for(int row=0;row<34;row++) {
    board[row][0].hasTrap = true;
    board[row][29].hasTrap = true;
}
for_draw(2,2,8,7);
for_draw(2,8,5,11);
for_draw(2,12,5,18);
for_draw(2,19,5,22);
for_draw(2,23,8,28);
for_draw(6,8,7,22);
for_draw(8,10,9,20);
for_draw(6,8,9,9);
for_draw(6,21,9,22);
for_draw(9,0,14,5);
for_draw(10,6,21,9);
for_draw(10,10,21,20);
for_draw(10,21,21,24);
for_draw(9,25,14,29);
for_draw(15,25,16,27);
for_draw(14,28,15,29);
for_draw(15,3,16,5);
for_draw(14,0,15,2);
for_draw(16,0,21,5);
for_draw(16,25,21,29);
for_draw(22,2,25,12);
for_draw(22,13,27,17);
for_draw(22,18,25,28);
for_draw(26,8,30,12);
for_draw(28,12,30,18);
for_draw(26,18,30,22);
for_draw(26,5,27,9);
for_draw(26,22,27,25);
for_draw(28,5,30,7);
for_draw(28,23,30,25);
for_draw(31,4,32,26);
for_draw(26,3,30,4);
for_draw(26,2,32,3);
for_draw(26,26,30,27);
for_draw(26,27,32,28);
placeFoodOnBoard();
//erase(11,11,20,19);
erase(10,13,11,17);
}

void PacBoard::Debug_Display() const {
    int food=0;
    int traps=0;
    for(int row=0; row<height; row++)
    {
        for(int col=0; col<width; col++)
        {
            if(board[row][col].hasTrap)
            {
                std::cout<<"*";
                traps++;
            }
            if(board[row][col].hasFood)
            {
                std::cout<<"fo";
                food++;
            }
            else
                std::cout<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<food<<std::endl;
    std::cout<<traps<<std::endl;
}

int PacBoard::getWidth() const {
    return width;
}

int PacBoard::getHeight() const {
    return height;
}

void PacBoard::for_draw(int row, int col, int rowKoniec, int colKoniec) {
    for(int x=row; x<rowKoniec;x++)
    {
        for(int y=col; y<colKoniec;y++)
        {
            board[x][y].hasTrap=true;
        }

    }

}

void PacBoard::erase(int row, int col, int rowKoniec, int colKoniec) {
    for(int x=row; x<rowKoniec;x++)
    {
        for(int y=col; y<colKoniec;y++)
        {
            board[x][y].hasTrap=false;
            board[x][y].hasFood=false;
        }

    }

}
char PacBoard::getCharInfo(int x, int y) {
    if(board[x][y].hasTrap)
    {
        return'*';
    }
    if(board[x][y].hasFood)
    {
        return 'f';
    }
    if(board[x][y].hasPremiumFood)
    {
        return 'p';
    }
    if(!board[x][y].isEmpty)
    {
        return'_';
    }
    return'_';
}

void PacBoard::placeFoodOnBoard() {
    for(int row=0;row<height;row++)
    {
        for(int col=0;col<width;col++)
        {
            if(!board[row][col].hasTrap)
            {
                board[row][col].hasFood=true;
            }

        }
    }


}

void PacBoard::setFoodFalse(int row, int col) {
    board[row][col].hasFood=false;

}
