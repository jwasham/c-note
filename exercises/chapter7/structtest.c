#include <stdio.h>

int main(int argc, char *argv[]) {

    struct automobile {
        float length;
        float height;
        float width;
        float weight;
        int year;
        char make[20];
        char model[20];
    };

    struct automobile jeep = {
        12.5,
        6.6,
        5.7,
        3834,
        2015,
        "Jeep",
        "Wrangler"
    };

    printf("It's a %d %s %s\n", jeep.year, jeep.make, jeep.model);

    return 0;
}