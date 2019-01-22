#include <iostream>

    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the values of that array using pointers again

int main() {

    int inputArray[5];

    for (int i = 4; i >= 0 ; --i) {

        std::cout << "enter " << i+1 << " numbers" << std::endl;
        std::cin >> inputArray[i];
    }

    int* indexP = inputArray;

    for (int j = 0; j < 5; ++j) {

        std::cout << *(inputArray+j) << std::endl;
    }

    return 0;
}