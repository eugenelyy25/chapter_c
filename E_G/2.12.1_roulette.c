#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Enumeration for bet types
typedef enum {
    ODD_EVEN_BET,
    NUMBER_BET
} BetType;

// Structure for a bet
typedef struct {
    BetType type;
    int number; // Used only for NUMBER_BET
    int amount;
} Bet;

int spinRoulette(void);
int isOdd(int number);
void processBet(Bet bet, int rouletteNumber);

int main(void)
{
    srand(time(NULL)); // Seed the random number generator

    Bet playerBet;
    int betChoice;

    // Get the player's bet type
    printf("Choose your bet type (0 for Odd/Even, 1 for Number): ");
    scanf("%d", &betChoice);
    playerBet.type = (BetType)betChoice;

    // Get the bet number & amount
    if (playerBet.type == NUMBER_BET) {
        do {
            printf("Enter the number you want to bet on (0-35): ");
            scanf("%d", &playerBet.number);
            if (playerBet.number < 0 || playerBet.number > 35) {
                printf("Invalid number. Please enter a number between 0 and 35.\n");
            }
        } while (playerBet.number < 0 || playerBet.number > 35);
    }
    printf("Enter the amount you want to bet: ");
    scanf("%d", &playerBet.amount);

    // Spin the roulette
    int rouletteNumber = spinRoulette();
    printf("Roulette selected: %d\n", rouletteNumber);

    // Process the bet
    processBet(playerBet, rouletteNumber);

    return 0;
}

// Function to simulate spinning the roulette
int spinRoulette(void)
{
    return rand() % 36; // Random number between 0 and 35
}

// Function to check if a number is odd
int isOdd(int number)
{
    return number % 2 != 0;
}

// Function to process the player's bet
void processBet(Bet bet, int rouletteNumber)
{
    if (bet.type == ODD_EVEN_BET) {
        if (rouletteNumber == 0) {
            printf("Roulette selected 0. All odd/even bets lose.\n");
        } else if ((isOdd(rouletteNumber) && bet.number == 1) || (!isOdd(rouletteNumber) && bet.number == 0)) {
            printf("You win! Payout: %d\n", bet.amount * 2);
        } else {
            printf("You lose.\n");
        }
    } else if (bet.type == NUMBER_BET) {
        if (rouletteNumber == bet.number) {
            printf("You win! Payout: %d\n", bet.amount * 35);
        } else {
            printf("You lose.\n");
        }
    }
}