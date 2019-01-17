#include <iostream>
#include <string>

// - Create an array variable named `abc`
//   with the following content: `["first", "second", "third"]`
// - Swap the first and the third element of `abc`

int main() {

    std::string abc[] = {"first", "second", "third"};

    std::string first = abc[0];
    abc[0] = abc[2];
    abc[2] = first;

    return 0;
}