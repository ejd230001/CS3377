#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int generateRandomValue(int min, int max);

int main() {
    srand(time(NULL) + getpid());
    int numGuesses = 0;
    int allowedGuesses = 10;
    int randomValue = generateRandomValue(-100, 100);
    int guess;
    //printf("Random Value: %d\n", randomValue);

    printf("Guess the random number! It lies between -100 and 100.\nYou are allowed 10 guesses.\n\n");
    while (numGuesses < allowedGuesses) {
        printf("Enter a guess: ");
        numGuesses++;
        scanf("%d", &guess);
        if (guess > randomValue) {
            printf("Too High!\n\n");
        }
        else if (guess < randomValue) {
            printf("Too Low!\n\n");
        }
        else if (guess == randomValue) {
            break;
        }
    }

    if(guess == randomValue) {
        printf("\nYou guessed it! The number was: %d\n", randomValue);
        printf("Your score is: %d\n", numGuesses);
    }
    else {
        printf("\nYou failed to guess the number in %d guesses.\nThe number was %d.\n", allowedGuesses, randomValue);
    }

    int fd = open("report.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fd < 0) { 
        printf("Error opening file\n");
        return -1;
    }

    char message[100];
    char *username = getenv("USER");

    if (guess == randomValue) 
        sprintf(message, "User: %s\nSuccessfully guessed the number %d in %d tries.\n", username, randomValue, numGuesses);
    else 
        sprintf(message, "User: %s\nFailed to guess the number %d in 10 tries.\n", username, randomValue);
    
    write(fd, message, strlen(message));
    return 0;
}

int generateRandomValue(int min, int max) {
    return min + (rand() % (max - min + 1));
}