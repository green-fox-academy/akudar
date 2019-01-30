
#include "Car.h"


Car::Car(int amount, int tank) {

    gasAmount = amount;
    capacity = tank;
}

void Car::fill() {

    gasAmount++;
}

bool Car::isFull() {

    if (gasAmount == capacity) {

        return true;
    }

    return false;
}