#include <iostream>
#include <limits.h>

// Create a function which takes an array (and its length) as a parameter
// and returns a pointer to its minimum value

int* minValue (int array[], int size);

int main() {

    int numbers[] = {12, 4, 66, 101, 87, 3, 15};

    minValue(numbers, 7);

    return 0;
}

int* minValue ( int array[], int size) {

    int* valueP = nullptr;
    int min = INT_MAX;
    int index = size;
    int arrayClone[size];

    for (int j = 0; j < size; ++j) {

        arrayClone[j] = array[j];
    }

    for (int i = 0; i < size; ++i) {

        if (min > arrayClone[i]) {

            min = arrayClone[i];
            index = i;
        }
    }

    valueP = &arrayClone[index];

    std::cout << valueP << " " << *valueP << std::endl;
    return valueP;
}