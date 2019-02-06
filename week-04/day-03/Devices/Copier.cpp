#include <iostream>
#include "Copier.h"

Copier::Copier(int x, int y, int speed)
        : Printer2D(x, y),Scanner(speed)
{
    Printer2D::set_sizeX(x);
    Printer2D::set_sizeY(y);
    Scanner::set_speed(speed);
}

void Copier::copy()
{
    scan();
    std::cout << " and ";
    print();
}