#include <stdio.h>

void inssort(int *array, int n) {
  int c, d;
  for (c=1 ; c <= n-1; c++) {
    d = c;
    while (d > 0 && array[d] > array[d-1]) {
      int t      = array[d];
      array[d]   = array[d-1];
      array[d-1] = t;
      d--;
    }
  }
}

void print(int *array, int n) {
  int i;
  for (i=0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main() {
  int T;
  scanf("%d\n", &T);

  int i;
  for (i=0; i < T; i++) {
    int D;
    scanf("%d\n", &D);
    int Di[2020];
    int n;
    for (n=0; n < D; n++) {
      scanf("%d", &Di[n]);
    }

    inssort(Di, n);
    // print(Di, n);

    int it = 0;
    int best = Di[0];
    while (it < best) {
      // printf("%d < %d = %d\n", it, best, it < best);
      // printf("best: %d\n", best);
      int split = Di[0] / 2;
      Di[0] -= split;
      Di[n++] = split;
      inssort(Di, n);
      // print(Di, n);
      it++;
      if (it+Di[0] < best) {
        best = it+Di[0];
      }
    }
    // printf("final best: %d\n", best);
    // printf("\n");

    printf("Case #%d: %d\n", i+1, best);
  }
}
