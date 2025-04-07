#include <stdio.h>
#include <stdlib.h>

int max(int x, int y){
    if(x > y){
        return x;
    }else{
        return y;
    }
}

int maxSub(int A[], int left, int right) {
    if (left == right) return A[left];
    int middle = (left + right) / 2;
    int sum_1 = maxSub(A, left, middle);
    int sum_2 = maxSub(A, middle + 1, right);
    return max(max(max(sum_1, sum_2), sum_2), 0);
}
int main() {
    int A[] = {1,2,3,4,6,7,8,9};
    int res = maxSub(A, 0, 8);
    printf("Max subarray sum is: %d\n", res);
    return 0;
}