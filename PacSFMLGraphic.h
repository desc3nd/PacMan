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

class PacSFMLGraphic: public sf::Drawable
{
PacBoard &board;
PacMan &pacMan;
PacGhosts &ghosts;
PacGameMenager &ctrl;
int height;
int width;
int screenWidth;
int screenHeight;
int numberOfFood;
int numberOfTraps;
int numberOfPremiumFood;
int numberOfGhosts;
sf::Texture texture;
sf::Texture texture2;
sf::Font font;
sf::Text point;
sf::RectangleShape menu;
sf::RectangleShape gameOver;
sf::CircleShape pacek;
sf::CircleShape ghostek[8];
sf::RectangleShape traps[692];
sf::RectangleShape food[333];
sf::CircleShape tp[1];
sf::CircleShape premiumFood[10];
void drawPoints();

public:
    PacSFMLGraphic(PacBoard &board, PacMan &pac, PacGhosts &ghost, PacGameMenager &menager );
    int getScreenWidth() const;
    int getScreenHeight() const;
    void draw(sf::RenderTarget& target,sf::RenderStates states) const override;
    void drawBoard();
    void drawMenu();
    void drawGameOver();
    void drawTP();
};


#endif //PACMAN_PACSFMLGRAPHIC_H
