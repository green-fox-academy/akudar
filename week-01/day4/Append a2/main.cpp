#include <iostream>
#include <string>

// - Create an array variable named `animals`
//   with the following content: `["koal", "pand", "zebr"]`
// - Add all elements an `"a"` at the end

int main() {

    std::string animals[] = {"koal", "pand", "zebr"};

    for (int i = 0; i < sizeof(animals)/ sizeof(animals[0]); i++) {

        animals[i].append("a");
    }

    for (int j = 0; j < 3; ++j) {

        std::cout << animals[j] << std::endl;
    }

    return 0;
}