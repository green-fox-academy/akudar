#include "Chef.h"

void Chef::work() {
    xp++;
}

void Chef::cook(std::string nInput) {
    if (meals.count(nInput)) {
        meals[nInput]++;
    } else {
        meals[nInput] = 1;
    }
}

const std::map<std::string, int> &Chef::getMeals() const {
    return meals;
}
