#ifndef KLASSZ_EMPLOYEES_H
#define KLASSZ_EMPLOYEES_H


#include <string>

class Employees
{
protected:
    std::string eName;
    int xp;

public:
    Employees();
    Employees(int xpInput);
    virtual void work() = 0;
};


#endif