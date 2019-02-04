#include "Pirate.h"
#include <string>


Pirate::Pirate(int cName)
{
    isCaptain = false;
    name = cName;
    hP = 10;
}

std::string Pirate::work()
{
    if (isCaptain) {
        gold += 10;
        hP -= 5;
    } else {
        gold += 1;
        hP -= 1;
    }

    if (isWoodenLeg) {
        return "Hello, I'm Jack. I have a wooden leg and 20 golds.";
    } else {
        return "Hello, I'm Jack. I still have my real legs and 20 golds. ";
    }
}

std::string Pirate::party()
{
    if (isCaptain) {
        hP += 10;
    } else {
        hP += 1;
    }

    if (isWoodenLeg) {
        return "Hello, I'm Jack. I have a wooden leg and 20 golds.";
    } else {
        return "Hello, I'm Jack. I still have my real legs and 20 golds. ";
    }
}

int Pirate::getGold()
{
    return gold;
}

std::string Pirate::getName()
{
    return name;
}

void Pirate::setCaptain()
{
    isCaptain = true;
}

bool Pirate::getLeg()
{
    return isWoodenLeg;
}