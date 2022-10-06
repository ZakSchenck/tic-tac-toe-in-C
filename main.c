// My first project ever built in C: Tic Tac Toe by Zak Schenck.
#include <stdio.h>
#include <stdbool.h>

// Base global variables
char gameBoard[] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
char currentPlayer = 'X';
bool isGameActive = true;

// Function prototype
void displayBoard();
void getUserInput();
bool checkColWinner();
bool checkRowWinner();
bool checkDiagWinner();
char switchPlayer();

// Main function
int main()
{
    displayBoard();
    getUserInput();
    return (0);
};

// Displays game board when called
void displayBoard()
{
    printf("__%c__|__%c__|__%c__\n", gameBoard[0], gameBoard[1], gameBoard[2]);
    printf("__%c__|__%c__|__%c__\n", gameBoard[3], gameBoard[4], gameBoard[5]);
    printf("__%c__|__%c__|__%c__\n", gameBoard[6], gameBoard[7], gameBoard[8]);
};

// Getting user input function
void getUserInput()
{
    int userInput;
    printf("Enter any input to start game! \n");
    scanf("%i", &userInput);

    while (isGameActive)
    {
        int i;
        displayBoard();
        printf("Pick your square \n");
        scanf("%i", &userInput);
        while (gameBoard[userInput] != '-' || userInput > 8 || userInput < 0)
        {
            printf("Choose an valid square \n");
            scanf("%i", &userInput);
        }
        gameBoard[userInput] = currentPlayer;
        printf("You used %i\n", userInput);
        checkRowWinner();
        checkColWinner();
        checkDiagWinner();
        switchPlayer();
    }
};

// Function that changes player
char switchPlayer()
{
    if (currentPlayer == 'X')
    {
        return currentPlayer = 'O';
    }
    else
    {
        return currentPlayer = 'X';
    }
}

bool checkRowWinner()
{
    // Check if row contains winner
    if (gameBoard[0] == gameBoard[1] && gameBoard[0] == gameBoard[2] && gameBoard[0] != '-' ||
        gameBoard[3] == gameBoard[4] && gameBoard[3] == gameBoard[5] && gameBoard[3] != '-' ||
        gameBoard[6] == gameBoard[7] && gameBoard[6] == gameBoard[8] && gameBoard[6] != '-')
    {
        printf("%c is the winner!!", currentPlayer);
        return isGameActive = false;
    }
}

bool checkColWinner()
{
    // Check if column contains winner
    if (gameBoard[0] == gameBoard[3] && gameBoard[0] == gameBoard[6] && gameBoard[0] != '-' ||
        gameBoard[1] == gameBoard[4] && gameBoard[1] == gameBoard[7] && gameBoard[1] != '-' ||
        gameBoard[2] == gameBoard[5] && gameBoard[2] == gameBoard[8] && gameBoard[2] != '-')
    {
        printf("%c is the winner!!", currentPlayer);
        return isGameActive = false;
    }
}

bool checkDiagWinner()
{
    // Check if column contains winner
    if (gameBoard[0] == gameBoard[4] && gameBoard[0] == gameBoard[8] && gameBoard[0] != '-' ||
        gameBoard[2] == gameBoard[4] && gameBoard[2] == gameBoard[6] && gameBoard[2] != '-')
    {
        printf("%c is the winner!!", currentPlayer);
        return isGameActive = false;
    }
}
