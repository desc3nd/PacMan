//
// Created by Marcinek on 01.06.2020.
//

#include "PacView.h"
#include<iostream>
PacView::PacView(PacMan &pac, PacGhosts &ghosts, PacBoard &board) :pacMan(pac),pacBoard(board),pacGhosts(ghosts)
{
    height=pacBoard.getHeight();
    width=pacBoard.getWidth();

}

void PacView::Display() {
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
                std::cout<<" ";
            }
            if(pacMan.getCharInfo(row,col))
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
