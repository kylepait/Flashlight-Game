#include <iostream>
#include <cstdlib>
#include "time.h"
#include "board.h"


using namespace std;
///default constructor
board::board()
{
    flashLightRow = 7;
    flashLightColumn = 7;
        for(int i = 0; i < 17; i++)
            for(int j = 0; j < 17; j++)
                grid[i][j].value = ' ';
}


board::boardConstruct(int numOfItems)
{

    srand(time(0));
    int randXCoord, randYCoord;


    ///generate border values
    for(int i = 0; i < 17; i++)
        for(int j = 0; j < 17; j++)
        {
            if(i == 0 || i == 16)
                grid[i][j].value = '-';

            else if(j == 0 || j == 16)
                grid[i][j].value = '|';

        }


    for(int i = 0; i < numOfItems; i++)
    {
        ///generate random X value for item location
        randXCoord = rand()%(15 - 1 + 1) + 1;
        ///generate random Y value for item location
        randYCoord = rand()%(15 - 1 + 1) + 1;

        ///set value at the XY location to 'X'
        grid[randXCoord][randYCoord].value = 'X';
    }


}
///test print function
void board::printGrid()
{
    for(int i = 0; i < 17; i++)
    {

        for(int j = 0; j < 17; j++)
        {

            cout << grid[i][j].value;


        }
        cout << endl;
    }
}

void board::hiddenPrint(int& numFound)
{
    ///variables for the flash light borders
    int upRow = flashLightRow - 1;
    int upColumn = flashLightColumn;

    int downRow = flashLightRow + 1;
    int downColumn = flashLightColumn;

    int leftRow = flashLightRow;
    int leftColumn = flashLightColumn - 1;

    int rightRow = flashLightRow;
    int rightColume = flashLightColumn + 1;

    for(int i = 0; i < 17; i++)
    {

        for(int j = 0; j < 17; j++)
        {
            ///if flash light is over X, change its value to found
            if(i == flashLightRow && j == flashLightColumn)
            {
                cout << grid[i][j].value;
                if(grid[i][j].value == 'X')
                {
                    grid[i][j].value = 'F';
                    numFound++;
                }


            }

            ///showing the border values of the flashlight
            else if(i == upRow && j == upColumn)
            {
                if(grid[i][j].value == 'X' || grid[i][j].value == 'F')
                    cout << "X";
                else if(grid[i][j].value != 'X' || grid[i][j].value == 'F')
                    cout << "-";
            }
            else if(i == downRow && j == downColumn)
            {
                if(grid[i][j].value == 'X' || grid[i][j].value == 'F')
                    cout << "X";
                else if(grid[i][j].value != 'X' || grid[i][j].value == 'F')
                    cout << "-";
            }

            else if(i == leftRow && j == leftColumn)
            {
                if(grid[i][j].value == 'X' || grid[i][j].value == 'F')
                    cout << "X";
                else if(grid[i][j].value != 'X' || grid[i][j].value == 'F')
                    cout << "|";
            }

            else if(i == rightRow && j == rightColume)
            {
                if(grid[i][j].value == 'X' || grid[i][j].value == 'F')
                    cout << "X";
                else if(grid[i][j].value != 'X' || grid[i][j].value == 'F')
                    cout << "|";
            }
            ///prints previously found X instead of @
            else if(grid[i][j].value == 'F')
                cout << "X";

            ///if supposed to print an X, hide it with a @
            else if(grid[i][j].value == 'X')
                cout << "@";

            else if(grid[i][j].value == ' ')
                cout << "@";

            else if(i == 0 || i == 16)
                cout << grid[i][j].value;

            else if(j == 0 || j == 16)
                cout << grid[i][j].value;




        }
        cout << endl;
    }
}
