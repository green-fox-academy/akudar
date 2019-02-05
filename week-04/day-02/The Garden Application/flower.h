#ifndef THE_GARDEN_APPLICATION_FLOWER_H
#define THE_GARDEN_APPLICATION_FLOWER_H


#include "plants.h"

class Flower : public Plants{

public:
    Flower(Color _color);
    void watering(double amount) override;
};


#endif