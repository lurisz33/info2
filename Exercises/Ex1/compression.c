#include <stdio.h>
#include <stdlib.h>

void compression(char string[], int n) {
    int count = 0;
    char last = 0;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            last = string[i];
            count = 1;
        } else if (string[i] == last) {
            count++;
        } else {
            printf("%d%c", count, last);
            last = string[i];
            count = 1;
        }
    }
    printf("%d%c\n", count, last);
}

int main() {
    compression("ABCDEF", 6);
}
