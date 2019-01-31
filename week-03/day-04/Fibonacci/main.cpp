#include <iostream>

int fibonacci(int index, int value1, int value2) {

    if (index == 1) {

        return value2;
    } else {

        return fibonacci(index - 1, value2, value1 + value2);
    }
}

int main() {

    std::cout << fibonacci(5, 0, 1);

    return 0;
}