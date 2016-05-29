#include <stdio.h>

int main() {
  int T;
  scanf("%d\n", &T);

  int i,j;
  for (j=0; j < T; j++) {
    int N;
    scanf("%d\n", &N);
    // printf("N=%d\n", N);

    int r = 0;
    int seen[] = {0,0,0,0,0,0,0,0,0,0};
    for (i=1; i <= 1000000; i++) {
      int y = i*N;
      int x;
      do {
        x = y % 10;
        y = y / 10;
        // if (seen[x] == 0) {
        //   printf("saw %d\n", x);
        // }
        seen[x] = 1;
      } while (y > 0);
      // printf("done? %d\n", seen[0] == 1 && seen[1] == 1 && seen[2] == 1 && seen[3] == 1 && seen[4] == 1 && seen[5] == 1 && seen[6] == 1 && seen[7] == 1 && seen[8] == 1 && seen[9] == 1);
      if (seen[0] == 1 && seen[1] == 1 && seen[2] == 1 && seen[3] == 1 && seen[4] == 1 && seen[5] == 1 && seen[6] == 1 && seen[7] == 1 && seen[8] == 1 && seen[9] == 1) {
        r = i*N;
        break;
      }
    }

    if (r == 0) {
      printf("Case #%d: INSOMNIA\n", j+1);
    }
    else {
      printf("Case #%d: %d\n", j+1, r);
    }
  }
}
