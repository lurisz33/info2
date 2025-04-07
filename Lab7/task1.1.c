#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack {
    int items[1000];
    int top;
};

struct stack *new() {
    struct stack *s = malloc(sizeof(struct stack));
    s->top = 0;
    return s;
}

bool is_empty(struct stack *s) {
    return s->top == 0;
}

struct stack *push(struct stack *s, int x) {
    if (is_empty(s)) return -1;
    s->items[s->top] = x;
    s->top++;
}

int pop(struct stack *s) {
    s->top--;
    return s->items[s->top];
}

int main() {
    struct stack *s = new();
    push(s, 10);
    push(s, 20);
    push(s, 30);
    int a = pop(s);
    printf("%d\n", a);
    int b = pop(s);
    printf("%d\n", b);
    int c = pop(s);
    printf("%d\n", c);
    free(s);
    return 0;
}



