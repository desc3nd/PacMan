//
// Created by Marcinek on 01.06.2020.
//

#ifndef LOL_PACVIEW_H
#define LOL_PACVIEW_H

#include "PacMan.h"
#include "PacGhosts.h"
#include "PacBoard.h"

class PacView {
    int height;
    int width;
    PacMan &pacMan;
    PacBoard &pacBoard;
    PacGhosts &pacGhosts;
public:
PacView(PacMan &pac, PacGhosts &ghosts, PacBoard &board);
void Display();
};


#endif //LOL_PACVIEW_H
