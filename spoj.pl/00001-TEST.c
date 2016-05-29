#include <stdlib.h>
#include <stdio.h>

int main() {
  char line[80], c;
  int i = 0;
  while ((c=getchar()) != EOF) {
    if (c == '\n') {
      if (strcmp(line,"42") == 0) {
        break;
      }
      printf("%s\n", line);
      i = 0;
      line[i] = '\0';
    }
    else {
      line[i] = c;
      i++;
      line[i] = '\0';
    }
  }
  return 0;
}
