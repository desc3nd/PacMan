

#ifndef LOL_PACGHOSTS_H
#define LOL_PACGHOSTS_H
#include"PacBoard.h"
#include "PacMan.h"
#include<vector>
struct direction
{
    bool up,down,right,left;
};
class PacGhosts
{
field board [100][100];
PacBoard &tab;
int height;
int width;
int nr;
int amountOfGhosts;
int licznik[7];
direction direction[7];
PacCoord ghostCoord[7];
//void checkLicznik(int nrOfGhost);
void tp(int nrOfGhost);
void checkDirection(int nrOfGhost);
public:
    explicit PacGhosts(PacBoard &x);
    bool isGhost(int row,int col) const;
    void ghostMove(int nrOfGhost);
    void DefaultSettings();
    void DebugGhost() const;
    int getNumberOfGhosts();
};


#endif //LOL_PACGHOSTS_H
