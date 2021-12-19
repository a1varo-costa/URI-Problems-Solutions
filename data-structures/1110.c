#include <stdio.h>
#include <stdlib.h>

#define MAX 64

// solve using circular buffer to represent the deck
struct deck {
        int buf[MAX];
        int capacity, len;
        int beg, end;
};

void deck_init(struct deck *d, int n)
{
        int i;

        d->capacity = n;
        d->len = n;
        d->beg = 0;

        for (i = 0; i < n; i++)
                d->buf[i] = i + 1;

        d->end = i;
}

int deck_pop(struct deck *d)
{
        int x;

        if (d->len == 0)
                return -1;

        x = d->buf[d->beg];

        d->beg = (d->beg + 1) % d->capacity;
        d->len--;

        return x;
}

void deck_insert(struct deck *d, int x)
{
        if (d->len == d->capacity)
                return;

        d->buf[d->end % d->capacity] = x;

        d->end = (d->end + 1) % d->capacity;
        d->len++;
}

int main()
{
        int n;
        struct deck d;
        int discarded[MAX], i;

        while (scanf("%d", &n) != EOF && n != 0) {
                deck_init(&d, n);

                discarded[0] = 0;
                i = 0;
                while (d.len >= 2) {
                        discarded[i++] = deck_pop(&d);
                        deck_insert(&d, deck_pop(&d));
                }

                printf("Discarded cards:");
                for (int j = 0; j < i; j++) {
                        if (j == 0)
                                printf(" %d", discarded[j]);
                        else
                                printf(", %d", discarded[j]);
                }

                printf("\nRemaining card: %d", deck_pop(&d));
                while (d.len > 0) {
                        printf(", %d", deck_pop(&d));
                }
                puts("");
        }
        return 0;
}
