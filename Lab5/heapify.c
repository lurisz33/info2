#include <stdio.h>

void heapify(int A[], int c, int n) {
    int max = c;
    int left = c * 2 + 1;
    int right = c * 2 + 2;
    if (left < n && A[left] > A[max]) max = left;
    if (right < n && A[right] > A[max]) max = right;
    if (max != c) {
        int temp = A[max];
        A[max] = A[c];
        A[c] = temp;
        heapify(A, max, n);
    }
}

void main() {
    int A[] = {4,10,3,5,1};
    heapify(A, 0, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d ", A[i]);
    }
}