//
// Created by Marcinek on 01.06.2020.
//

#ifndef PACMAN_PACSFMLGRAPHIC_H
#define PACMAN_PACSFMLGRAPHIC_H
#include<SFML/Graphics.hpp>
#include "PacBoard.h"
#include "PacGhosts.h"
#include "PacMan.h"


class PacSFMLGraphic: public sf::Drawable {
PacBoard &board;
PacMan &pacMan;
PacGhosts &ghosts;
int height;
int width;
int screenWidth;
int screenHeight;
int numberOfFood;
int numberOfTraps;

sf::CircleShape points[100];
sf::CircleShape pacek;
sf::CircleShape ghostek[10];
sf::RectangleShape traps[700];
sf::RectangleShape food[1000];

public:
    PacSFMLGraphic(PacBoard &board, PacMan &pac, PacGhosts &ghost );
    int getScreenWidth();
    int getScreenHeight();
    void draw(sf::RenderTarget& target,sf::RenderStates states) const override;
    void drawBoard();
};


#endif //PACMAN_PACSFMLGRAPHIC_H
