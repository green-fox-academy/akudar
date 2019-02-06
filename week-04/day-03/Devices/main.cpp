#include <iostream>
#include <vector>
#include "Printer.h"
#include "Printer2D.h"
#include "Printer3D.h"
#include "Copier.h"

int main() {

    std::vector<Printer*> printers;
    Printer2D p2d1(1,1);
    Printer2D p2d2(2,2);
    Printer2D p2d3(3,3);
    Printer3D p3d1(4,4,4);
    Printer3D p3d2(5,5,5);
    Copier c1(6,6,6);

    printers.push_back(&p2d1);
    printers.push_back(&p2d2);
    printers.push_back(&p2d3);
    printers.push_back(&p3d1);
    printers.push_back(&p3d2);
    printers.push_back(&c1);

    for (int i = 0; i < printers.size(); ++i) {

        printers[i]->print();
    }

    std::vector<Scanner*> scanners;
    Scanner s1(7);
    Scanner s2(8);
    Copier c2(9,9,9);
    Copier c3(10,10,10);

    scanners.push_back(&s1);
    scanners.push_back(&s2);
    scanners.push_back(&c2);
    scanners.push_back(&c3);

    for (int j = 0; j < scanners.size(); ++j) {

        scanners[j]->scan();
    }

    Copier c4(11,11,11);
    c4.copy();

    return 0;
}