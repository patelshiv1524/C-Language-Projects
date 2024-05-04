#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to implement the game
int playGame(char you, char computer) {
    // If both the user and computer have chosen the same thing
    if (you == computer)
        return 0; // Draw

    // Define the winning combinations
    if ((you == 's' && computer == 'z') ||
        (you == 'p' && computer == 's') ||
        (you == 'z' && computer == 'p'))
        return 1; // You win
    else
        return -1; // Computer wins
}

int main() {
    int userWins = 0, computerWins = 0, rounds = 0; // Track consecutive wins and total rounds
    char you, computer, result;

    // Seed the random number generator
    srand(time(NULL));

    printf("\n\n\n\n\t\t\t\tEnter s for STONE, p for PAPER and z for SCISSOR\n\n");

    do {
        // Generate computer's choice
        int n = rand() % 3; // Generate a number between 0 and 2
        if (n == 0)
            computer = 's'; // Stone
        else if (n == 1)
            computer = 'p'; // Paper
        else
            computer = 'z'; // Scissor

        // Input from the user
        printf("\t\t\t\tYour choice: ");
        scanf(" %c", &you);

        // Play the game
        result = playGame(you, computer);

        // Print the result
        if (result == 0) {
            printf("\n\t\t\t\tGame Draw!\n");
        } else if (result == 1) {
            printf("\n\t\t\t\tYou win this round!\n");
            userWins++;
            computerWins = 0; // Reset computer's consecutive wins
        } else {
            printf("\n\t\t\t\tComputer wins this round!\n");
            computerWins++;
            userWins = 0; // Reset user's consecutive wins
        }

        printf("\t\t\t\tYou choose: %c   Computer choose: %c\n", you, computer);
        
        rounds++; // Increment the round counter

    } while (userWins < 3 && computerWins < 3);

    // Print the winner of the game and total rounds played
    if (userWins == 3) {
        printf("\n\n\t\t\t\tCongratulations! You won the game in %d rounds!\n", rounds);
    } else {
        printf("\n\n\t\t\t\tOops! Computer won the game in %d rounds!\n", rounds);
    }

    return 0;
}
