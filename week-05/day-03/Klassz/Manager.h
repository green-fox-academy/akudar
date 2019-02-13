#ifndef KLASSZ_MANAGER_H
#define KLASSZ_MANAGER_H


#include "Employees.h"

class Manager : public Employees{

    int moodLevel;

public:
    Manager();
    void work() override;
    void haveAMeeting();
};


#endif