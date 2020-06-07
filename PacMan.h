//
// Created by Marcinek on 01.06.2020.
//

#ifndef LOL_PACMAN_H
#define LOL_PACMAN_H
#include "PacBoard.h"
#include "PacBoard.h"
struct PacCoord{
    int Col;
    int Row;
};
class PacMan {
    PacBoard &tab;
    field board[100][100];
  PacCoord pacCoord;
   int height;
   int width;
   void tp();
public:
explicit PacMan(PacBoard &x);
void PacMovement(char klawisz);
void DebugDisplayPac();
bool getCharInfo(int row, int col);
void DefaultSettings();
};


#endif //LOL_PACMAN_H
