#include <stdio.h>
#include <conio.h>

void printBoard();
int checkWin();
void clearScreen();

char board[]={'0','1','2','3','4','5','6','7','8','9'};

void main() {
    int player = 1, input, status = -1;
    printBoard();

    while (status == -1) {
        player = (player % 2 == 0) ? 2 : 1;
        char mark = (player == 1) ? 'X' : 'O';
        printf("Player %d, enter a number: ", player);
        scanf("%d", &input);

        if (input < 1 || input > 9 || board[input] == 'X' || board[input] == 'O') {
            printf("Invalid input or cell already taken. Please try again.\n");
            continue;
        }

        board[input] = mark;
        printBoard();

        int result = checkWin();

        if (result == 1) {
            printf("Player %d wins!\n", player);
            return;
        } else if (result == 0) {
            printf("It's a draw!\n");
            return;
        }

        player++;
    }
}


void printBoard(){
    clearScreen();
    printf("\n\n");
    printf("=== TIC TAC TOE ===\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",board[1],board[2],board[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",board[4],board[5],board[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",board[7],board[8],board[9]);
    printf("     |     |     \n");
    printf("\n\n");
}


int checkWin() {
    // Define winning combinations
    int win_combinations[8][3] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, // Rows
        {1, 4, 7}, {2, 5, 8}, {3, 6, 9}, // Columns
        {1, 5, 9}, {3, 5, 7}             // Diagonals
    };

    // Check for a win
    for (int i = 0; i < 8; i++) {
        int a = win_combinations[i][0];
        int b = win_combinations[i][1];
        int c = win_combinations[i][2];

        if (board[a] == board[b] && board[b] == board[c]) {
            return 1; // Found a winner
        }
    }

    // Check for a draw
    for (int i = 1; i <= 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            return -1; // Game still in progress
        }
    }

    return 0; // It's a draw
}

void clearScreen()
{
printf("\033[H\033[J"); // ANSI escape code to clear screen
}
