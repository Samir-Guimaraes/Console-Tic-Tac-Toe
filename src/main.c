#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char gameBoard[3][3];
char player1[50], player2[50];
char playerWithX[50], playerWithO[50];
char character;

void createBoard(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            gameBoard[i][j] = ' ';
        }
    }
}

void printBoard(){
    int row = 1, col = 1;
    for (int i = 0; i < 3; i++){
        col = 1;
        for (int j = 0; j < 3; j++){
            if (gameBoard[i][j] == 'X' || gameBoard[i][j] == 'O'){
                printf(" %c  ", gameBoard[i][j]);
            }
            // Otherwise, prints the position (like "11", "12", etc.)
            else {
                printf(" %d%d ", row, col);
            }
            col++;
        }
        printf("\n");
        row++;
    }
}

void insertMove(char *player, char symbol){
    int row, col;
    printf("%s, enter the row where you want to place %c: ", player, symbol);
    scanf("%d", &row);
    while(row < 1 || row > 3){
        printf("%s, enter only numbers between 1 and 3: ", player);
        scanf("%d", &row);
    }

    printf("%s, enter the column where you want to place %c: ", player, symbol);
    scanf("%d", &col);
    while(col < 1 || col > 3){
        printf("%s, enter only numbers between 1 and 3: ", player);
        scanf("%d", &col);
    }

    row--;
    col--;
    // Checks if the position is already taken
    if (gameBoard[row][col] == 'X' || gameBoard[row][col] == 'O'){
        printf("\nPosition already taken! Try again.\n");
        insertMove(player, symbol);  // Calls the function again if the position is taken
    } else {
        gameBoard[row][col] = symbol;  // Marks the position with the symbol
    }
}

void insertPlayers(){

    printf("What is the first player's name: ");
    scanf("%s", player1);
    printf("What is the second player's name: ");
    scanf("%s", player2);

    printf("\nWelcome to Tic-Tac-Toe \nPlayer 1 - %s \nPlayer 2 - %s", player1, player2);
    printf("\n");
}

int decideX_O() {
    srand(time(NULL));   // srand should be called only once
    int r = rand() % 2;  // Generates 0 or 1 randomly
    return r;
}

int isPositionFilled(int i, int j){
    if (gameBoard[i][j] == 'X' || gameBoard[i][j] == 'O')
        return 1;
    return 0;
}

int checkRowWin(){
    int counter = 1;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++){
            if (isPositionFilled(i, j) && (gameBoard[i][j] == gameBoard[i][j+1]))
                counter++;
        }
        if (counter == 3)
            return 1;
        counter = 1;
    }
    return 0;
}

int checkColumnWin(){
    int counter;
    for (int j = 0; j < 3; j++) { // Now j iterates through columns
        counter = 1; // Resets for each column
        for (int i = 0; i < 2; i++) { // Iterates through rows, but stops at the second-to-last
            if (isPositionFilled(i, j) && gameBoard[i][j] == gameBoard[i+1][j])
                counter++;
        }
        if (counter == 3)
            return 1;
    }
    return 0;
}

int checkMainDiagonalWin(){
    int counter = 1;
    for(int i = 0; i < 2; i++){
        if(isPositionFilled(i, i) && gameBoard[i][i] == gameBoard[i+1][i+1])
            counter++;
    }
     if (counter == 3)
            return 1;
    return 0;
}

int checkSecondaryDiagonalWin(){
    int counter = 1;
    for(int i = 0; i < 2; i++){
        if(isPositionFilled(i, 3 - i - 1) && gameBoard[i+1][3 - i - 2] == gameBoard[i][3 - i - 1])
            counter++;
    }
    if (counter == 3)
            return 1;
    return 0;
}

int checkWin(){
  int finalResult = 0;

  if (checkRowWin())
    finalResult = 1;
  else if (checkColumnWin())
    finalResult = 1;
  else if (checkMainDiagonalWin())
    finalResult = 1;
  else if (checkSecondaryDiagonalWin())
    finalResult = 1;

  return finalResult;
}

void initializeGame(){
  createBoard();
  insertPlayers();

  int r = decideX_O();
  if (r == 0) {
      strcpy(playerWithX, player1);
      strcpy(playerWithO, player2);
  } else {
      strcpy(playerWithX, player2);
      strcpy(playerWithO, player1);
  }
  printf("\nAfter a random draw, it was decided that:\n");
  printf("%s plays with X and %s plays with O.\n", playerWithX, playerWithO);
  printf("And by rule, the X player goes first.\n");
}

void runGame(){
  printf("\nWelcome to Tic-Tac-Toe\n");
  printBoard();
  int count = 0;
  int winner = 0;

  while(count < 9){
      insertMove(playerWithX, 'X'); // Substitution of the call
      if (checkWin()){
        printBoard();
        printf("Player %s wins!\n", playerWithX);
        winner = 1;
        break;
      }

      printBoard();
      count++;

      // Checks if there is still space for player O
      if (count == 9) break;
      insertMove(playerWithO, 'O'); // Substitution of the call
      if (checkWin()){
        printBoard();
        printf("Player %s wins!\n", playerWithO);
        winner = 1;
        break;
      }
      printBoard();
      count++;
    }

    if (count == 9 && winner == 0)
      printf("TIE! The game ended in a draw!\n");
}

int main()
{
    int option;

    do{
      printf("\nTic-Tac-Toe \nType 1 to start the game. \nType 2 to stop the procedure.\n");
      scanf("%d", &option);

      switch(option){
        case 1:
          initializeGame();
          runGame();
          break;
        case 2:
          printf("Aborting procedure abruptly.");
          break;
        default:
          printf("Please enter a valid option.\n");
          break;
      }
    }while(option != 2);

    return 0;
}
