//
// Created by Marcinek on 01.06.2020.
//

#ifndef LOL_PACGAMEMENAGER_H
#define LOL_PACGAMEMENAGER_H

#include "PacMan.h"
#include "PacGhosts.h"
#include "PacView.h"
#include "PacBoard.h"
enum GameStatus{Running,Lost};
class PacGameMenager {
    PacGhosts &ghosts;
    PacMan &pacMan;
    PacBoard &board;
    GameStatus status;
    int height;
    int points;
    int lives;
    int width;
    int refreshSpeed;
public:
    void play();
    GameStatus getGameStatus();
    int getLives();
    int getPoints();
    int getRefreshSpeed();
    void DefaultSettings();
    PacGameMenager(PacMan &pac,PacGhosts &ghost, PacBoard &tab);

    //field board[100][100];


};


#endif //LOL_PACGAMEMENAGER_H
