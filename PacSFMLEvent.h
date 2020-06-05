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
public:
    PacSFMLEvent(PacSFMLGraphic &graph, PacMan &pac);
    void PacManMove();
    void SelfMove();
};


#endif //PACMAN_PACSFMLEVENT_H
