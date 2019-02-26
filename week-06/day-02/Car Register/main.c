#include <stdio.h>

enum transmission
{
    MANUAL,
    AUTOMATIC,
    CVT,
    SEMI_AUTOMATIC,
    DUAL_CLUTCH
};

typedef struct
{
    char manufacturer;
    float price;
    int made_in;
    enum transmission t_type;
}car_t;

int get_older_cars_than(car_t* array, int array_length, int age)
{
    int counter = 0;

    for (int j = 0; j < array_length; ++j) {
        if (2019 - array[j].made_in > age) {
            counter++;
        }
    }

    return counter;
}

int get_transmission_count(car_t* array, int array_length, enum transmission trnsm)
{
    int counter = 0;

    for (int j = 0; j < array_length; ++j) {
        if (array[j].t_type == trnsm) {
            counter++;
        }
    }

    return counter;
}

int main() {

    car_t car1;
    car1.t_type = MANUAL;
    car1.made_in = 2010;
    car_t car2;
    car2.t_type = CVT;
    car2.made_in = 2018;
    car_t car3;
    car3.t_type = CVT;
    car3.made_in = 2015;
    car_t car_array[3] = {car1, car2, car3};

    printf("%d - %d", get_older_cars_than(car_array, 3, 5), get_transmission_count(car_array, 3, CVT));

    return 0;
}