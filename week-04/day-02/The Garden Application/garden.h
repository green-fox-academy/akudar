#ifndef THE_GARDEN_APPLICATION_GARDEN_H
#define THE_GARDEN_APPLICATION_GARDEN_H


#include <vector>
#include "tree.h"
#include "flower.h"

class Garden {

    std::vector<Tree> trees;
    std::vector<Flower> flowers;

public:
    Garden(int amountOfTree, int amountOfFlower);
    void distributeWater(int _amount);
};


#endif