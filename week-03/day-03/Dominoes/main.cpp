#include <iostream>
#include <vector>

#include "Domino.h"

std::vector<Domino> initializeDominoes()
{
    std::vector<Domino> dominoes;
    dominoes.push_back(Domino(5, 2));
    dominoes.push_back(Domino(4, 6));
    dominoes.push_back(Domino(1, 5));
    dominoes.push_back(Domino(6, 7));
    dominoes.push_back(Domino(2, 4));
    dominoes.push_back(Domino(7, 1));
    return dominoes;
}

int main(int argc, char* args[])
{
    std::vector<Domino> dominoes = initializeDominoes();
    // You have the list of Dominoes
    // Order them into one snake where the adjacent dominoes have the same numbers on their adjacent sides
    // eg: [2, 4], [4, 3], [3, 5] ...

    Domino temp(dominoes[0].getValues().first, dominoes[0].getValues().second);

    for (int j = 1; j < dominoes.size(); ++j) {

        if (dominoes[0].getValues().first > dominoes[j].getValues().first) {

            temp = dominoes[0];
            dominoes[0] = dominoes[j];
            dominoes[j] = temp;
        }
    }

    for (int i = 0; i < dominoes.size(); ++i) {

        for (int j = 1; j < dominoes.size(); ++j) {

            if (dominoes[i].getValues().second == dominoes[j].getValues().first) {

                temp = dominoes[i+1];
                dominoes[i+1] = dominoes[j];
                dominoes[j] = temp;
            }
        }
    }

    for (int k = 0; k < dominoes.size(); ++k) {

        std::cout << dominoes[k].toString();
    }

    return 0;
}