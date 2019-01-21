#include <iostream>
#include <string>

// I would like to replace "dishwasher" with "galaxy" in this example, but it has a problem.
// Please fix it for me!
// Expected output: In a galaxy far far away

int main(int argc, char* args[])
{
    std::string example = "In a dishwasher far far away";
    std::string replacement = "galaxy";
    int startPos = example.find("dishwasher");

    example.replace(startPos,10 ,replacement);

    std::cout << example << std::endl;

    return 0;
}