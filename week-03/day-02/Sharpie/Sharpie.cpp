#include <string>
#include "Sharpie.h"

Sharpie::Sharpie(std::string cColor, float cWidth) {

    color = cColor;
    width = cWidth;
    inkAmount = 100;
}
void Sharpie::use() {

    inkAmount--;
}