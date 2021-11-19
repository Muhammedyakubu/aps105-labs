#include <stdio.h>
#include <string.h>

void initializeBoard(char board[][26], int n){
    for (int i = 0; i< n; i++){
        for (int j = ; j < n ; j++)
            board[i][j] = 'U';
    }
}

void printBoard(char board[][26], int n){
        printf("  ");
        for ( int k = 0; k < n; k++)
            printf("%c",97+k);
        
        printf("\n");
        
        for (int i = 0; i < n; i++){
            printf("%c ",97+i);
            for (int j = 0; i < n; j++)
                printf("%c",board[i][j]);
    }
}

void placeTile (char board[][26], char input[]){
    int row, col;
    char color;
    color = input[0];
    row = input[1] - 'a' + 1;
    col = input[2] - 'a' + 1;
    board[row][col] = color;
}

void  configureBoard(char board[][26], int n){
    printf("Enter board configuration:\n ");
    char input[] = "xyz", endInput[] = "!!!";
    while(strcmp(const input, const endInput) != 0){
        gets(input);
        placeTile (board, input);
    }
}

bool positionInBounds (int n, int row, int col){
    if (row <= n && row > 0 && col <= n && col > 0)
        return true;
        else 
            return false;
}

bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol){
    row += deltaRow;
    col += deltaCol;
    while (positionInBounds(row, col) || board[row][col] != colour || board[row][col] != 'U'){
            row += deltaRow;
            col += deltaCol;
    }
        if (board[row][col] == colour)
            return true;
        else
            return false;
}
    row += deltaRow;
    col += deltaCol;
    while (positionInBounds(row, col) || board[row][col] != colour || board[row][col] != 'U'){
            row += deltaRow;
            col += deltaCol;
    }
    if (


void availableMoves (char board[][26], int n){
    bool legalMove;
    char colour = 'W';//finding available moves for white
    puts("Available moves for %c:",colour);
    for (row = 0; row < n; row++){
        for (col = 0; col < n; col++){
            
            if (board[row][col] == 'U'){
                for (deltaRow = -1; deltaRow <= 1; deltaRow++){
                    for (int deltaCol = -1; deltaCol <= 1; deltaCol++, legalMove = false;)
                        legalMove = checkLegalInDirection( board, n, row, col, colour, deltaRow, deltaCol);
                        if (legalMove)
                            printf("%c%c\n",97+row,97+col);
                }
            }
        }
    }
}


int main(void) {
    char gameBoard[26][26];
    int boardDimensions;
    printf("Enter the board dimension: ");
    scanf("%d",&boardDimensions);
    initializeBoard(gameBoard, boardDimensions);
    
    printBoard(gameBoard, boardDimensions);
    
    configureBoard(gameBoard, boardDimensions);
    
    availableMoves(gameBoard, boardDimensions);
    
    playerTurn(gameboard, boardDimensions, move);
    
    

    return 0;
}

void playerTurn(char board[][26], int n, char move[]){
    colour = move[0];
    row = move[1] - 'a' + 1;
    col = move[2] - 'a' + 1;
    bool valid;
        if (positionInBounds(n, row, col))
            valid = checkValidAndFlip( board, row, col, colour, n): 
            
            valid? puts("Valid move."): puts("Invalid move");
    }
bool checkValidAndFlip(char board[][26], int row, int col, char colour, int n){
    bool legalMove;
    if (board[row][col] == 'U'){
        for (int deltaRow = -1; deltaRow <= 1; deltaRow++){
            for (int deltaCol = -1; deltaCol <= 1; deltaCol++, legalMove = false){
                if (!(deltaCol == deltaRow && deltaCol ==0)){
                    legalMove = checkLegalInDirection( board, n, row, col, colour, deltaRow, deltaCol);
                    if (legalMove)
                        flipInDirection (board, row, col, deltaRow, deltaCol, colour);
                }
            }
        }
    }
    if (legalMove)
        return true;
        return false;
}

void flipInDirection(char board[][26], int row, int col, int deltaRow, int deltaCol, ){
    while(board[row][col] != colour){
        row +=deltaRow;
        col += deltaCol;
        board[row][col] = colour;
    }
}

void playerTurn(char board[][26], int n, char move[]);
bool checkValidAndFlip(char board[][26], int row, int col, char colour, int n);
void flipInDirection(char board[][26], int row, int col, int deltaRow, int deltaCol, );