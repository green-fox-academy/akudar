#ifndef DEVICES_PRINTER_H
#define DEVICES_PRINTER_H


class Printer {

public:
    virtual std::string getSize() = 0;
    void print();
};


#endif