#include <iostream>
#include <string>
#include "Pirate.h"

Pirate::Pirate() {

    state = 2;
    drinkCounter = 0;
}

int Pirate::getRum() {

    return drinkCounter;
}

int Pirate::getState() {

    return state;
}

void Pirate::drinkSomeRum() {

    drinkCounter++;
}

void Pirate::setState(int value) {

    state = value;
}

void Pirate::howIsItGoingMate() {

    if (drinkCounter < 5 && state != 0) {

        std::cout << "Pour me anudder!" << std::endl;
        drinkCounter = 0;
        state = 2;
    }
    else if (drinkCounter > 4 && state != 0){

        std::cout << "Arghh, I'ma Pirate. How d'ya d'ink its goin?" << std::endl;
        state = 1;
    } else {

        std::cout << "This pirate is dead!" << std::endl;
    }
}

void Pirate::die() {

    state = 0;
}

int Pirate::brawl(Pirate &otherP) {

    if (state == 0 || otherP.getState() == 0) {

        std::cout << "This pirate is dead!" << std::endl;

        return 1;
    }

    int random = 1 + (rand() % 3);

    switch (random) {

        case 1: state = 0;
                std::cout << "The defender died!" << std::endl;
            break;
        case 2: otherP.die();
                std::cout << "The challenger died!" << std::endl;
            break;
        case 3: state = 1;
                otherP.setState(1);
                std::cout << "The both got passed out" << std::endl;
            break;
    }

    return 0;
}