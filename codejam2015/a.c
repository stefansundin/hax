#include <stdio.h>

int main() {
  int T;
  scanf("%d\n", &T);

  int i;
  for (i=0; i < T; i++) {
    int Smax;
    scanf("%d ", &Smax);
    int P = 0;
    int r = 0;
    int j;
    for (j=0; j <= Smax; j++) {
      int Sj = getchar()-'0';
      if (j > 0 && P < j) {
        int Padd = j-P;
        r += Padd;
        P += Padd;
      }
      P += Sj;
    }
    printf("Case #%d: %d\n", i+1, r);
  }
}
