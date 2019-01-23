#include <iostream>
#include <exception>
#include <fstream>
#include <string>

// Write a program that opens a file called "my-file.txt", then prints
// each line from the file.
// You will have to create the file, you may use C-programming, although it is not mandatory

int main () {

    std::ifstream myFile;

    myFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {

        myFile.open("C:/Users/ASUS/Desktop/greenfox/my-file.txt");
        std::string text;

        while(getline(myFile, text)) {

            std::cout << text << std::endl;
        }
        myFile.close();
    }catch (std::ifstream::failure& e) {

        std::cout << e.what() << std::endl;
    }


    return 0;
}