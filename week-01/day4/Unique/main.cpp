#include <iostream>
#include <string>

//  Create a function that takes a list of numbers as a parameter
//  Don't forget you have pass the size of the list as a parameter as well
//  Returns a list of numbers where every number in the list occurs only once

//  Example
// int numbers[] = {1, 11, 34, 11, 52, 61, 1, 34};
// std::cout << (unique(numbers)) << std::endl;
//  should print: `[1, 11, 34, 52, 61]`

int* unique(int inputArray[]);

int main() {

    int withDuplicate[] = {1,3,6,2,4,7,7};

    std::cout << unique(withDuplicate);

    return 0;
}

int* unique(int inputArray[]) {

    bool isDuplicate = false;
    int size = 0;

    for (int i = 0; i < sizeof(inputArray)/ sizeof(inputArray[0]); ++i) {
        for (int j = 0; j < sizeof(inputArray)/ sizeof(inputArray[0]); ++j) {

            if (inputArray[i] == inputArray[j]){

                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {

            size++;
        }
    }

    int noDuplicate[size];

    for (int k = 0; k < sizeof(inputArray)/ sizeof(inputArray[0]); ++k) {
        for (int i = 0; i < sizeof(inputArray)/ sizeof(inputArray[0]); ++i) {

            if (inputArray[k] == inputArray[i]) {

                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {

            noDuplicate[k] = inputArray[k];
        }
    }

    return noDuplicate;
}