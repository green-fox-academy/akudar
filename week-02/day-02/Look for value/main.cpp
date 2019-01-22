#include <iostream>

    // Create a function which takes an array (and it's lenght) and a number as a parameter
    // the function should return index where it found the given value
    // if it can't find the number return 0

int index(int array[], int size, int value);

int main() {

    int array[5] = {5, 7, 8, 2, 1};

    std::cout << index(array, 5, 4) << std::endl;

    return 0;
}

int index(int array[], int size, int value) {

    int arrayClone[size];

    for (int i = 0; i < size; ++i) {

        arrayClone[i] = array[i];
    }
    for (int j = 0; j < size; ++j) {

        if (arrayClone[j] == value) {

            return j;
        }
    }

    return -1;
}