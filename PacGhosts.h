//
// Created by Marcinek on 01.06.2020.
//

#ifndef LOL_PACGHOSTS_H
#define LOL_PACGHOSTS_H
#include"PacBoard.h"
#include "PacMan.h"
class PacGhosts {
field board [100][100];
PacBoard &tab;
int height;
int width;
PacCoord ghostCoord[3];
public:
    explicit PacGhosts(PacBoard &x);
    char ghostsMovement(char klawisz);
};


#endif //LOL_PACGHOSTS_H
