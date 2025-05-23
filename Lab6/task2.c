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
    struct month *cur = head;
    while (cur != NULL) {
        printf("%s (%d) ", cur->month_name, cur->month_number);
        cur = cur->next;
    }
}

struct month *get_previous_month(struct month *head, struct month *target) {
    if (head == NULL || target == NULL) return NULL;
    struct month *cur = head;
    while (cur != NULL && cur-> next != target) {
        cur = cur->next;
    }
    return cur;
}

struct month *swap_month(struct month *head, struct month *a, struct month *b) {
    if (head == NULL || head-> next == NULL) return head;
    struct month *prev_a = get_previous_month(head, a);
    struct month *prev_b = get_previous_month(head, b);

    if (a->next == b) {
        if (prev_a) {
            prev_a->next = b;
        } else {
            head = b;
        }
        a->next = b->next;
        b->next = a;
    } else if (b->next == a) {
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
    if (head == NULL || head->next == NULL) return head;
    struct month *i = head;

    while (i != NULL) {
        struct month *min = i;
        struct month *j = i-> next;

        while (j != NULL) {
            if (j->month_number < min->month_number) {
                min = j;
            }
            j = j->next;
        }
        if (min != i) {
            printf("Swapping %s (%d) with %s (%d)\n", i->month_name, i->month_number, min->month_name, min->month_number);
            head = swap_month(head, min, i);
            i = min;
        }
        i = i->next;
    }
    return head;
}

int main(int argc, char *argv[]) {
    struct month *head;
    head = init_months(head);

    print_months(head);

    head = selection_sort(head);
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
