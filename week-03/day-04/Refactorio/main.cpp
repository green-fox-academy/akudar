#include <iostream>

int refactorio(int input) {

    return input == 1 ? input : input * refactorio(input - 1);
}

int main() {

    std::cout << refactorio(4);

    return 0;
}