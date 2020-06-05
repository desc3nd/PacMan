//
// Created by Marcinek on 05.06.2020.
//

#include "PacSFMLEvent.h"

PacSFMLEvent::PacSFMLEvent(PacSFMLGraphic &graph, PacMan &pac) :pacman(pac),graphic(graph)
{

}

void PacSFMLEvent::PacManMove() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        move='w';
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        move='s';
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        move='d';
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        move='a';
    }

}

void PacSFMLEvent::SelfMove() {
  pacman.PacMovement(move);

}

