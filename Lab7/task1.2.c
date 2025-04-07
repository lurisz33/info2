#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int val;
    struct node *next;
};

struct stack {
    struct node *head;
};

struct stack *new() {
    struct stack *stack = malloc(sizeof(struct stack));
    stack->head = NULL;
    return stack;
}

bool is_empty(struct stack *s) {
    return (s->head == NULL);
}

int pop(struct stack *s) {
    if (is_empty(s)) return -1;
    struct node *temp = s->head;
    int res = temp->val;
    s->head = s->head->next;
    free(temp);
    return res;
}

struct stack *push(struct stack *s, int x) {
    struct node *cur = malloc(sizeof(struct node));
    cur->val = x;
    cur->next = s->head;
    s->head = cur;
    return s;
}

int main() {
    printf("Got in here");
    struct stack *s = new();

    printf("Test 1: Check if new stack is empty: %s\n", is_empty(s) ? "true" : "false");
    
    push(s, 10);
    push(s, 20);
    push(s, 30);
    printf("Test 2: After pushing 10, 20, 30, check if stack is empty: %s\n", is_empty(s) ? "true" : "false");
    
    int value1 = pop(s);
    printf("Test 3: Popped value: %d\n", value1);
    
    push(s, 40);
    int value2 = pop(s);
    printf("Test 4: Popped value: %d\n", value2);
    
    push(s, 50);
    push(s, 60);
    int value3 = pop(s);
    printf("Test 5: Popped value: %d\n", value3);
    
    int value4 = pop(s);
    printf("Test 6: Popped value: %d\n", value4);
    
    int value5 = pop(s);
    printf("Test 7: Popped value: %d\n", value5);
    
    return 0;
}