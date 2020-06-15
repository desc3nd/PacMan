
#include "PacSFMLGraphic.h"
#include<iostream>
#include<string>
PacSFMLGraphic::PacSFMLGraphic(PacBoard &Board, PacMan &pac, PacGhosts &ghost, PacGameMenager &menager):board(Board),pacMan(pac),ghosts(ghost),ctrl(menager) {
    width=board.getWidth();
    height=board.getHeight();
    screenHeight=680;
    screenWidth=600;
    numberOfFood=325;
    numberOfTraps=691;
    numberOfPremiumFood=5;
    numberOfGhosts=7;
    pacek.setRadius(5);
    if(!texture.loadFromFile("myPac.png")  || !texture2.loadFromFile("koniec.png") || !font.loadFromFile("arial.ttf"))
    {
        std::cerr<<"blad przy wczytaniu tekstury lub fontu";
    }
    drawMenu();

}

int PacSFMLGraphic::getScreenWidth() const{
    return screenWidth;
}

int PacSFMLGraphic::getScreenHeight() const {
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
    for(int i=0;i<numberOfPremiumFood;i++)
    {
        target.draw(premiumFood[i],states);
    }
    for(int i=0;i<numberOfGhosts;i++)
    {
        target.draw(ghostek[i],states);
    }
    target.draw(menu,states);
    target.draw(gameOver,states);
    target.draw(point);
}

void PacSFMLGraphic::drawBoard()
{
    int tempHeight=4;
    int tempWidth=5;
    int nrTraps=0;
     int nrFood=0;
     int prem=0;
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
            }
            if(board.getCharInfo(row,col)=='p')
            {
                premiumFood[prem].setRadius(5);
                premiumFood[prem].setPosition(sf::Vector2f(tempWidth,tempHeight));
                premiumFood[prem].setFillColor(sf::Color::Red);
                prem++;
            }
            if(pacMan.isPacman(row, col))
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
                if(ctrl.getEatableStatus())
                {
                    ghostek[0].setFillColor(sf::Color::Cyan);
                    ghostek[1].setFillColor(sf::Color::Cyan);
                    ghostek[2].setFillColor(sf::Color::Cyan);
                    ghostek[3].setFillColor(sf::Color::Cyan);
                    ghostek[4].setFillColor(sf::Color::Cyan);
                    ghostek[5].setFillColor(sf::Color::Cyan);
                    ghostek[6].setFillColor(sf::Color::Cyan);
                }
                if(nrGhostka>numberOfGhosts)
                {
                    nrGhostka=0;
                }
            } else{
                food[nrFood].setFillColor(sf::Color::Transparent);
                premiumFood[prem].setFillColor(sf::Color::Transparent);
            }

        tempWidth+=20;
        }
        tempWidth=5;
        tempHeight+=20;
    }
    gameOver.setSize(sf::Vector2f(0,0));
    point.setCharacterSize(0);
}

void PacSFMLGraphic::drawMenu() {
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
