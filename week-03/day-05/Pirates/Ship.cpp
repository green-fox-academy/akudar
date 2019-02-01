#include <string>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include "Ship.h"
#include "Pirate.h"

Ship::Ship(std::string shipName) {

    name = shipName;
}

void Ship::fillShip() {

    int random = rand() % 20 + 10;

    for (int i = 0; i < random; i++) {

        crew.push_back(Pirate());
    }

    std::cout << name << " has got a Captain and " << random << " crew member" << std::endl;
}

void Ship::shipsState() {

    switch (crew[0].getState()) {

        case 0: std::cout << "The Captain is dead! Number of crew: " << crew.size() << std::endl;
            break;
        case 1: std::cout << "The Captain is alive, but passed out! Number of crew: " << crew.size() << std::endl;
            break;
        case 2: std::cout << "The Captain is awake! Number of crew: " << crew.size() << std::endl;
            break;
    }
}

bool Ship::battle(Ship otherS) {

    std::cout << name << " is going to battle with " << otherS.name << std::endl;

    int random = rand() % 10 + 1;

    if (this->scoreCalc() > otherS.scoreCalc()) {

        for (int i = 1; i < random; ++i) {

            crew[i].die();
        }

        std::cout << otherS.name << " lost the battle and " << random << " crew members!" << std::endl;

        return true;
    }else{

        for (int i = 1; i < random; ++i) {

            crew[i].die();
        }

        std::cout << name << " lost the battle and " << random << " crew members!" << std::endl;

        return false;
    }
}

int Ship::scoreCalc() {

    int score = 0;

    for (int i = 0; i < crew.size(); ++i) {

        if (crew[i].getState() != 0) {
            score++;
        }
    }

    score += crew[0].getRum();

    return score;
}

Pirate& Ship::getMember(int i) {

    return crew[i];
}