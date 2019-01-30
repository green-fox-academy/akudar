#include <iostream>
#include "Car.h"
#include "Station.h"


Station::Station(int amount) {

    gasAmount = amount;
}

int Station::fill(Car tank) {

    while (!tank.isFull()) {

        if (gasAmount == 0) {

            std::cout << "Station is out of gas" << std::endl;

            return 0;
        }

        if (!tank.isFull()) {

            tank.fill();
            gasAmount--;
            std::cout << "Filling the car!" << std::endl;
        }
    }

    std::cout << "Remaining gas amount of the station: " << gasAmount << std::endl;

    return 1;
}