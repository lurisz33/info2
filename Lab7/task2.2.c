#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int val;
    struct node *next;
};

struct queue {
    struct node *h;
    struct node *t;
};

struct queue *new() {
    struct queue *q = malloc(sizeof(struct queue));
    q->h = 0;
    q->t = 0;
    return q;
}

bool is_empty(struct queue *q) {
    return q->h == NULL;
}

struct queue *enqueue(struct queue *q, int x) {
    struct node *cur = malloc(sizeof(struct node));
    cur->val = x;
    cur->next = NULL;
    if (is_empty(q)){
        q->t = cur;
        q->h = cur;
    } else {
        q->h->next = cur;
        q->h = cur;
    }
    return q;
}

int dequeue(struct queue * q) {
    if (is_empty(q)) return -1;
    struct node *cur = q->t;
    int res = cur->val;
    q->t = q->t->next;
    if (q->t == NULL) {
        q->h = NULL;
    }
    free(cur);
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


