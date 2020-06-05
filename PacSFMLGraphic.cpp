//
// Created by Marcinek on 01.06.2020.
//

#include "PacSFMLGraphic.h"

PacSFMLGraphic::PacSFMLGraphic(PacBoard Board, PacMan &pac, PacGhosts &ghost):board(Board),pacMan(pac),ghosts(ghost) {
    width=board.getWidth();
    height=board.getHeight();
    screenHeight=680;
    screenWidth=600;
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
for(const auto & trap : traps)
{
    target.draw(trap,states);
}
    for(int i=0; i<1000;i++)
    {
        target.draw(food[i]);
    }
    target.draw(ghostek[0],states);
    target.draw(ghostek[1],states);
    target.draw(ghostek[2],states);
//    target.draw(ghostek[3],states);
//    target.draw(ghostek[4],states);
}

void PacSFMLGraphic::drawBoard()
{
    int tempHeight=10;
    int tempWidth=3;
    int i=0;
    int foodNumber=0;
    int nrGhostka=0;
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {

            if (board.getCharInfo(row, col)=='*')
            {
                traps[i].setSize(sf::Vector2f(3,3));
                traps[i].setPosition(sf::Vector2f(tempWidth,tempHeight));
                traps[i].setFillColor(sf::Color::White);
                i++;
            }
            if(board.getCharInfo(row,col)=='f')
            {
                food[foodNumber].setSize(sf::Vector2f(1,1));
                food[foodNumber].setPosition(sf::Vector2f(tempWidth,tempHeight));
                food[foodNumber].setFillColor(sf::Color::Magenta);
                foodNumber++;
            }
            if(pacMan.getCharInfo(row,col))
            {
                pacek.setRadius(5);
                pacek.setPosition(sf::Vector2f(tempWidth,tempHeight));
                pacek.setFillColor(sf::Color::Yellow);
            }
            if(ghosts.isGhost(row,col))
            {
                ghostek[nrGhostka].setRadius(5);
                ghostek[nrGhostka].setPosition(sf::Vector2f(tempWidth,tempHeight));
                ghostek[nrGhostka].setFillColor(sf::Color::Blue);
                nrGhostka++;
                if(nrGhostka>3)
                {
                    nrGhostka=0;
                }
            }
        tempWidth+=20;
        }
        tempWidth=10;
        tempHeight+=20;

    }


}