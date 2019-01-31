#include <iostream>

std::string aPlus(std::string input, int size) {

    if (size - 1 == -1) {

        return input;
    } else {

        input.insert(size-1, 1, 'a');
        return aPlus(input, size - 1);
    }
}

int main() {

    std::cout << aPlus("sdfjnj", 6);

    return 0;
}