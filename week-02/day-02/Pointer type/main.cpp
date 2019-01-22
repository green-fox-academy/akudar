#include <iostream>

// Create a pointer for each variable and print out the memory addresses of that variables
// Print out the values of the pointers

int main ()
{

    int a = 31;
    double b = 432.2;
    std::string name = "Bob";

    int* aP = &a;
    double* bP = &b;
    std::string* nameP = &name;

    std::cout << aP << std::endl << bP << std::endl <<  nameP << std::endl;
    std::cout << *aP << std::endl << *bP << std::endl << *nameP;

    return 0;
}