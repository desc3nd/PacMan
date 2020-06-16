
#ifndef PACMAN_PACSFMLMUSIC_H
#define PACMAN_PACSFMLMUSIC_H
#include "PacBoard.h"
#include "PacGhosts.h"
#include "PacMan.h"
#include "PacGameMenager.h"
#include <SFML/Audio.hpp>
class PacSFMLMusic
{
    int height;
    int width;
    PacBoard &board;
    PacMan &pacMan;
    PacGhosts &ghosts;
    PacGameMenager &ctrl;
    sf::SoundBuffer buffer[5];
    sf::Sound sound[5];//0-blech 1-pipe 2-fail 3-win 4-theme
    bool mute;

public:

    PacSFMLMusic(PacBoard &Board, PacMan &pac, PacGhosts &ghost, PacGameMenager &menager );
    void stopStartMusic();
    void soundEffect(); 
    void playMusic();
};


#endif //PACMAN_PACSFMLMUSIC_H
