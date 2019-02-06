#include <iostream>
#include "Printer2D.h"

Printer2D::Printer2D(int x, int y)
{
    _sizeX = x;
    _sizeY = y;
}

std::string Printer2D::getSize()
{
    std::string temp;

    return temp = std::to_string(_sizeX) + " X " + std::to_string(_sizeY);
}

void Printer2D::set_sizeX(int _sizeX) {
    Printer2D::_sizeX = _sizeX;
}

void Printer2D::set_sizeY(int _sizeY) {
    Printer2D::_sizeX = _sizeX;
}