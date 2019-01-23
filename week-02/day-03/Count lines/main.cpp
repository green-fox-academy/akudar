#include <iostream>
#include <fstream>
#include <string>

    // Write a function that takes a filename as string,
    // then returns the number of lines the file contains.
    // It should return zero if it can't open the file

int count(std::string filename);

int main () {

    std::string source = "C:/Users/ASUS/Desktop/greenfox/my-file.txt";

    std::cout << count(source);

    return 0;
}

int count(std::string filename) {

    int counter = 0;
    std::ifstream myFile;
    std::string line;

    try {

        myFile.open(filename);
        while (getline(myFile, line)) {

            counter++;
        }
        myFile.close();
        return counter;

    } catch (...) {

        return counter;
    }
}