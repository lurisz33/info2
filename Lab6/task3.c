#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
    struct node *prev;
};

struct node *merge(struct node *a, struct node *b){
    struct node *head = NULL;
    struct node *cur = NULL;
    while (a || b) {
        struct node *smaller;
        if (a && b) {
            if (a->val < b->val) {
                smaller = a;
                a = a->next;
            } else {
                smaller = b;
                b = b->next;
            }
        } else if (a) {
            smaller = a;
            a = a->next;
        } else {
            smaller = b;
            b = b->next;
        }
        smaller->next = NULL;
        if (!head) {
            head = smaller;
            cur = smaller;
        } else {
            cur->next = smaller;
            smaller->prev = cur;
            cur = smaller;
        }
    }
    return head;
}

struct node *create_node(int val) {
    struct node *n = malloc(sizeof(struct node));
    n->val = val;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

struct node *append(struct node *head, int val) {
    struct node *new_node = create_node(val);
    if (!head) return new_node;

    struct node *cur = head;
    while (cur->next) cur = cur->next;
    cur->next = new_node;
    new_node->prev = cur;
    return head;
}

void print_list(struct node *head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

void free_list(struct node *head) {
    while (head) {
        struct node *tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    // Create first sorted list: 1 -> 3 -> 5
    struct node *list1 = NULL;
    list1 = append(list1, 1);
    list1 = append(list1, 3);
    list1 = append(list1, 5);

    // Create second sorted list: 2 -> 4 -> 6
    struct node *list2 = NULL;
    list2 = append(list2, 2);
    list2 = append(list2, 4);
    list2 = append(list2, 6);

    printf("List 1: ");
    print_list(list1);

    printf("List 2: ");
    print_list(list2);

    // Merge the lists
    struct node *merged = merge(list1, list2);

    printf("Merged: ");
    print_list(merged);

    // Cleanup
    free_list(merged);
    return 0;
}

