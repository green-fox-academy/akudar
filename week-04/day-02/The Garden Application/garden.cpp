#include <iostream>
#include "garden.h"


Garden::Garden(int amountOfTree, int amountOfFlower)
{
    for (int i = 0; i < amountOfTree; ++i) {
        trees.push_back(Tree(YELLOW));
        std::cout << "The " << trees[i].getColor() << " Tree needs water" << std::endl;
    }

    for (int j = 0; j < amountOfFlower; ++j) {
        flowers.push_back(Flower(BLUE));
        std::cout << "The " << trees[j].getColor() << " flower needs water" << std::endl;
    }
}

void Garden::distributeWater(int _amount)
{
    std::cout << "Watering with " << _amount <<std::endl;
    double amount;
    std::vector<int> treeIndex;
    std::vector<int> flowerIndex;

    for (int k = 0; k < trees.size(); ++k) {
        if (trees[k].getWater() < 10) {
            treeIndex.push_back(k);
        } else {
            std::cout << "The " << trees[k].getColor() << " Tree doesnt need water" << std::endl;
        }
    }

    for (int l = 0; l < flowers.size(); ++l) {
        if (flowers[l].getWater() < 5) {
            flowerIndex.push_back(l);
        } else {
            std::cout << "The " << trees[l].getColor() << " Flower doesnt need water" << std::endl;
        }
    }

    amount = _amount / (treeIndex.size() + flowerIndex.size());

    for (int i = 0; i < treeIndex.size(); ++i) {
        trees[treeIndex[i]].watering(amount);
    }

    for (int j = 0; j < flowerIndex.size(); ++j) {
        flowers[flowerIndex[j]].watering(amount);
    }
}