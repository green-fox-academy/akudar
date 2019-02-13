#include <iostream>
#include <string>

//  Create a function that takes a list of numbers as a parameter
//  Don't forget you have pass the size of the list as a parameter as well
//  Returns a list of numbers where every number in the list occurs only once

//  Example
// int numbers[] = {1, 11, 34, 11, 52, 61, 1, 34};
// std::cout << (unique(numbers)) << std::endl;
//  should print: `[1, 11, 34, 52, 61]`

int* unique(int inputArray[], int sizeOfArray);

int main() {

    int withDuplicate[] = {1,3,6,2,7,7,8};

    int* p = unique(withDuplicate, 7);

    for (int i = 0; i < 6; ++i) {

        std::cout << p[i] << std::endl;
    }


    return 0;
}

int* unique(int inputArray[], int sizeOfArray) {

    bool isDuplicate;
    int size = 0;

    for (int i = 0; i < sizeOfArray-1; ++i) {

        isDuplicate = false;
        for (int j = i+1; j < sizeOfArray; ++j) {

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

    for (int k = 0; k < sizeOfArray-1; ++k) {

        isDuplicate = false;
        for (int i = k+1; i < sizeOfArray; ++i) {

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