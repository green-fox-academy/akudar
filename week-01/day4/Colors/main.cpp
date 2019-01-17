#include <iostream>
#include <string>

// - Create a two dimensional array
//   which can contain the different shades of specified colors
// - In `colors[0]` store the shades of green:
//   `"lime", "forest green", "olive", "pale green", "spring green"`
// - In `colors[1]` store the shades of red:
//   `"orange red", "red", "tomato"`
// - In `colors[2]` store the shades of pink:
//   `"orchid", "violet", "pink", "hot pink"`

int main() {

    std::string shades[3][5];

    std::string green[] = {"lime", "forest green", "olive", "pale green", "spring green"};
    std::string red[] = {"orange red", "red", "tomato"};
    std::string pink[] = {"orchid", "violet", "pink", "hot pink"};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; ++j) {

            shades[i][j] = green[j];
        }

    }

    return 0;
}
