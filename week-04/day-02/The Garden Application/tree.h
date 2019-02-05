#ifndef THE_GARDEN_APPLICATION_TREE_H
#define THE_GARDEN_APPLICATION_TREE_H


#include "plants.h"

class Tree : public Plants{

public:
    Tree(Color _color);
    void watering(double amount) override;
};


#endif