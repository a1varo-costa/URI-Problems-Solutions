#include <stdio.h>
#include <stdlib.h>

double limits[][2] = {
    {0.0, 25.0},
    {25.0, 50.0},
    {50.0, 75.0},
    {75.0, 100.0}
};

int find_interval(double x) {
    if (x < 0 || x > 100) {
        return -1;
    }

    for (int i = 0; i < 4; i++) {
        int lower = i == 0 ? x >= limits[i][0] : x > limits[i][0];
        int upper = x <= limits[i][1];

        if (lower && upper) {
            return i;
        }
    }
}

int main() {
    double x;

    scanf("%lf", &x);

    int interval = find_interval(x);

    if (interval >= 0) {
        printf(
            "Intervalo %c%d,%d]\n",
            interval == 0 ? '[' : '(',
            (int) limits[interval][0],
            (int) limits[interval][1]
        );
    }
    else {
        printf("Fora de intervalo\n");
    }

    return 0;
}
