#include <stdio.h>

int isPrime(int number) {

    for (int i = 2; i < number; ++i) {
        if (number % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {

    int input;

    scanf("%d", &input);

    printf("%d", isPrime(input));

    return 0;
}