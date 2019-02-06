#ifndef DEVICES_SCANNER_H
#define DEVICES_SCANNER_H


class Scanner{

    int _speed;

public:
    Scanner(int speed);
    virtual void scan();
    void set_speed(int _speed);
};


#endif