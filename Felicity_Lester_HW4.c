// NAME : Felicity Lester
// CS 4350 – 251 - Unix Systems Programming
// Assignment Number : 4
// Due Date: 3 / 17 / 2025

#include <stdio.h>
#include <stdlib.h>  // For rand(), srand()
#include <time.h>    // For seeding random numbers

// Function to generate a random number between 2 and 20
int generate_random_number() {
    return (rand() % 19) + 2;
}

// Function to calculate how many times it takes to find the same sum again
int calculate_attempts(int targetSum) {
    int count = 0;
    int newFirst, newSecond, newSum;

    do {
        newFirst = generate_random_number();
        newSecond = generate_random_number();
        newSum = newFirst + newSecond;

        printf("Generating First Number = %d\n", newFirst);
        printf("Generating Second Number = %d\n", newSecond);
        printf("The sum of the generated numbers is : %d\n\n", newSum);

        count++;
    } while (newSum != targetSum);   // loops until the desired sum is reached again

    return count;
}

int main() {
    srand(time(0)); // Seed random number generator

    printf("Practicing C Programming Language\n\n");

    printf("This App generates two random numbers between 2 and 20\n");
    printf("inclusive. A sum will be calculated by adding the two generated\n");
    printf("numbers. Then, the program will find the number of times it\n");
    printf("takes for the sum to be reproduced again. Process is repeated\n");
    printf("until No is entered.\n");

    while (1) { // Keeps the program running
        int choice;
        printf("\nEnter one of the following:\n");
        printf("1 - Run the application\n");
        printf("9 - Exit the program ------> ");
        if (scanf("%d", &choice) != 1) {  // Check for valid input
            printf("\nInvalid input. Please enter 1 or 9.\n");
            while (getchar() != '\n');  // Clear input buffer
            continue;
        }
        printf("\n");

        if (choice == 9) {
            printf("Exiting program...\n");
            printf("\nImplemented By Felicity Lester\n3 - 17 - 2025\n");
            return 0;  // Exit program
        } else if (choice != 1) {
            printf("\nInvalid Choice - Enter 1 or 9 ----- > ");
            continue;
        }

        // Clear input buffer to avoid issues
        while (getchar() != '\n');

        // Use the function to generate 2 random numbers
        int firstNum = generate_random_number();
        int secondNum = generate_random_number();
        int numSum = firstNum + secondNum;

        printf("\nFirst Generated Number : %d\n", firstNum);
        printf("Second Generated Number : %d\n", secondNum);
        printf("\nFirst Number + Second Number = %d\n", numSum);
        printf("\nProcessing . . . . . . . \n\n");

        // call function to do math
        int count = calculate_attempts(numSum);

        printf("Number of Times the Numbers were Generated\n");
        printf("Before the Desired sum was reached = %d\n", count);

        // beefing with "Run Again?" appearing
        char userInput[10];  // Holds input
        while (1) {
            printf("\nRun The App. Again Yes ? No ----- > ");
            scanf("%s", userInput);

            // allows user to get crazy with letter casing
            for (int i = 0; userInput[i]; i++) {
                if (userInput[i] >= 'A' && userInput[i] <= 'Z') {
                    userInput[i] += ('a' - 'A');  // uppercase to lowercase
                }
            }

            if (strcmp(userInput, "yes") == 0) {
                break;  // Restart the loop
            } else if (strcmp(userInput, "no") == 0) {
                printf("\n\nImplemented By Felicity Lester\n3 - 17 - 2025\n");
                return 0;
            } else {
                printf("\nInvalid Choice - Enter Yes / No ----- > ");
            }
        }
    }

    return 0;
}