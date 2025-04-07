#include <stdio.h>
#include <stdlib.h>

int close(int A[], int n, int t) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (A[middle] == t) {
            return 0;
        }
        if ((abs(A[middle - 1] - t)) < (abs(A[middle + 1] - t))) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    if (abs(A[left] - t) < abs(A[right] - t)) {
        return A[left];
    } else {
        return A[right];
    }
}

int main() {
    int A[] = {1,2,3,4,6,7,8,9};
    int t = 1;
    int res = close(A, 8, t);
    printf("Closest number is: %d\n", res);
    return 0;
}