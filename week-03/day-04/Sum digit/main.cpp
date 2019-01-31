#include <iostream>

int sumDigit(int input) {

    return input == 0 ? input : input % 10 + sumDigit(input / 10);
}

int main() {

    int sum = sumDigit(126);

    std::cout << sum;

    return 0;
}