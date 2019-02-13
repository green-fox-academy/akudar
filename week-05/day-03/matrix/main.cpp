#include <iostream>
#include <vector>

std::vector<std::vector<int>> rotateMatrix(std::vector<std::vector<int>> matr)
{
    std::vector<std::vector<int>> resultMatrix = matr;


    int element = matr[0][0];
    // mirror matrix on diagonal axis
    for (int i = 0; i < matr.size(); i++) {
        std::vector<int> row;

        for (int j = 0; j < matr[i].size(); j++) {
            row.push_back(matr[j][i]);

        }
        resultMatrix.push_back(row);
    }


    // mirror matrix on central vertical axis
    std::vector<std::vector<int>> finalResultMatrix;

    for (int i = 0; i < matr.size(); i++) {
        std::vector<int> row;

        for (int j = 0; j < matr[i].size(); j++) {
            for (int j = 0; j < matr.size(); j++) {
                finalResultMatrix[i][j] = resultMatrix[i][matr.size() - j - 1];

            }
        }

    }


    int size = finalResultMatrix.size() - 1;
    for (int i = 0; i < finalResultMatrix.size(); i++) {
        for (int j = 0; j < finalResultMatrix.size(); j++) {
            element = finalResultMatrix[i][j];
            finalResultMatrix[i][j] = finalResultMatrix[size - j][i];
            finalResultMatrix[size - j][i] = element;

            std::cout << resultMatrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    return finalResultMatrix;
}

int main() {
    int element;
    std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            std::cout << matrix[i][j] << " ";

        }
        std::cout << "\n";

    }
    std::cout << "\n";
    std::string text = {"yoloswag"};
    //rotateMatrix(matrix);
    int size = matrix.size() - 1;
    std::vector<std::vector<int>> rm = matrix;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            rm[i][size - j] = matrix[j][i];
            std::cout << rm[i][size - j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}