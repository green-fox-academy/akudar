#ifndef PIRATES_SHIP_H
#define PIRATES_SHIP_H

#include <vector>
#include "Pirate.h"
#include <string>


class Ship
{
    std::vector<Pirate> crew;

public:

    void fillCrew();
    std::vector<std::string> getPoorPirates(std::vector<Pirate> crewMembers);
    int getGolds(std::vector<Pirate> crewMembers);
    void lastDayOnTheShip(std::vector<Pirate> crewMembers);
    void prepareForBattle(std::vector<Pirate> crewMembers);

};


#endif
