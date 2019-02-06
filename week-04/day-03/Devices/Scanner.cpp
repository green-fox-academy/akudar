#include <iostream>
#include "Scanner.h"

Scanner::Scanner(int speed)
{
    _speed = speed;
}

void Scanner::scan()
{
    std::cout <<  "I'm scanning a document " << _speed << " ppm" << std::endl;
}

void Scanner::set_speed(int _speed) {
    Scanner::_speed = _speed;
}
