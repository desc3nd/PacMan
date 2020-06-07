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
int licznik[7];
direction direction[7];
PacCoord ghostCoord[7];
void checkLicznik(int nrOfGhost);

void ghostsMovement( int nrOfGhost);
public:
    explicit PacGhosts(PacBoard &x);
    bool isGhost(int row,int col);
    void tp(int nrOfGhost);
   void ghostMove(int nrOfGhost);
   void DefaultSettings();
   void DebugGhost();
};


#endif //LOL_PACGHOSTS_H
