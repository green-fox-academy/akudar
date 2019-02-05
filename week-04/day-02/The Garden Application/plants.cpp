#include "plants.h"

Plants::Plants(Color _color)
{
    water = 0;
    color = _color;
}

void Plants::watering(double amount)
{
    setWater(amount);
}

double Plants::getWater() const {
    return water;
}

void Plants::setWater(double water) {
    Plants::water = water;
}

Color Plants::getColor() const {
    return color;
}

void Plants::setColor(Color color) {
    Plants::color = color;
}
