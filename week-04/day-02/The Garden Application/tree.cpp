#include <iostream>
#include "tree.h"


Tree::Tree(Color _color)
    : Plants(_color)
{
    setWater(0);
    setColor(_color);
}

void Tree::watering(double amount)
{
    if (getWater() < 10) {

        setWater(amount*0.4);
        std::cout << "The " << getColor() << " Tree needs water" << std::endl;
    }
}