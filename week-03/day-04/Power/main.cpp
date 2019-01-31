#include <iostream>

int onPower(int base, int power) {


    return power == 1 ? base * base : base * onPower(base, power - 1);
}

int main() {

    int sum = onPower(2, 3);

    std::cout << sum;

    return 0;
}