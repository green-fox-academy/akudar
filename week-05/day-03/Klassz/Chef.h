#ifndef KLASSZ_CHEF_H
#define KLASSZ_CHEF_H


#include <map>
#include "Employees.h"

class Chef : public Employees{

    std::map<std::string, int> meals;
public:
    const std::map<std::string, int> &getMeals() const;

public:
    void work() override;
    void cook(std::string nInput);

};


#endif