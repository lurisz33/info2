#include <stdio.h>

int runCount = 0;

int hoarePartition(int A[], int left, int right) {
    int pivot = A[right];
    int i = left - 1;
    int j = right + 1;
    while (1) {
        do {
            j--;
            ++runCount;
        } while (A[j] > pivot);
        
        do {
            i++;
            ++runCount;
        } while (A[i] < pivot);
        if (i < j) {
            int temp = A[j];
            A[j] = A[i];
            A[i] = temp;
        } else {
            return i;
        }
    }
}

int quickselect(int A[], int left, int right, int m) {
    if (left == right) return A[left];
    int pivot = hoarePartition(A, left, right);
    if (m == pivot) {
        return A[m];
    } else if (m < pivot) {
        return quickselect(A, left, pivot - 1, m);
    } else {
        return quickselect(A, pivot + 1, right, m);
    }
}

int findMedian(int A[],int n) {
    if (n % 2 == 0) {
        int lower = quickselect(A, 0, n - 1, n / 2 - 1);
        int upper = quickselect(A, 0, n - 1, n / 2);
        return (lower + upper) / 2;
    } 
    return quickselect(A, 0, n - 1, n / 2);
}

int main() {
    int A[] = {5,2,8,3,7};
    int B[] = {1,9,0,6,3,8,7,2,4,5};
    int size = sizeof(A)/sizeof(A[0]);

    int res = findMedian(A, size);
    printf("Sorted array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    printf("Median is: %d\n", res);
    return 0;
}