#include <iostream>
#include <string>

// - Create a function called `factorio`
//   it should calculate its input's factorial.
//   it should not return it, but take an additional integer parameter and overwrite its value.

void factorio (int input, int& param);

int main() {

    int input1 = 3;
    int input2 = 5;

    factorio(input1, input2);

    std::cout << input2;

    return 0;
}

void factorio (int input, int& param) {

    int a = input;

    for (int i = input-1; i > 0; i--) {

        a *= i;
    }

    param = a;
}