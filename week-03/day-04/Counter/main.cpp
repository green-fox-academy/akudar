#include <iostream>

int countDown(int input) {

    std::cout << input << std::endl;

    if (input != 0) {

        return countDown(input-1);
    }

    return 0;
}

int main() {

    countDown(10);

    return 0;
}