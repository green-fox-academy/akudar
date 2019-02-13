//
// Created by ASUS on 13/02/2019.
//

#include "Manager.h"

Manager::Manager() {
    moodLevel = 400;
}

void Manager::work() {
    xp++;
    haveAMeeting();
}

void Manager::haveAMeeting() {
    moodLevel -= xp;
}
