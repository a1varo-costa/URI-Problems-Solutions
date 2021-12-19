#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 1024
#define INVALID -1

// Use a stack to solve the problem. Not the most efficient solution in this case,
// but is used here as an exercise to implement this data structure.
struct stack {
        int len;
        char stack[MAX];
};

struct stack *stack_new()
{
        struct stack *s;
        s = malloc(sizeof(*s));
        s->len = 0;
        s->stack[0] = INVALID;
        return s;
}

void stack_free(struct stack *s)
{
        free(s);
}

void stack_push(struct stack *s, char x)
{
        s->stack[s->len++] = x;
}

char stack_pop(struct stack *s)
{
        if (s->len - 1 < 0)
                return INVALID;
        return s->stack[--s->len];
}

char stack_peek(struct stack *s)
{
        if (s->len - 1 < 0)
                return INVALID;
        return s->stack[s->len - 1];
}

void stack_clear(struct stack *s)
{
        s->len = 0;
        s->stack[0] = INVALID;
}

int main()
{
        int N;
        char input[MAX];
        struct stack *s;

        s = stack_new();

        scanf("%d", &N);
        (void)getchar();
        for (int i = 0; i < N; i++) {
                int res;

                stack_clear(s);

                fgets(input, sizeof(input), stdin);
                res = 0;
                for (char *ch = input; *ch != '\0'; ch++) {
                        if (*ch == '<')
                                stack_push(s, *ch);
                        else if (*ch == '>') {
                                if (stack_peek(s) == '<') {
                                        stack_pop(s);
                                        res++;
                                }
                        }
                }
                printf("%d\n", res);
        }
        stack_free(s);
        return 0;
}
