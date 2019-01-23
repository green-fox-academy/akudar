#include <iostream>
#include <fstream>

// Create a function that takes a number
// divides ten with it,
// and prints the result.
// It should print "fail" if the parameter is 0

void divide(int input);

int main() {

    divide(5);

    return 0;
}

void divide(int input) {

    int result = 10;

    if (input != 0) {

        try {

            result /= input;
            std::cout << result;
        } catch (...) {
            std::cout << "wrong input";
        }
    } else {

        std::cout << "fail";
    }
}