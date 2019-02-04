#include <iostream>
#include <string>
#include <fstream>
#include <exception>

char mostCommonChar(std::string fileName)
{
    char mostCommon;
    int counter = 0;
    int mostUsed = 0;
    std::ifstream myFile;
    std::string text;

    try {
        if (myFile.good()) {
            myFile.open(fileName);
        } else {
            throw 0;
        }

    }catch (int e) {
        std::cout << "File does not exist!" << std::endl;
    }
    getline(myFile, text);

    for (int j = 0; j < text.size(); ++j) {
        for (int i = 0; i < text.size(); ++i) {
            if (text[j] == text[i]) {
                counter++;
            }
        }
        if (mostUsed < counter) {
            mostUsed = counter;
        }
    }
    myFile.close();

    return mostCommon;
}


int main() {

    return 0;
}