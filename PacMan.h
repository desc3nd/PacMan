

#ifndef LOL_PACMAN_H
#define LOL_PACMAN_H
#include "PacBoard.h"
#include "PacBoard.h"
struct PacCoord
{
    int Col;
    int Row;
};
class PacMan
{
    PacBoard &tab;
    field board[100][100];
  PacCoord pacCoord;
   int height;
   int width;
   void tp();
public:
explicit PacMan(PacBoard &x);
void PacMovement(char klawisz);
void DebugDisplayPac() const;
bool isPacman(int row, int col) const;
void DefaultSettings();
};


#endif //LOL_PACMAN_H
