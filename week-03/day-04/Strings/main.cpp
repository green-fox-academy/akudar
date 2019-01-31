#include <iostream>
#include <string>

std::string xToY (std::string input, int size) {

    if (size - 1 == -1) {

        return input;
    }
    else if (input[size-1] == 'x') {

        input[size-1] = 'y';
        return xToY(input, size - 1);
    }
    else if (input[size-1] != 'x') {

        return xToY(input, size-1);
    }

    return "";
}

int main() {

    std::string output = "xxasdx";

    std::cout << xToY("xxasdx" , 6);

    return 0;
}