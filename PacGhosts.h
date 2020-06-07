//
// Created by Marcinek on 01.06.2020.
//

#ifndef LOL_PACGHOSTS_H
#define LOL_PACGHOSTS_H
#include"PacBoard.h"
#include "PacMan.h"
#include<vector>
struct direction
        {
    bool up,down,right,left;
};
class PacGhosts {
field board [100][100];
PacBoard &tab;
int height;
int width;
int nr;
int licznik;
direction direction;
PacCoord ghostCoord[4];


void ghostsMovement( int nrOfGhost);
public:
    explicit PacGhosts(PacBoard &x);

    bool isGhost(int row,int col);
    void gostStart();
   void ghostMove(int nrOfGhost);
};


#endif //LOL_PACGHOSTS_H
