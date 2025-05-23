#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct month *init_months(struct month *head);
void free_months(struct month *head);

struct month {
    int month_number;
    char *month_name;
    struct month *next;
};

void print_months(struct month *head) {
    if (!head) return;
    struct month *cur = head;
    while(cur) {
        printf("%s (%d) ", cur->month_name, cur->month_number);
        cur = cur->next;
    }
}

struct month *get_previous_month(struct month *head, struct month *target) {
    if (!head || head == target) return NULL;
    struct month *cur = head;
    while (cur-> next != target && cur != target) {
        cur = cur->next;
    }
    return cur;
}

struct month *swap_month(struct month *head, struct month *a, struct month *b) {
    if (a == b) return head;
    struct month *prev_a = get_previous_month(head, a);
    struct month *prev_b = get_previous_month(head, b);

    if (prev_b == a) {
        if (prev_a) {
            prev_a->next = b;
        } else {
            head = b;
        } 
        a->next = b->next;
        b->next = a;
    } else if (prev_a == b) {
        if (prev_b) {
            prev_b->next = a;
        } else {
            head = a;
        } 
        b->next = a->next;
        a->next = b;
    } else {
        if (prev_a) {
            prev_a->next = b;
        } else {
            head = b;
        }
        if (prev_b) {
            prev_b->next = a;
        } else {
            head = a;
        }
        struct month *temp = b->next;
        b->next = a->next;
        a->next = temp;
    }
    return head;
}

struct month *selection_sort(struct month *head) {
    struct month *i = head;
    while (i) {
        struct month *smallest = i;
        struct month *j = i->next;
        while (j) {
            if (j->month_number < smallest->month_number) smallest = j;
            j = j->next;
        }
        if (smallest != i) {
            head = swap_month(head, smallest, i);
            i = smallest;
        }
        i = i->next;
    }
    return head;
}

int main(int argc, char *argv[]) {
    struct month *head;
    head = init_months(head);

    print_months(head);

    printf("\n\nTesting get_previous_month:\n");

    if (head && head->next) {
        struct month *second = head->next;
        struct month *prev = get_previous_month(head, second);
        if (prev) {
            printf("Previous month of %s is %s\n", second->month_name, prev->month_name);
        } else {
            printf("Previous month of %s not found (should not happen).\n", second->month_name);
        }
    }

    struct month *test_null = get_previous_month(head, head);
    if (!test_null) {
        printf("Correctly returned NULL for previous of head.\n");
    } else {
        printf("Error: Should have returned NULL for previous of head.\n");
    }

    struct month *cur = head;
    for (int i = 0; i < 4 && cur; i++) cur = cur->next;
    if (cur) {
        struct month *prev = get_previous_month(head, cur);
        if (prev) {
            printf("Previous month of %s is %s\n", cur->month_name, prev->month_name);
        } else {
            printf("Previous of %s not found (should not happen).\n", cur->month_name);
        }
    }

    printf("\n\nTesting swap_month:\n");

    if (head && head->next && head->next->next) {
        struct month *first = head;
        struct month *second = head->next;
        struct month *third = head->next->next;

        printf("Before swap:\n");
        print_months(head);

        head = swap_month(head, first, third);

        printf("\nAfter swapping first and third:\n");
        print_months(head);
    }

    printf("\n");
    printf("Unsorted list is: \n");
    print_months(head);
    head = selection_sort(head);
    printf("\n");
    printf("Sorted list is: \n");
    print_months(head);

    
    free_months(head);
    return 0;
}

struct month *init_months(struct month *head) {
    int n = 12;
    int init_order[n];
    char *month_strings[] = {"January",   "February", "March",    "April",
                             "May",       "June",     "July",     "August",
                             "September", "Oktober",  "November", "Dezember"};
    struct month *h;
    struct month *p; 

    for (int i = 0; i < n; ++i) {
        init_order[i] = i + 1;
    }
    srand(time(0));
    for (int i = n - 1; i > 0; --i) {
        int j = rand() % (i + 1); 
        int tmp = init_order[i];
        init_order[i] = init_order[j];
        init_order[j] = tmp;
    }


    h = malloc(sizeof(struct month)); 
    h->month_number = init_order[0]; 
    h->month_name = month_strings[h->month_number - 1];
    p = h; 
    for (int i = 1; i < n; ++i) {
        struct month *m = malloc(sizeof(struct month));
        m->month_number = init_order[i];
        m->month_name = month_strings[m->month_number - 1];
        p->next = m;

        p = m; 
    }
    p->next = NULL;
    return h;
}

void free_months(struct month *head) {
    struct month *p = head;
    struct month *q = head->next;
    while (q) {
        free(p);
        p = q;
        q = q->next;
    }
    free(p);
}
