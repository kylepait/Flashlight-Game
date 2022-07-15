#include <iostream>
#include "player.h"
#include "board.h"

void player::flashLightMove(board* ptr, char playerMove)
{


    ///movement based on user input
    if(playerMove == 'a')
        {
            ptr->flashLightColumn -= 1;
        }
        else if(playerMove == 'd')
        {
            ptr->flashLightColumn += 1;
        }
        else if(playerMove == 'w')
        {
            ptr->flashLightRow -= 1;
        }
        else if(playerMove == 's')
        {
            ptr->flashLightRow += 1;
        }




}
