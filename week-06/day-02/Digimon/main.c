#include <stdio.h>
#include <mem.h>

enum digivolution
{
    BABY,
    IN_TRAINING,
    ROOKIE,
    CHAMPION,
    ULTIMATE,
    MEGA
};

typedef struct
{
    unsigned char name[128];
    unsigned int age;
    unsigned char health;
    char t_name[256];
    enum digivolution d_level;
}digimon_t;

int i_of_lowest(digimon_t *digimons, int digimons_length)
{
    int index = 0;
    int lowest = digimons[0].health;

    for (int i = 1; i < digimons_length; ++i) {
        if (lowest > digimons[i].health) {
            index = i;
        }
    }

    return index;
}

int digivolution_checker(digimon_t *digimons, int digimons_length, enum digivolution level)
{
    int counter = 0;

    for (int i = 0; i < digimons_length; ++i) {
        if (digimons[i].d_level == level) {
            counter++;
        }
    }

    return counter;
}

int tamer_checker(digimon_t *digimons, int digimons_length, char *tamer)
{
    int counter = 0;

    for (int i = 0; i < digimons_length; ++i) {
        if (strcmp(digimons[i].t_name, tamer) == 0) {
            counter++;
        }
    }

    return counter;
}

double avg_health(digimon_t *digimons, int digimons_length, char *tamer)
{
    double average = 0;
    int counter = 0;

    for (int i = 0; i < digimons_length; ++i) {
        if (strcmp(digimons[i].t_name, tamer) == 0) {
            counter++;
            average += digimons[i].health;
        }
    }

    return average / counter;
}

int main() {

    digimon_t digimon1;
    digimon1.health = 15;
    strcpy(digimon1.t_name, "Sanyi");
    digimon1.d_level = MEGA;
    digimon_t digimon2;
    digimon2.health = 20;
    strcpy(digimon2.t_name, "Lali");
    digimon2.d_level = BABY;
    digimon_t digimon3;
    digimon3.health = 10;
    strcpy(digimon3.t_name, "Sanyi");
    digimon3.d_level = CHAMPION;
    digimon_t digimons[3] = {digimon1, digimon2, digimon3};

    printf("%d - %d - %d - %f",
            i_of_lowest(digimons, 3), digivolution_checker(digimons, 3, BABY),
            tamer_checker(digimons, 3, "Sanyi"), avg_health(digimons, 3, "Sanyi"));

    return 0;
}