#include <iostream>
#include <fstream>
#include <string>

// Create a function that takes 3 parameters: a path, a word and a number,
// than it should write to a file.
// The path parameter should describes the location of the file.
// The word parameter should be a string, that will be written to the file as lines
// The number paramter should describe how many lines the file should have.
// So if the word is "apple" and the number is 5, than it should write 5 lines
// to the file and each line should be "apple"

void write(std::string path, std::string word, int number);

int main() {

    write("C:/Users/ASUS/Desktop/greenfox/my-file.txt", "apple", 5);

    return 0;
}

void write(std::string path, std::string word, int number) {

    std::ofstream myFile;
    int counter = 0;

    myFile.open(path);

    while (counter != number) {

        myFile << word << std::endl;
        counter++;
    }
    myFile.close();
}