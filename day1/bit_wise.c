#include <stdio.h>

// Como funciona : x = [1001] , y = [0101]
// (^) -> xor
// y = x ^ y = [1100]
// x = x ^ y = [0101]
// y = x ^ y = [1001]
// Da pra ver que os valores foram trocados
void inplace_swap(int *x, int *y) {
  *y = *x ^ *y;
  *x = *x ^ *y;
  *y = *x ^ *y;
}

void reverse_array(int a[], int cnt) {
  int first, last;
  for (first = 0, last = cnt - 1; first <= last; first++, last--) {
    inplace_swap(&a[first], &a[last]);
  }
}

int main() {

  int a[4] = {1, 2, 3, 4};

  // em ordem
  for (int i = 0; i < 4; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  reverse_array(a, 4);

  // inverso
  for (int i = 0; i < 4; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}
