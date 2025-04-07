#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct queue {
    int items[1000];
    int h;
    int t;
};

struct queue *new() {
    struct queue *q = malloc(sizeof(struct queue));
    q->h = 0;
    q->t = 0;
    return q;
}

bool is_empty(struct queue *q) {
    return q->t == q->h;
}

struct stack *enqueue(struct queue *q, int x) {
    q->items[q->t] = x;
    q->t = (q->t + 1) % 1000;
}

int dequeue(struct queue * q) {
    int res = q->items[q->h];
    q-> h = (q->h + 1) % 1000;
    return res;
}

int main() {
    struct queue *q = new();
    printf("Initial queue empty: %s\n", is_empty(q) ? "true" : "false");
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printf("After enqueuing 10, 20, 30, queue empty: %s\n", is_empty(q) ? "true" : "false");
    int value = dequeue(q);
    printf("Dequeued value: %d\n", value);
    enqueue(q, 40);
    value = dequeue(q);
    printf("Dequeued value: %d\n", value);
    enqueue(q, 50);
    enqueue(q, 60);
    value = dequeue(q);
    printf("Dequeued value: %d\n", value);
    value = dequeue(q);
    printf("Dequeued value: %d\n", value);
    value = dequeue(q);
    printf("Dequeued value: %d\n", value);
    value = dequeue(q);
    printf("Dequeued value: %d\n", value);
    printf("Final queue empty: %s\n", is_empty(q) ? "true" : "false");
    free(q);
    return 0;
}


