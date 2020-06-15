
#include "PacView.h"
#include<iostream>
PacView::PacView(PacMan &pac, PacGhosts &ghosts, PacBoard &board) :pacMan(pac),pacBoard(board),pacGhosts(ghosts)
{
    height=pacBoard.getHeight();
    width=pacBoard.getWidth();

}

void PacView::Display() const{
    for(int row=0; row<height; row++)
    {
        for(int col=0; col<width; col++)
        {
            if(pacBoard.getCharInfo(row,col)=='*')
            {
                std::cout<<"*";
            }
            if(pacBoard.getCharInfo(row,col)=='f')
            {
                std::cout<<"F ";
            }
            if(pacMan.isPacman(row, col))
            {
                std::cout<<"M";
            }
            if(pacGhosts.isGhost(row,col))
            {
                std::cout<<"G";
            }
        }
        std::cout<<std::endl;
    }

}
