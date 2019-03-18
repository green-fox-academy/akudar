#include <stdio.h>
#include <mem.h>
#include <stdlib.h>

char bi_to_char(char input[8]);
void file_reader(char *filename, char *output);

int main()
{
    char *file = "../binary.txt";
    char *converted;

    file_reader(file, converted);

    printf("%s", converted);

    return 0;
}

char bi_to_char(char input[8])
{
    char single_char;
    int temp = 1;
    int value = 0;

    for (int i = 7; i >= 0; --i) {
        if (atoi(&input[i]) == 1) {
            value += temp;
        }
        temp *= 2;
    }

    sprintf(&single_char,"%c", value);

    return single_char;
}

void file_reader(char *filename, char *output)
{
    char in_ascii;
    char token;
    char binary[8] = "";
    FILE *file_to_read;
    file_to_read = fopen(filename, "r");

    if (file_to_read == NULL) {
        printf("Failed to read the file");
        return;
    }

    while (fgetc(file_to_read)) {
        token = (char)fgetc(file_to_read);
        if (strcmp(&token, " ") != 0) {
            strcat(binary, &token);
        } else {
            in_ascii = bi_to_char(binary);
            strcat(output, &in_ascii);
            strcpy(binary, "");
        }
    }
    fclose(file_to_read);
}