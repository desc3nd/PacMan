//
// Created by Marcinek on 01.06.2020.
//

#ifndef PACMAN_PACSFMLGRAPHIC_H
#define PACMAN_PACSFMLGRAPHIC_H
#include<SFML/Graphics.hpp>
#include "PacBoard.h"
#include "PacGhosts.h"
#include "PacMan.h"
#include "PacGameMenager.h"

class PacSFMLGraphic: public sf::Drawable {
PacBoard &board;
PacMan &pacMan;
PacGhosts &ghosts;
int height;
int width;
int screenWidth;
int screenHeight;
void drawBoard();
sf::CircleShape points[100];
sf::CircleShape pacek;
sf::CircleShape ghostek[2];
sf::RectangleShape traps[1000];
sf::RectangleShape food[1000];

public:
    PacSFMLGraphic(PacBoard board, PacMan &pac, PacGhosts &ghost );
    int getScreenWidth();
    int getScreenHeight();
    void draw(sf::RenderTarget& target,sf::RenderStates states) const override;

};


#endif //PACMAN_PACSFMLGRAPHIC_H
