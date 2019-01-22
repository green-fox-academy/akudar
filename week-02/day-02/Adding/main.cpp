#include <iostream>

// Add two numbers using pointers

int main() {

    int a = 20;
    int b = 17;
    int* aP = &a;
    int* bP = &b;

    std::cout << *aP + *bP << std::endl;

    return 0;
}