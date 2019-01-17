#include <iostream>
#include <string>


void greet(std::string input);

int main() {

    std::string al = "Greenfox";

    greet(al);

    return 0;
}

void greet(std::string input) {

    std::cout << "Greetings dear, " << input << std::endl;
}