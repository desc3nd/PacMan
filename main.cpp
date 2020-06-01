#include <iostream>
#include"PacBoard.h"
#include"Pacman.h"
int main() {
PacBoard board;
//board.Debug_Display();
PacMan Pacman(board);
Pacman.DebugDisplayPac();
Pacman.PacMovement('w');
Pacman.PacMovement('w');
    Pacman.PacMovement('w');
    Pacman.PacMovement('w');
    std::cout<<std::endl;
    std::cout<<std::endl;
    Pacman.DebugDisplayPac();

    return 0;
}
