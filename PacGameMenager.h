
#ifndef LOL_PACGAMEMENAGER_H
#define LOL_PACGAMEMENAGER_H
#include <SFML/Audio.hpp>
#include "PacMan.h"
#include "PacGhosts.h"
#include "PacView.h"
#include "PacBoard.h"
enum GameStatus{Running,Lost, Win};
class PacGameMenager
{
    PacMan &pacMan;
    PacGhosts &ghosts;
    PacBoard &board;
    GameStatus status;
    int height;
    int points;
    int width;
    float refreshSpeed;
    int foodLeft;
    int eatableGhostsTime;
    bool eatable;
    int nrOfLoop;
public:
    void checkRelationAndRules();
    GameStatus getGameStatus() ;
    int getPoints() const;
    float getRefreshSpeed() const;
    void DefaultSettings();
    PacGameMenager(PacMan &pac,PacGhosts &ghost, PacBoard &tab);
    void eatableGhosts();
    bool getEatableStatus() const;


};


#endif //LOL_PACGAMEMENAGER_H
