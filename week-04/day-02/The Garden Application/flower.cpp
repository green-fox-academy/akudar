#include <iostream>
#include "flower.h"

Flower::Flower(Color _color)
       : Plants(_color)
{
    setWater(0);
    setColor(_color);
}

void Flower::watering(double amount)
{
    if (getWater() < 5) {

        setWater(amount * 0.75);
        std::cout << "The " << getColor() << " Flower needs water" << std::endl;
    }
}