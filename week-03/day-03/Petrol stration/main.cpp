#include <iostream>
#include "Station.h"
#include "Car.h"

int main() {

    Station station(1000);
    Car mercedesGLE63V8BiTurbo(20, 80);
    Car audiS6(15, 70);
    Car bMWM6(50, 80);
    Car trabant(5, 40);
    Car jeepGrandCheeroke65(31, 90);

    station.fill(mercedesGLE63V8BiTurbo);
    station.fill(audiS6);
    station.fill(bMWM6);
    station.fill(trabant);
    station.fill(jeepGrandCheeroke65);

    return 0;
}