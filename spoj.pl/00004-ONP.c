#include <stdlib.h>
#include <stdio.h>

char *ONP(char *s) {
  char op;

  if (*s == '(') {
    s = ONP(s+1);
    s++;
    if (*s == '\0') {
      return;
    }
  }
  else {
    putchar(*s);
    s++;
  }

  op = *s;
  s++;

  if (*s == '(') {
    s = ONP(s+1);
    putchar(op);
  }
  else {
    putchar(*s);
    putchar(op);
  }
  s++;

  return s;
}

int main() {
  int t;
  char line[401];
  fscanf(stdin, "%d\n", &t);
  while (t--) {
    scanf("%s\n", line);
    ONP(line);
    putchar('\n');
  }
  return 0;
}
