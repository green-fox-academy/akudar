#include <iostream>
#include <string>

// - Create (dynamically) a two dimensional array
//   with the following matrix. Use a loop!
//   by dynamically, we mean here that you can change the size of the matrix
//   by changing an input value or a parameter or this combined
//
//   1 0 0 0
//   0 1 0 0
//   0 0 1 0
//   0 0 0 1
//
// - Print this two dimensional array to the output

void sizeOfMatrix(int rows, int columns);

int main() {

    sizeOfMatrix(4,4);

    return 0;
}

void sizeOfMatrix(int rows, int columns){

    int matrix[rows][columns];
    int x = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {

            if (j == x) {

                std::cout << 1;
            } else{
                std::cout << 0;
            }
            std::cout << " ";
        }

        std::cout << std::endl;
        x++;
    }
}