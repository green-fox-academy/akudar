#include <iostream>
#include <fstream>
#include <string>

// Write a function that reads all lines of a file and writes the read lines to an other file (a.k.a copies the file)
// It should take the filenames as parameters
// It should return a boolean that shows if the copy was successful

bool copy(std::string path, std::string path2);

int main() {

    std::cout << copy("C:/Users/ASUS/Desktop/greenfox/my-file.txt", "C:/Users/ASUS/Desktop/greenfox/my-file2.txt");

    return 0;
}

bool copy(std::string path, std::string path2) {

    bool isDone = false;
    std::ifstream read;
    std::string line;
    std::ofstream write;

    read.open(path);
    write.open(path2);

    if (read.is_open() && write.is_open())
        isDone = true;

    while (getline(read, line)) {

        write << line << std::endl;
    }

    read.close();
    write.close();

    return isDone;
}