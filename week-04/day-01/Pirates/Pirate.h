#ifndef PIRATES_PIRATE_H
#define PIRATES_PIRATE_H

#include <string>


class Pirate
{
    std::string name;
    int gold, hP;
    bool isCaptain, isWoodenLeg;

public:
    Pirate(int cName);
    std::string work();
    std::string party();
    int getGold();
    std::string getName();
    void setCaptain();
    bool getLeg();
};


#endif
