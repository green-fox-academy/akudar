#include <iostream>

int add(int input) {

    return (input == 0 ? input : add(input-1) + input);
}

int main() {

    int sum = add(10);

    std::cout << sum;

    return 0;
}