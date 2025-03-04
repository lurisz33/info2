#include <stdio.h>
#include <stdlib.h>

void sequence(int n) {
  printf("%d\n", n);
  if (n == 1) return;
  if (n % 2 == 0) {
    sequence(n / 2);
  } else {
    sequence(n * 3 + 1);
  }
}

int main() {
  int n = 3;
  sequence(n);
  return 0;
}