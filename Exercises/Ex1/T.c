#include <stdio.h>


int T(int A[], int n, int t) {
    for (int i = 0 ; i < n ; i++) {
      if (A[i] >= t) continue;
      int num = A[i];
      for (int j = i + 1; j < n; j++) {
        if (num + A[j] == t) return 1;
      }
    }
    return 0;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", T(arr, n, 16));
}