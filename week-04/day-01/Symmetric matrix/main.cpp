#include <iostream>

bool isSymmetric(int **matrix, int column, int size)
{
    int tempMatrix[column][size;

    for (int i = 0; i < column; ++i) {
        for (int j = 0; j < size; ++j) {

            tempMatrix[i][j] = matrix[i][j];
        }
    }

    for (int k = 0; k < column; ++k) {
        for (int i = 0; i < size; ++i) {

            if (tempMatrix[k][i] != tempMatrix[k][size-i]) {
                return false;
            }
        }
    }

    return true;
}


int main() {

    return 0;
}