#include <iostream>
#include <string>

// Create two integer variables: a=15, b=23
// Create a function named swap that gets the 2 integers as parameters and swaps its values.
// Print the values before and after the function call and make sure the values are printed in reversed order.

void swap (int input, int input2);

int main() {

    int a = 15;
    int b = 23;

    std::cout << "a = " << a << std::endl << "b = " << b << std::endl;

    swap(a,b);

    std::cout << "a = " << a << std::endl << "b = " << b << std::endl;

    return 0;
}

void swap (int& input, int& input2){

    int x;

    x = input;
    input = input2;
    input2 = x;
}