#include <iostream>
#include <string>
#include <fstream>
#include <exception>

char mostCommonChar(std::string fileName)
{
    char mostCommon;
    std::ifstream myFile;
    std::string text;

    try {
        if (true) {
            myFile.open(fileName);
        } else {
            throw 0;
        }

    }catch (int e) {
        std::cout << "File does not exist!" << std::endl;
    }
    getline(myFile, text);
    for (int i = 0; i < text.size(); ++i) {
        if (text[i]) {

        }
    }
    myFile.close();

    return mostCommon;
}


int main() {

    return 0;
}