#include <vector>
#include "Ship.h"
#include <string>
#include <time.h>


void Ship::fillCrew()
{
    srand(time(NULL));
    int random = rand() % 20 + 10;

    for (int i = 0; i < random; i++) {
        crew.push_back(Pirate(i));
        if (i == 0) {
            crew[0].setCaptain();
        }
    }
}

std::vector<std::string> Ship::getPoorPirates(std::vector<Pirate> crewMembers)
{
    static std::vector<std::string> poorPirates;

    for (int j = 0; j < crewMembers.size(); ++j) {
        if (crewMembers[0+j].getGold() < 15 && crewMembers[0+j].getLeg()) {
            poorPirates.push_back(crewMembers[j].getName());
        }
    }

    return poorPirates;
}

void Ship::lastDayOnTheShip(std::vector<Pirate> crewMembers)
{
    for (int i = 0; i < crewMembers.size(); ++i) {
        crewMembers[i].party();
    }
}

void Ship::prepareForBattle(std::vector<Pirate> crewMembers)
{
    for (int j = 0; j < crewMembers.size(); ++j) {
        for (int i = 0; i < 5; ++i) {
            crewMembers[j].work();
        }
    }

    lastDayOnTheShip(crew);
}

int Ship::getGolds(std::vector<Pirate> crewMembers)
{
    int sum = 0;

    for (int j = 0; j < crewMembers.size(); ++j) {
        sum += crewMembers[0+j].getGold();
    }

    return sum;
}