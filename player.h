#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "board.h"

class player
{

public:

    board* ptr;
    void flashLightMove(board* ptr, char playerMove);

};

#endif
