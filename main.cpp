#include <iostream>
#include <cstdlib>
#include "square.h"

#include "board.h"

#include "player.h"




using namespace std;

void userPrompt(int& numOfTurns, int& numOfItems);

int main()
{


    ///create square object
    square playSquare;
    ///create board object
    board newBoard;
    ///create player object
    player newPlayer;
    newPlayer.ptr = &newBoard;


    int numOfTurns = 0, numOfItems = 0;
    char playerMove = ' ';

    userPrompt(numOfTurns, numOfItems);

    ///construct board
    newBoard.boardConstruct(numOfItems);
    ///test print
    ///newBoard.printGrid();

    ///value for found Xs
    int numFound = 0;



    while(numOfTurns > 0 && numOfItems > numFound)
    {
        newBoard.hiddenPrint(numFound);
        cout << endl;
        cout << "Current Position: " << "(" << newBoard.flashLightRow << "," << newBoard.flashLightColumn << ")" << endl
             << numFound << "/" << numOfItems << endl
             << "Movement controls: a,d,w,s" << endl
             << "Enter Move: ";
        cin  >> playerMove;

        newPlayer.flashLightMove(newPlayer.ptr, playerMove);

        newBoard.hiddenPrint(numFound);

        numOfTurns--;

        if(numFound == numOfItems)
            cout << "You Win!";
        if(numOfTurns == 0)
            cout << "Game Over";
    }



    return 0;
}

void userPrompt(int& numOfTurns, int& numOfItems)
{

    bool flagOne = false, flagTwo = false;

    while(flagOne == false && flagTwo == false)
    {
        while(flagOne == false)
        {
            cout << "Enter the number of turns: ";
            cin  >> numOfTurns;

            if(numOfTurns < 1 || numOfTurns > 50)
                cout << "Number of turns must be between 1-50" << endl;
            else if(numOfTurns >= 1 && numOfTurns <= 50)
                flagOne = true;
        }
        while(flagTwo == false)
        {
            cout << "Enter the number of hidden items: ";
            cin  >> numOfItems;

            if(numOfItems < 1 || numOfItems > 25)
                cout << "Number of items must be between 1-25" << endl;
            else if(numOfItems >= 1 && numOfItems <= 25)
                flagTwo = true;
        }
    }
}
