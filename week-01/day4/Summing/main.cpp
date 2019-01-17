#include <iostream>
#include <string>

// - Write a function called `sum` that sum all the numbers
//   until the given parameter and returns with an integer

int sum (int input );

int main() {

    std::cout << sum(10) << std::endl;

    return 0;
}

int sum (int input ) {

    int a = 0;

    for (int i = input; i >= 0 ; i--) {

        a += i;
    }

    return a;
}