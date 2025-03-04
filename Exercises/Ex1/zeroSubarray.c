#include <stdio.h>

int zeroSubarray(int A[], int n) {
    int left = 0, sum = 0;
    for (int right = 0; right < n; right++) {
      sum += A[right];
      while (left <= right && sum != 0) {
        sum -= A[left];
        left++;
      }
      if (sum == 0) {
        return 1;
      }
    }
    return 0;

}

int main() {
    int arr[] = {1, 2, -2, 1, 0};
//    int arr[] = {1, 2, -2, 1, -2};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", zeroSubarray(arr, n));
}