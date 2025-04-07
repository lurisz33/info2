#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node {
    char val;
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

char pop(struct stack *s) {
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

bool validate_parentheses(char *s) {
    struct stack *stack = new();
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '[') {
            push(stack, s[i]);
        } else {
            char prev = pop(stack);
            if (s[i] == ')' && prev != '(') {
                return false;
            } else if (s[i] == ']' && prev != '[') {
                return false;
            } 
        }
    }
    return is_empty(stack);
}

int main() {
    char *word_one = "(())((()))";
    char *word_two = "[[()[()]]]";
    char *word_three = "(()))()";
    char *word_four = "[[()]";

    printf("Testing %s should result in True, res is %s\n", word_one, validate_parentheses(word_one) ? "true" : "false");
    printf("Testing %s should result in True, res is %s\n", word_two, validate_parentheses(word_two) ? "true" : "false");
    printf("Testing %s should result in False, res is %s\n", word_three, validate_parentheses(word_three) ? "true" : "false");
    printf("Testing %s should result in False, res is %s\n", word_four, validate_parentheses(word_four) ? "true" : "false");
}