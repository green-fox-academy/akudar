#ifndef PIRATES_PIRATE_H
#define PIRATES_PIRATE_H


class Pirate {

    int drinkCounter;
    int state; // 0 = dead, 1 = passed out, 2 = awake (default)

public:

    Pirate();

    void drinkSomeRum();
    void howIsItGoingMate();
    void die();
    int brawl(Pirate &otherP);
    int getRum();
    int getState();
    void setState(int value);
};


#endif
