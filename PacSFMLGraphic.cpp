//
// Created by Marcinek on 01.06.2020.
//

#include "PacSFMLGraphic.h"
#include<iostream>
#include<string>
PacSFMLGraphic::PacSFMLGraphic(PacBoard &Board, PacMan &pac, PacGhosts &ghost, PacGameMenager &menager):board(Board),pacMan(pac),ghosts(ghost),ctrl(menager) {
    width=board.getWidth();
    height=board.getHeight();
    screenHeight=680;
    screenWidth=600;
    numberOfFood=330;
    numberOfTraps=686;
    pacek.setRadius(5);
    if(!texture.loadFromFile("myPac.png")  || !texture2.loadFromFile("koniec.png") || !font.loadFromFile("arial.ttf"))
    {
        std::cerr<<"blad przy wczytaniu tekstury lub fontu";
    }
   // drawBoard();
    drawMenu();

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
    for(int i=0; i<numberOfFood;i++)
    {
        target.draw(food[i]);
    }
    target.draw(ghostek[0],states);
    target.draw(ghostek[1],states);
    target.draw(ghostek[2],states);
    target.draw(ghostek[3],states);
    target.draw(ghostek[4],states);
    target.draw(ghostek[5],states);
    target.draw(ghostek[6],states);
    target.draw(menu,states);
    target.draw(gameOver,states);

    target.draw(point);
}

void PacSFMLGraphic::drawBoard()
{
    int tempHeight=10;
    int tempWidth=3;
    int nrTraps=0;
   int nrFood=0;
    int nrGhostka=0;
    menu.setSize(sf::Vector2f(0,0));
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {

            if (board.getCharInfo(row, col)=='*')
            {
                traps[nrTraps].setSize(sf::Vector2f(10,10));
                traps[nrTraps].setPosition(sf::Vector2f(tempWidth,tempHeight));
                traps[nrTraps].setFillColor(sf::Color::White);
                nrTraps++;
            }
            if(board.getCharInfo(row,col)=='f')
            {
                food[nrFood].setSize(sf::Vector2f(3,3));
                food[nrFood].setPosition(sf::Vector2f(tempWidth+2,tempHeight+5));
                food[nrFood].setFillColor(sf::Color::Magenta);
                nrFood++;
                for(int i=nrFood;i<numberOfFood;i++)
                {
                    food[i].setFillColor(sf::Color::Black);
                    food[i].setPosition(sf::Vector2f(tempWidth+2,tempHeight+5));
                }
            }

            if(pacMan.getCharInfo(row,col))
            {
                pacek.setRadius(8);
                pacek.setPosition(sf::Vector2f(tempWidth-2,tempHeight-5));
                pacek.setFillColor(sf::Color::Yellow);
                food[nrFood].setFillColor(sf::Color::Black);
            }
            if(ghosts.isGhost(row,col))
            {
                ghostek[nrGhostka].setRadius(8);
                ghostek[nrGhostka].setPosition(sf::Vector2f(tempWidth-2,tempHeight-5));
                ghostek[nrGhostka].setFillColor(sf::Color::Blue);
                nrGhostka++;
                if(nrGhostka>7)
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
    gameOver.setSize(sf::Vector2f(0,0));
    point.setCharacterSize(0);
}

void PacSFMLGraphic::drawMenu() {
//menu.setPosition(0,0);
menu.setSize(sf::Vector2f(600,680));
    menu.setTexture(&texture);
}

void PacSFMLGraphic::drawGameOver() {
   gameOver.setPosition(0,0);
    gameOver.setSize(sf::Vector2f(610,680));
    gameOver.setTexture(&texture2);
    drawPoints();


}

void PacSFMLGraphic::drawPoints() {
    point.setFont(font);
    point.setFillColor(sf::Color::White);
    point.setCharacterSize(40);
    point.setPosition(sf::Vector2f(290,500));
    int outcome=ctrl.getPoints();
    std::string str= std::to_string(outcome);
    point.setString(str);

}
