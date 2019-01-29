#include <string>
#ifndef SHARPIE_SHARPIE_H
#define SHARPIE_SHARPIE_H


class Sharpie {

    std::string color;
    float width, inkAmount;

public:
    Sharpie(std::string cColor, float cWidth);

    void use();
};


#endif
