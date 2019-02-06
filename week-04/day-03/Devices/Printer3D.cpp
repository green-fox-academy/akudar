#include <iostream>
#include "Printer3D.h"


Printer3D::Printer3D(int x, int y, int z)
{
    _sizeX = x;
    _sizeY = y;
    _sizeZ = z;
}

std::string Printer3D::getSize()
{
    std::string temp;

    return temp = std::to_string(_sizeX) + " X " + std::to_string(_sizeY) + " X " + std::to_string(_sizeZ);
}