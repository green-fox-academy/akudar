#include <stdio.h>

#define PI 3.14

double aoc(double radius) {

    double area;

    return area = radius * radius * PI;
}

int main() {

    double result = aoc(12);
    printf("%lf", result);

    return 0;
}