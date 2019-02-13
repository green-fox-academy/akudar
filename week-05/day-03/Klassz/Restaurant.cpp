#include "Restaurant.h"

void Restaurant::guestsArrived() {
    for (int i = 0; i < list.size(); ++i) {
        list[i]->work();
    }
}

void Restaurant::hire(Employees &employee) {
    list.push_back(&employee);
}
