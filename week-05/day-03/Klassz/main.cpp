#include <iostream>
#include "Restaurant.h"
#include "Manager.h"
#include "Chef.h"
#include "Waiter.h"

int main() {

    Restaurant restaurant;
    Manager manager;
    Chef chef;
    Waiter waiter;

    restaurant.hire(manager);
    restaurant.hire(chef);
    restaurant.hire(waiter);

    restaurant.guestsArrived();
    chef.cook("bab");
    chef.cook("bab");
    chef.cook("repa");

    return 0;
}