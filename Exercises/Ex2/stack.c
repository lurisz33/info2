#include <stdio.h>
#include <stdlib.h>

void  stack(int A[], int n) {
    if (n == 1){
        printf("%d\n", A[0]);
        return;
    }
    int *res = (int*)malloc((n - 1) * sizeof(int));
    for (int i = 0; i < n - 1; i++) {
      res[i] = A[i] + A[i + 1];
    }
    stack(res, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    free(res);
    return;

}

int main() {
    int A[] = {5,4,6,1,3};
    int n = sizeof(A) / sizeof(A[0]);
    stack(A, n);
    return 0;
}