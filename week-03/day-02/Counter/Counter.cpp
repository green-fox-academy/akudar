
#include "Counter.h"

Counter::Counter() {

    value = 0;
    iValue = 0;
}

Counter::Counter(int number) {

    value = number;
    iValue = number;
}

void Counter::add() {

    value++;
}

void Counter::add(int number) {

    value += number;
}

int Counter::get() {

    return value;
}

void Counter::reset() {

    value = iValue;
}