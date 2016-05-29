#include <stdlib.h>
#include <stdio.h>

char primetbl[100000];

void PRIME1(int m, int n) {
  /* SET ALL BUT 0 AND 1 TO PRIME STATUS */
  int i;
  for (i=0; i <= n-m; i++) {
    primetbl[i] = 1;
  }
  if (m == 1) {
    primetbl[0] = 0;
  }

  /* MARK ALL THE NON-PRIMES */
  int thisFactor = 2;
  int lastSquare = 0;
  int thisSquare = 0;
  while (thisFactor * thisFactor <= n) {
    /* mark */
    int mark = thisFactor+thisFactor;
    if (mark < m) {
      mark = m;
      if (m%thisFactor != 0) {
        mark += thisFactor-(m%thisFactor);
      }
    }
    while (mark <= n) {
      primetbl[mark-m] = 0;
      mark += thisFactor;
    }

    /* Move to next prime */
    thisFactor++;
    while (thisFactor >= m && primetbl[thisFactor-m] == 0) {
      thisFactor++;
    }
  }

  /* Print */
  for (i=m; i <= n; i++) {
    if (primetbl[i-m]) {
      printf("%d\n", i);
    }
  }
}

int main() {
  int t;
  int m, n; // 1 <= m <= n <= 1000000000
  scanf("%d\n", &t);
  while (t--) {
    scanf("%d %d\n", &m, &n);
    PRIME1(m, n);
    printf("\n");
  }
  return 0;
}
