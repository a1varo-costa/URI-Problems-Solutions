#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 3000100

uint8_t buf[MAX];

void fastscan(uint8_t *x) {
    uint8_t in;
    *x = 0;

    while ((in = getchar()) && isspace(in)) {}

    for ( ; in >= '0' && in <= '9'; in = getchar()) {
        *x = 10 * (*x) + in - '0';
    }    
}

int comp(const void *_a, const void *_b) {
    uint8_t a = *((uint8_t *) _a);
    uint8_t b = *((uint8_t *) _b);
    return a - b;
}

int main() {
    int nc, n;
    scanf("%d", &nc);

    while (nc > 0) {
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            //scanf(" %u", &buf[i]);
            fastscan(&buf[i]);
        }

        qsort(buf, n, sizeof(buf[0]), comp);

        for (int i = 0; i < n; i++) {
            if (i == n - 1) {
                printf("%d\n", buf[i]);
            } 
            else {
                printf("%d ", buf[i]);
            }
        }

        nc--;
    }
    return 0;
}