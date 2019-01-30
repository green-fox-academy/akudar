
#ifndef PETROL_STRATION_CAR_H
#define PETROL_STRATION_CAR_H


class Car {

    int gasAmount;
    int capacity;

public:

    Car(int amount, int tank);

    bool isFull();
    void fill();
};


#endif