

#ifndef PACMAN_PACSFMLEVENT_H
#define PACMAN_PACSFMLEVENT_H
#include "PacMan.h"
#include "PacSFMLGraphic.h"

class PacSFMLEvent
{
    PacMan &pacman;
    PacSFMLGraphic &graphic;
    char move;
    bool enter;
    bool again;

public:
    PacSFMLEvent(PacSFMLGraphic &graph, PacMan &pac);
    void PacManMove();
    void SelfMove();
    void startGame();
    bool getEnterStatus() const;
    bool getAgainStatus() const;
    void restart();
    void DefaultSettings();
};


#endif //PACMAN_PACSFMLEVENT_H
