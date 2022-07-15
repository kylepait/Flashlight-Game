#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include "square.h"

class board
{
    private:

        square grid[17][17];

    public:

        ///default constructor
        board();


        boardConstruct(int numOfItems);

        void printGrid();


        int flashLightRow;
        int flashLightColumn;

        void hiddenPrint(int& numFound);
};

#endif
