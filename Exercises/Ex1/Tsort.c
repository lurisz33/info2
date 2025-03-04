#include <stdio.h>

int Tsort(int A[], int n, int t) {
    int left = 0, right = n - 1;
    while (left != right) {
      int sum = A[left] + A[right];
      if (sum == t) {
        return 1;
      } else if (sum < t) {
      ++left;
      } else {
        ++right;
      }
    }
    return 0;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", Tsort(arr, n, 9));
}