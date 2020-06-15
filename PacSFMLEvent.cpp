
#include "PacSFMLEvent.h"

PacSFMLEvent::PacSFMLEvent(PacSFMLGraphic &graph, PacMan &pac) :pacman(pac),graphic(graph)
{
enter=false;
again=false;
}

void PacSFMLEvent::PacManMove()
{
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

void PacSFMLEvent::SelfMove()
{
    PacManMove();
  pacman.PacMovement(move);

}

void PacSFMLEvent::startGame()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        enter=true;
    }

}

bool PacSFMLEvent::getEnterStatus() const
{
    return enter;
}

bool PacSFMLEvent::getAgainStatus() const
{
    return again;
}

void PacSFMLEvent::restart()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        again=true;
    }

}

void PacSFMLEvent::DefaultSettings()
{
    again=false;
}

