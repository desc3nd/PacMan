//
// Created by Marcinek on 01.06.2020.
//

#include "PacGhosts.h"

PacGhosts::PacGhosts(PacBoard &x):tab(x) {
    height=tab.getHeight();
    width=tab.getWidth();
    ghostCoord[0].Row=15;
    ghostCoord[0].Col=12;
    ghostCoord[1].Row=15;
    ghostCoord[1].Col=14;
    ghostCoord[2].Row=15;
    ghostCoord[2].Col=16;
   board[ghostCoord[0].Row][ghostCoord[0].Col].hasPacman=true;
   board[ghostCoord[1].Row][ghostCoord[1].Col].hasPacman=true;
   board[ghostCoord[2].Row][ghostCoord[2].Col].hasPacman=true;


}

char PacGhosts::ghostsMovement(char klawisz) {
    return 0;
}
