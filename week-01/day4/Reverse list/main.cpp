#include <iostream>
#include <string>
#include <math.h>

    // - Create an array variable named `aj`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Reverse the order of the elements in `aj`
    // - Print the elements of the reversed `aj`

int main() {

    int aj[] = {3,4,5,6,7};
    int temp;
    int a = 0;

    for (int i = 0; i < floor((sizeof(aj)/ sizeof(aj[0]))/2); i++) {

        temp = aj[i];
        aj[i] = aj[sizeof(aj)/ sizeof(aj[0])-1-a];
        aj[sizeof(aj)/ sizeof(aj[0])-1-a] = temp;
        a++;
    }

    for (int j = 0; j < 5; ++j) {

        std::cout << aj[j] << std::endl;
    }

    return 0;
}