#include <stdio.h>
#include <mem.h>

int indexOf(char* word, char* sentence) {

    int iow = 0;
    char* part = strstr(sentence, word);
    double position = part - sentence;

    for (int i = 0; i < position; ++i) {
        char tempChar = sentence[i];
        if (strcmp(&tempChar, " ") == 0) {
            iow++;
        }
    }

    return iow;
}

int main() {

    char* word = "kar";
    char* sentence = "mar dar far kar mar";
    printf("%d", indexOf(word, sentence));

    return 0;
}