#include "Dice_set.h"

#include <stdlib.h>
#include <time.h>

Dice_set::Dice_set()
{
    srand(time(nullptr));
    dices = std::vector<int>(6);
}

void Dice_set::roll()
{
    for (int i = 0; i < dices.size(); i++) {
        dices[i] = (int) (rand() % 6) + 1;
    }
}

void Dice_set::roll(int i)
{
    dices[i] = (int) (rand() % 6) + 1;
}

std::vector<int> Dice_set::getCurrent() const
{
    return dices;
}

int Dice_set::getCurrent(int i) const
{
    return dices[i];
}