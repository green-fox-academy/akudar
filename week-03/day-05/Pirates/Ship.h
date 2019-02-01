
#ifndef PIRATES_SHIP_H
#define PIRATES_SHIP_H

#include "Pirate.h"
#include <vector>

class Ship {

    std::vector<Pirate> crew;
    std::string name;

public:

    Ship(std::string *shipName);
    void fillShip();
    void shipsState();
    bool battle(Ship otherS);
    int scoreCalc();
    Pirate& getMember(int i);
};


#endif
