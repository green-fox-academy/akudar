#include <iostream>

// Create a function which swaps the values of 'a' and 'b'
// This time use a void funtion and pointers

void swap(int* aP, int* bP);

int main () {

    int a = 10;
    int b = 316;

    swap(&a, &b);

    std::cout << a << " " << b << std::endl;

    return 0;
}

void swap(int* aP, int* bP) {

    int tempPointer;

    tempPointer = *aP;
    *aP = *bP;
    *bP = tempPointer;
}