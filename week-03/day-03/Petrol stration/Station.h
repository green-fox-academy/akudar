#include "Car.h"
#ifndef PETROL_STRATION_STATION_H
#define PETROL_STRATION_STATION_H


class Station {

    int gasAmount;

public:

    Station(int amount);
    int fill(Car tank);
};


#endif
