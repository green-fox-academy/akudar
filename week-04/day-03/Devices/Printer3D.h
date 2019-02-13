#ifndef DEVICES_PRINTER3D_H
#define DEVICES_PRINTER3D_H

#include "Printer.h"

class Printer3D : public Printer{

    int _sizeX;
    int _sizeY;
    int _sizeZ;

public:

    Printer3D(int x, int y, int z);
    std::string getSize() override;
};


#endif