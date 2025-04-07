#include <stdio.h>

int controlMaxHeap(int array[], int currentIndex, int length) {
    for (int i = currentIndex; i < length; i++) {
        if (array[i/2] < array[i]) {
            return i/2;
        }
    }
    return -1;
}

int controlMaxHeapRecursive(int A[], int c, int n) {
    if (c >= n) return -1;
    if (A[c/2] < A[c]) {
        return c/2;
    } else {
        return controlMaxHeapRecursive(A, c + 1, n);
    }
}

void main() {
    int A[] = {5,5,3,2,1,3};
    int B[] = {5,5,3,2,1,4};
    int C[] = {5,5,3,2,1,6};
    int D[] = {1,5,3,2,1,3};
    
    int *test[] = {A, B, C, D};

    for (int i = 0; i < 4; i++) {
        int res = controlMaxHeapRecursive(test[i], 0, 6);
        printf("Result is: %d\n", res);
    }
}