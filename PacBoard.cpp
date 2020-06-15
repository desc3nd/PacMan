
#include<iostream>
#include "PacBoard.h"
#include <fstream>
#include <iostream>
#include<string>
PacBoard::PacBoard()
{
    height=34;
    width=30;
     std::ifstream plikPlansza;
     plikPlansza.open("plansza.txt" );
     if( !plikPlansza.good() )
     {
         std::cerr<<"blad czytania planszy";
     }
     char gwiazdkaKropka;

     for(int row=0; row<height; row++)
     {
         for(int col=0; col<=width;col++)
         {
             plikPlansza.get(gwiazdkaKropka);
             if(gwiazdkaKropka=='*')
             {
                 board[row][col].hasTrap=true;
             }
            if(gwiazdkaKropka=='.' || gwiazdkaKropka=='\n')
             {
                 board[row][col].hasTrap=false;
             }
         }
     }
     plikPlansza.close();
     placeFoodOnBoard();
     board[15][1].hasFood=false;
     board[15][28].hasFood=false;
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
char PacBoard::getCharInfo(int x, int y) const {
    if(board[x][y].hasTrap)
    {
        return'*';
    }
    if(board[x][y].hasPremiumFood)
    {
        return 'p';
    }
    if(board[x][y].hasFood)
    {
        return 'f';
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
board[32][1].hasPremiumFood=true;
board[32][28].hasPremiumFood=true;
board[8][1].hasPremiumFood=true;
board[8][28].hasPremiumFood=true;
}

void PacBoard::setFoodFalse(int row, int col) {
    board[row][col].hasFood=false;
    board[15][1].hasFood=false;
    board[15][28].hasFood=false;
}

void PacBoard::DefaultSettings() {
    placeFoodOnBoard();
}

void PacBoard::setPremiumFoodFalse(int row,int col) {
    board[row][col].hasPremiumFood=false;

}
