#include <iostream>
#include <time.h>
#include "Ship.h"

int main() {

    srand(time(0));
    std::string ship1 = "FeketeGyongy";
    std::string ship2 = "Titanic";

    Ship FeketeGyongy(&ship1);
    FeketeGyongy.fillShip();
    for (int i = 0; i < 5; ++i) {

        FeketeGyongy.getMember(0).drinkSomeRum();
    }

    FeketeGyongy.getMember(0).howIsItGoingMate();
    FeketeGyongy.getMember(3).brawl(FeketeGyongy.getMember(5));
    FeketeGyongy.shipsState();

    Ship Titanic(&ship2);
    Titanic.fillShip();

    FeketeGyongy.battle(Titanic);

    return 0;
}