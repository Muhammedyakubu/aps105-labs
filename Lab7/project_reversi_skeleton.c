/*
 * File:        project_reversi_skeleton.c
 * Author:      APS105H1 Teaching Team
 * Modified by: * You Name Here *
 *
 * Date: Jan 2021
 */

#include "project_reversi_skeleton.h" // DO NOT modify this line
#include <stdio.h>
#include <string.h>
// Note: You may want to add more function declarations here
// =========   Function declaration  ==========
void initializeBoard(char board[][26], int n);
void printBoard(char board[][26], int n);
void configureBoard(char board[][26], int n);
void placeTile (char board[][26], char input[]);
bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol);
void availableMoves (char board[][26], int n, char colour);
bool positionInBounds(int n, int row, int col);
void playerTurn(char board[][26], int n, char move[]);
bool checkValidAndFlip(char board[][26], int row, int col, char colour, int n);
void flipInDirection(char board[][26], int row, int col, int deltaRow, int deltaCol, char colour);


// ========= Function implementation ==========

void initializeBoard(char board[][26], int n){
    for (int i = 0; i< 26; i++){
        for (int j = 0; j < 26 ; j++)
            board[i][j] = 'U';
    }
    board[n/2][n/2] = 'W';
    board[n/2 + 1][n/2 + 1] = 'W';
    board[n/2 + 1][n/2] = 'B';
    board[n/2][n/2 + 1] = 'B';
}
/*
 * Function:  printBoard 
 * --------------------
 * Print the whole board to the terminal window.
 */
void printBoard(char board[][26], int n) {
    //printing the column letters
    printf("  ");
    for ( int k = 0; k < n; k++)
        printf("%c",97+k);
        
    printf("\n");
        
    for (int i = 1; i <= n; i++){
        printf("%c ",96+i);//printing the column letters
        for (int j = 1; j <= n; j++)
            printf("%c",board[i][j]);//printing board content
        
        printf("\n");
    }
}

void placeTile (char board[][26], char input[]){
    int row, col;
    char color;
    //converting letters input to row/column numbers
    color = input[0];
    row = input[1] - 'a' + 1;
    col = input[2] - 'a' + 1;
    board[row][col] = color;
}

void  configureBoard(char board[][26], int n){
    printf("Enter board configuration:\n");
    char input[] = "xyz", endInput[] = "!!!";
    while(strcmp(input, endInput) != 0){
        scanf("%s",input);
        placeTile (board, input);
    }
}

void availableMoves (char board[][26], int n, char colour){
    bool legalMove;
    int numOfMoves = 0;//number of possible moves that each board location has
    printf("Available moves for %c:\n",colour);
    //looping through each board location
    for (int row = 1; row <= n; row++){
        for (int col = 1; col <= n; col++){
            
            if (board[row][col] == 'U'){
                for (int deltaRow = -1; deltaRow <= 1; deltaRow++){//looping through all 8 directions
                    for (int deltaCol = -1; deltaCol <= 1; deltaCol++, legalMove = false){
                        if (!(deltaCol == deltaRow && deltaCol ==0)){
                            legalMove = checkLegalInDirection( board, n, row, col, colour, deltaRow, deltaCol);
                            if (legalMove && numOfMoves == 0){//this makes sure that it prints the move only once
                                printf("%c%c\n",96+row,96+col);  
                                numOfMoves++;
                            }
                        }
                    }
                }
                numOfMoves = 0;
            }
        }
    }
}

void playerTurn(char board[][26], int n, char move[]){
    char colour = move[0];
    int row = move[1] - 'a' + 1;
    int col = move[2] - 'a' + 1;
    bool valid;
    if (positionInBounds(n, row, col))
        valid = checkValidAndFlip( board, row, col, colour, n);

    valid? puts("Valid move."): puts("Invalid move.");
    }

bool checkValidAndFlip(char board[][26], int row, int col, char colour, int n){
    bool legalMove, wasTrue;
    if (board[row][col] == 'U'){
        for (int deltaRow = -1; deltaRow <= 1; deltaRow++){
            for (int deltaCol = -1; deltaCol <= 1; deltaCol++, legalMove = false){
                if (!(deltaCol == deltaRow && deltaCol ==0)){
                    legalMove = checkLegalInDirection( board, n, row, col, colour, deltaRow, deltaCol);
                    if (legalMove){
                        flipInDirection (board, row, col, deltaRow, deltaCol, colour);
                        wasTrue = legalMove;                        
                    }
                }
            }
        }
    }
    if (wasTrue){//if any direction was legal it returns a boolean 
        wasTrue = false;
        return true;
    }
        return false;
}

void flipInDirection(char board[][26], int row, int col, int deltaRow, int deltaCol, char colour){
    if (board[row][col] == colour){//This is for the case where the location has more than one legal direction
        row +=deltaRow;
        col += deltaCol;
    }
    while(board[row][col] != colour){
        board[row][col] = colour;
        row +=deltaRow;
        col += deltaCol;
    }
}
/*
 * Function:  positionInBounds 
 * --------------------
 * Checks whether the specified (row, col) lies within the board dimensions.
 */
bool positionInBounds(int n, int row, int col) {
    if (row <= n && row > 0 && col <= n && col > 0)
        return true;
    return false;  
}

/*
 * Function:  checkLegalInDirection 
 * --------------------
 * Checks whether (row, col) is a legal position for a tile of colour by “looking” in the direction 
 * specified by deltaRow and deltaCol.
 */
bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol) {
    row += deltaRow;
    col += deltaCol;
        if (board[row][col] == colour)
            return false;
    while (positionInBounds(n, row, col) && board[row][col] != colour && board[row][col] != 'U'){
            row += deltaRow;
            col += deltaCol;
    }
        if (board[row][col] == colour)
            return true;
        else
            return false;
}

/*
 * Function:  makeMove 
 * --------------------
 * The player "turn" makes a move at (row, col).
 * Note: This function MUST NOT change board, only row and col can be changed to reflect the move.
 */
int makeMove(const char board[26][26], int n, char turn, int *row, int *col) {
    (void)board;
    (void)n;
    (void)turn;
    (void)row;
    (void)col;
    return 0;
}

#ifndef COMPETE_MODE // DO NOT DELETE THIS LINE
int main(void) {
    char gameBoard[26][26];
    int boardDimensions;
    printf("Enter the board dimension: ");
    scanf("%d",&boardDimensions);
    initializeBoard(gameBoard, boardDimensions);

    printBoard(gameBoard, boardDimensions);
    
    configureBoard(gameBoard, boardDimensions);
    
    printBoard(gameBoard, boardDimensions);
    
   
    
    char move[4];
    
    while (1){
        availableMoves(gameBoard, boardDimensions, 'W');

        availableMoves(gameBoard, boardDimensions, 'B');
       
        puts("Enter a move:");
        scanf("%s",move);
        
        playerTurn(gameBoard, boardDimensions, move);
        
        printBoard( gameBoard, boardDimensions);
    }
    
    return 0;
}
#endif // DO NOT DELETE THIS LINE