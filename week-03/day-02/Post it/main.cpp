#include <iostream>
#include "PostIt.h"

int main() {

    PostIt postIt("Idea 1", "blue", "orange");
    PostIt postIt1("Awesome","black", "pink");
    PostIt postIt2("Superb!", "green", "yellow");

    std::cout << postIt.textColor;

    return 0;
}