#include <iostream>
#include <limits.h>

// Create a program which first asks for a number
// this number indicates how many integers we want to store in an array
// and than asks for numbers till the user fills the array
// It should print out the biggest number in the given array and the memory address of it

int main() {

    int size = 0;

    std::cout << "please enter the size of the array" << std::endl;
    std::cin >> size;

    int array[size];

    for (int i = 0; i < size; ++i) {

        std::cout << "please enter " << size << " numbers to the array" << std::endl;
        std::cin >> array[i];
    }

    int max = INT_MIN;

    for (int j = 0; j < size; ++j) {

        if (max < array[j]) {

            max = array[j];
        }
    }

    std::cout << max << std::endl << &max << std::endl;

    return 0;
}