#ifndef DEVICES_PRINTER2D_H
#define DEVICES_PRINTER2D_H

#include "Printer.h"

class Printer2D : public Printer{

    int _sizeX;
    int _sizeY;

public:
    Printer2D(int x, int y);
    std::string getSize();
    void set_sizeX(int _sizeX);
    void set_sizeY(int _sizeY);
};


#endif