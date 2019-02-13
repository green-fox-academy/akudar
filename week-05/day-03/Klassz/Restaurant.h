#ifndef KLASSZ_RESTAURANT_H
#define KLASSZ_RESTAURANT_H


#include <string>
#include <vector>
#include "Employees.h"

class Restaurant
{

    std::string rName;
    int founded;
    std::vector<Employees*> list;

public:

    void guestsArrived();
    void hire(Employees &employees);
};


#endif