#include <iostream>
#include <map>

void sorting(int *tomb, int size);
int sum(int szam1, int szam2);

int szam = 5;

int main() {

    std::map<std::string, int> namesToAges;

    namesToAges["Peti"] = 22;
    namesToAges["Marci"] = 48;

    //std::cout << szam << std::endl;

    szam += sum(namesToAges["Peti"], 48);

    //std::cout << szam << std::endl;

    int sizeOfArray = 5;
    int array[] = {5,2,9,6,3};

    sorting(array, sizeOfArray);

    return 0;
}

int sum(int szam1, int szam2) {

    int result = 0;

    result = szam1 + szam2;

    return result;
}

void sorting(int *tomb, int size) {

    int arrayClone[size];

    for (int j = 0; j < size; ++j) {

        arrayClone[j] = tomb[j];
    }

    int temp = 0;

    for (int k = 0; k < size; ++k) {
        for (int i = 0; i < size-1; ++i) {

            if (arrayClone[i+1] < arrayClone[i]) {

                temp = arrayClone[i];
                arrayClone[i] = arrayClone[i+1];
                arrayClone[i+1] = temp;
            }
        }
    }

    for (int l = 0; l < size; ++l) {

        std::cout << tomb[l] << " ";
    }

    std::cout << std::endl;

    for (int i = 0; i < size; ++i) {

        std::cout << arrayClone[i] << " ";
    }
}