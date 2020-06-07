//
// Created by Marcinek on 05.06.2020.
//

#ifndef PACMAN_PACSFMLEVENT_H
#define PACMAN_PACSFMLEVENT_H
#include "PacMan.h"
#include "PacSFMLGraphic.h"

class PacSFMLEvent {
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
    bool getEnterStatus();
    bool getAgainStatus();
    void restart();
    void DefaultSettings();
};


#endif //PACMAN_PACSFMLEVENT_H
