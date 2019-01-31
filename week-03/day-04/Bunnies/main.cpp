#include <iostream>

int bunnies(int input, int ears) {

    return input == 1 ? ears : bunnies(input-1, ears) + ears;
}

int main() {

    int sum = bunnies(10, 2);

    std::cout << sum;

    return 0;
}