#include <stdio.h>

typedef struct
{
    float x;
    float y;
}point_t;

point_t create_point(float _x, float _y)
{
    point_t p;
    p.x = _x;
    p.y = _y;

    return p;
}

float calc_distance(point_t _p1, point_t _p2)
{
    float distance = 0;

    distance = _p1.x - _p2.x;

    return distance;
}

int main() {

    printf("%f", calc_distance(create_point(4,5), create_point(2,7)));

    return 0;
}