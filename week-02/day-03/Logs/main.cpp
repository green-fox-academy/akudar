#include <iostream>
#include <fstream>
#include <string>

// Read all data from 'log.txt'.
// Each line represents a log message from a web server
// Write a function that returns an array with the unique IP adresses.
// Write a function that returns the GET / POST request ratio.

std::string* uniqueIP(std::string array[], int size);
void ratio();

int main() {

    int size = 0;
    int size2 = 0;
    std::ifstream readFile;
    std::string line;
    readFile.open("C:/Users/ASUS/Desktop/greenfox/Log.txt");

    while (getline(readFile, line)) {

        size++;
    }

    readFile.close();

    std::string bigArray[size];

    readFile.open("C:/Users/ASUS/Desktop/greenfox/Log.txt");

    for (int i = 0; i < size; ++i) {

        std::string tempLine;
        std::string tempIP = "";
        getline(readFile, tempLine);

        for (int j = 27; j < 38; ++j) {

            tempIP.append(1, tempLine[j]);
        }
        bigArray[i] = tempIP;
    }

    readFile.close();


    for (int k = 0; k < size; ++k) {
        bool isDuplicate = false;
        for (int i = 0; i < size; ++i) {

            if (k != i) {
                if (bigArray[k] == bigArray[i]) {
                    isDuplicate = true;
                }
            }
        }
        if (!isDuplicate)
            size2++;
    }

    std::cout << size2;
    //uniqueIP(bigArray, size);

    return 0;
}


std::string* uniqueIP(std::string array[], int size) {

}

void ratio() {


}