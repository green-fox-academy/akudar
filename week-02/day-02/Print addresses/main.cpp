#include <iostream>

    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the memory addresses of the elements in the array

int main() {

    int inputArray[5];

    for (int i = 5; i > 0; --i) {

        std::cout << "enter " << i << " numbers" << std::endl;
        std::cin >> inputArray[i];
    }

    for (int j = 0; j < 5; ++j) {

        std::cout << &inputArray[j] << std::endl;
    }

    return 0;
}