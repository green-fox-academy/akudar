#ifndef KLASSZ_WAITER_H
#define KLASSZ_WAITER_H


#include "Employees.h"

class Waiter : public Employees{

    int tips;

public:
    Waiter();
    void work() override;
};


#endif