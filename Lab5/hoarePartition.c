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

int quicksort(int A[], int left, int right) {
    if (left < right) {
        int m = hoarePartition(A, left, right);
        quicksort(A, left, m - 1);
        quicksort(A, m, right);
    }
    
}

int main() {
    int A[] = {6,8,4,5,3,7,2,1,0,9};
    int B[] = {1,9,0,6,3,8,7,2,4,5};
    int size = sizeof(A)/sizeof(A[0]);

    quicksort(A, 0, size-1);
    printf("Sorted array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    printf("Runcount is: %d\n", runCount);

    runCount = 0;
    quicksort(B, 0, size-1);
    printf("Sorted array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");
    printf("Runcount is: %d\n", runCount);
    return 0;
}