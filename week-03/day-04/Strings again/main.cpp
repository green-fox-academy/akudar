#include <iostream>
#include <string>

std::string xRemoved(std::string input, int size) {

    if (size - 1 == -1) {

        return input;
    }
    else if (input[size-1] == 'x') {

        input.erase(size-1, 1);
        return xRemoved(input, size - 1);
    }
    else if (input[size-1] != 'x') {

        return xRemoved(input, size - 1);
    }

    return 0;
}

int main() {

    std::cout << xRemoved("xghxft", 6);

    return 0;
}