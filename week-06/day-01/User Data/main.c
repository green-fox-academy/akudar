#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include <string.h>

int main() {

    char temp[50];
    char namePlusAge[200] = "";
    char firstName[20];
    char lastName[20];
    int age = 0;

    for (int i = 0; i < 3; ++i) {
        fgets(temp, sizeof(temp), stdin);
        strcat(namePlusAge, temp);
    }

    strcpy(firstName, strtok(namePlusAge, " \n"));
    strcpy(lastName, strtok(NULL, " \n"));
    age = atoi(strtok(NULL, " "));

    printf("Your name is: %s %s and you are %d years old", firstName, lastName, age);

    return 0;
}