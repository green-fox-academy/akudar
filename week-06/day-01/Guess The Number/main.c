#include <stdio.h>

int main() {

    int number = 5;
    int guess;

    printf("Guess The Number\n");
    scanf("%d", &guess);

    while (guess != number) {
        if (guess < number) {
            printf("The stored number is higher\n");
            scanf("%d", &guess);
        } else if (guess > number) {
            printf("The stored number is lower\n");
            scanf("%d", &guess);
        }
    }

    if (guess == number) {
        printf("You found the number: %d", number);
    }

    return 0;
}