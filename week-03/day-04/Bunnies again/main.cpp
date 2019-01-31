#include <iostream>

int bunnies(int input, int ears) {

    if (input == 0) {

        return ears;
    }
    else if (input % 2 == 0) {

        return bunnies(input - 1, ears + 2);
    }
    else if (input % 2 != 0) {

        return bunnies(input - 1, ears + 3);
    }

    return 0;
}

int main() {

    std::cout << bunnies(10, 0);

    return 0;
}