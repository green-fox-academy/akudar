#include <iostream>
#include <fstream>
#include <string>

    // Open a file called "my-file.txt"
    // Write your name in it as a single line

int main() {

    std::ofstream myFile;
    std::string myName = "Adam Kudar";

    myFile.open("C:/Users/ASUS/Desktop/greenfox/my-file.txt");
    myFile << myName;
    myFile.close();

    return 0;
}