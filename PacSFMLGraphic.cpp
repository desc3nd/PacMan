//
// Created by Marcinek on 01.06.2020.
//

#include "PacSFMLGraphic.h"
#include<iostream>
PacSFMLGraphic::PacSFMLGraphic(PacBoard &Board, PacMan &pac, PacGhosts &ghost):board(Board),pacMan(pac),ghosts(ghost) {
    width=board.getWidth();
    height=board.getHeight();
    screenHeight=900;
    screenWidth=800;
    numberOfFood=330;
    numberOfTraps=686;
    pacek.setRadius(5);
    drawBoard();

}

int PacSFMLGraphic::getScreenWidth() {
    return screenWidth;
}

int PacSFMLGraphic::getScreenHeight() {
    return screenHeight;
}

void PacSFMLGraphic::draw(sf::RenderTarget &target, sf::RenderStates states) const {
target.draw(pacek);
for(int i=0;i<numberOfTraps;i++)
{
    target.draw(traps[i],states);
}

    target.draw(ghostek[0],states);
    target.draw(ghostek[1],states);
    target.draw(ghostek[2],states);
    target.draw(ghostek[3],states);
    for(int i=0; i<numberOfFood;i++)
    {
        target.draw(food[i]);
    }
}

void PacSFMLGraphic::drawBoard()
{
    int tempHeight=10;
    int tempWidth=3;
    int nrTraps=0;
   int nrFood=0;
    int nrGhostka=0;
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {

            if (board.getCharInfo(row, col)=='*')
            {
                traps[nrTraps].setSize(sf::Vector2f(3,3));
                traps[nrTraps].setPosition(sf::Vector2f(tempWidth,tempHeight));
                traps[nrTraps].setFillColor(sf::Color::White);
                nrTraps++;
            }
            if(board.getCharInfo(row,col)=='f')
            {
                food[nrFood].setSize(sf::Vector2f(1,1));
                food[nrFood].setPosition(sf::Vector2f(tempWidth,tempHeight));
                food[nrFood].setFillColor(sf::Color::Magenta);
                nrFood++;
                for(int i=nrFood;i<numberOfFood;i++)
                {
                    food[i].setFillColor(sf::Color::Black);
                    food[i].setPosition(sf::Vector2f(tempWidth,tempHeight));
                }
            }

            if(pacMan.getCharInfo(row,col))
            {
                pacek.setRadius(5);
                pacek.setPosition(sf::Vector2f(tempWidth,tempHeight));
                pacek.setFillColor(sf::Color::Yellow);
                food[nrFood].setFillColor(sf::Color::Black);
            }
            if(ghosts.isGhost(row,col))
            {
                ghostek[nrGhostka].setRadius(5);
                ghostek[nrGhostka].setPosition(sf::Vector2f(tempWidth,tempHeight));
                ghostek[nrGhostka].setFillColor(sf::Color::Blue);
                nrGhostka++;
                if(nrGhostka>4)
                {
                    nrGhostka=0;
                }
            }

        tempWidth+=20;
        }
        tempWidth=10;
        tempHeight+=20;
    }

    std::cout<<std::endl<<nrFood<<std::endl;
}