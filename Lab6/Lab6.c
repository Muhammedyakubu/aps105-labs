#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARDROWS 9
#define BOARDCOLS 11

bool dumpComputer = false; //causes dump of computer board before game if true (for debugging)

// boards. 0 means empty, non-zero means ship is there, number is size, -tive means hit on a ship
int playerBoard[BOARDROWS + 1][BOARDCOLS + 1];
int computerBoard[BOARDROWS + 1][BOARDCOLS + 1];
int compShotBoard[BOARDROWS + 1][BOARDCOLS + 1];

int getRand(int lowval, int highval) {
    return (rand() % (highval + 1 - lowval) + lowval);
}


int getShot(bool fromUser, int board[BOARDROWS + 1][BOARDCOLS + 1]) {
    int row, col;

    while (1) {
        if (fromUser) {
            printf("Give a shot (row, col):");
            scanf("%d%d", &row, &col);
            if (col < 1 || col > BOARDCOLS || row < 1 || row > BOARDROWS)
                printf("Invalid input\n");
            else  //valid input
                break;
        } else { //computer generated
            row = getRand(1, BOARDROWS);
            col = getRand(1, BOARDCOLS);
            if (compShotBoard[row][col] == 0) { //make sure haven't shot here before
                compShotBoard[row][col] = 1; //valid shot
                break;
            }
        }
    } //will leave this loop with valid input
    if (board[row][col] != 0) {
        if (board[row][col] > 0)
            board[row][col] = -1 * board[row][col]; //make sure is -tive
        return -1 * board[row][col]; //a hit!
    }
    return 0; //miss
}


bool allShipsNotHit(int board[BOARDROWS + 1][BOARDCOLS + 1]) {
    for (int i = 1; i <= BOARDROWS; i++) {
        for (int j = 1; j <= BOARDCOLS; j++) {
            if (board[i][j] > 0) //ship and not hit
                return (true);
        }
    }
    return (false); //no ships found not all hit
}

bool noneLeft(int valueToFind, int board[BOARDROWS + 1][BOARDCOLS + 1]) {
    for (int i = 1; i <= BOARDROWS; i++) {
        for (int j = 1; j <= BOARDCOLS; j++) {
            if (board[i][j] == valueToFind) //ship and not hit
                return (false);
        }
    }
    return (true); //no ships found, all hit
}

//This is in effect a boolean, 0 for false, 1 for True, and 2 as a special error code for if there is a ship alreay placed in that location.
int checkInput(int shipSize, int startRow, int startCol, int orientation, int board[BOARDROWS + 1][BOARDCOLS + 1]) {
    if (startRow < 1 || startRow > BOARDROWS || startCol < 1 || startCol > BOARDCOLS || orientation > 1 || orientation < 0) {//for inputs out of bounds.
        return 0;
    }
    
    if (orientation == 0) {//for across oriented placements
       for (int i = startCol; i < startCol + shipSize; i++) {//for inputs that conflict with a ship already placed
            if (board[startRow][i] != 0)
                return 2;
        }
         if (startCol + shipSize - 1 > BOARDCOLS) {//for ship placements that go over the board
            return 0;
        }
    }
    if (orientation == 1) {
        for (int j = startRow; j < startRow + shipSize; j++) {
            if (board[j][startCol] != 0)
                return 2;
        }
        if (startRow + shipSize - 1 > BOARDROWS) {//same as above but for across oriented ships.
            return 0;
        }
    }
    return 1;//returns true if all above statements are false.
}

void populateAcross(int shipSize, int startingRow, int startingColumn, int board[BOARDROWS + 1][BOARDCOLS + 1]) {
    for (int currentCol = startingColumn; currentCol < (startingColumn + shipSize); currentCol++) {
        board[startingRow][currentCol] = shipSize;
    }
}

void populateDown(int shipSize, int startingRow, int startingColumn, int board[BOARDROWS + 1][BOARDCOLS + 1]) {
    for (int currentRow = startingRow; currentRow < (startingRow + shipSize); currentRow++) {
        board[currentRow][startingColumn] = shipSize;
    }
}

void autoPopulate(int board[BOARDROWS + 1][BOARDCOLS + 1]) {
    int validInput = 0;
    int startingRow, startingCol, orientation;
    for (int shipSize = 5; shipSize > 0; shipSize--,validInput = 0) {
        while (validInput != 1) {
            startingRow = getRand(1, 9);
            startingCol = getRand(1, 11);
            orientation = getRand(0, 1);
            validInput = checkInput(shipSize, startingRow, startingCol, orientation, board);
        }//Will leave this loop with a valid input
        orientation == 0 ? populateAcross(shipSize, startingRow, startingCol, board) : populateDown(shipSize, startingRow, startingCol, board);
    }
}

void manualPopulate(int board[BOARDROWS + 1][BOARDCOLS + 1]) {
    int startingRow, startingColumn, orientation;
    printf("Rows are 1 - 9, Columns are 1 - 11\nOrientation is 0 for across, 1 for down\n");
    for (int shipSize = 5; shipSize > 0; shipSize--) {
        int validInput = 0;//1 for true, 0 and 2 for false, but they are different error codes
        while (validInput != 1) {
            printf("Give starting row, starting column and orientation (3 inputs) for ship of size=%d:", shipSize);
            scanf("%d %d %d", &startingRow, &startingColumn, &orientation);
            validInput = checkInput(shipSize, startingRow, startingColumn, orientation, board);
            if (validInput == 2) 
                printf("Conflicts with ship already placed\n");
             else if (validInput == 0)
                    printf("Invalid Input\n");
        }//Willl leave this loop with valid input
        orientation == 0 ? populateAcross(shipSize, startingRow, startingColumn, board) : populateDown(shipSize,startingRow, startingColumn, board);
    }

}

void populateBoard(bool getUserInput, int board[BOARDROWS + 1][BOARDCOLS + 1]) {
    //Manually populating user board
    getUserInput == true ? manualPopulate(board) : autoPopulate(board);
}

void showBoard(int board[BOARDROWS + 1][BOARDCOLS + 1]) {
    printf("   Cols\n");
    printf("    1  2  3  4  5  6  7  8  9 10 11\n");
    printf("     ________________________________\n");
    for (int i = 1; i <= BOARDROWS; i++) {
        printf("R%d|", i);
        for (int j = 1; j <= BOARDCOLS; j++) {
            if (board[i][j] >= 0)
                printf(" ");
            printf("%d ", board[i][j]);
        }
        printf("|\n");
    }
    printf("  __________________________________\n");
}

int main(int argc, char **argv) {
    bool playerBoardOK, computerBoardOK;

    // initialize the seed randomly. 

    srand(time(NULL));

    //init the boards
    for (int i = 0; i < BOARDROWS; i++) {
        for (int j = 0; j < BOARDCOLS; j++) {
            playerBoard[i][j] = 0;
            computerBoard[i][j] = 0;
            compShotBoard[i][j] = 0;
        }
    }

    populateBoard(true, playerBoard);
    populateBoard(false, computerBoard);
    printf("Your board is\n");
    showBoard(playerBoard);
    if (dumpComputer) {
        printf("\n\nComputer board is\n");
        showBoard(computerBoard);
    }

    // play starts here
    playerBoardOK = true;
    computerBoardOK = true;
    while (playerBoardOK && computerBoardOK) {
        int hit = getShot(true, computerBoard); //shot from user
        if (hit) {
            printf("HIT on size %d\n", hit);
            if (noneLeft(hit, computerBoard))
                printf("Sunk computer's %d\n", hit);
        } else
            printf("MISS!!\n");
        hit = getShot(false, playerBoard);
        if (hit) {
            printf("Computer hits! Size=%d\n", hit);
            if (noneLeft(hit, computerBoard))
                printf("Sunk your %d\n", hit);
        } else
            printf("Computer miss!\n");
        playerBoardOK = allShipsNotHit(playerBoard);
        computerBoardOK = allShipsNotHit(computerBoard);
//    showBoard(playerBoard); //debug
//    showBoard(computerBoard); //debug
    }
    if (playerBoardOK)
        printf("You win!\n");
    else
        printf("You lose.\n");
    showBoard(computerBoard);

    return 0;
}
