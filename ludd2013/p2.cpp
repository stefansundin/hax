#include <cstdio>
#include <cstring>

int to_number(char x) {
	if (x == '_') return 0;
	if (x >= 'a' && x <= 'z') return x-'a'+1;
	if (x == '.') return 27;
	fprintf(stderr, "to_number(%c): character not allowed!\n", x);
}

char to_char(int x) {
	if (x == 0) return '_';
	if (x >= 1 && x <= 26) return x+'a'-1;
	if (x == 27) return '.';
	fprintf(stderr, "to_char(%d): number out of range!\n", x);
}

int main() {
	for (;;) {
		int k;
		scanf("%d ", &k);
		if (k == 0) break;

		char e[100],c[100];
		gets(e);
		//printf("e: '%s'\n", e);
		int n = strlen(e);
		c[n] = '\0';
		//printf("n: %d\n", n);

		int i;
		for (i=0; e[i] != '\0'; i++) {
			int j = (k*i)%n;
			int m = (k*j)%n;
			c[m] = to_char((to_number(e[j])+j)%28);
		}
		printf("%s\n", c);

		/*
		for (i=0; e[i] != '\0'; i++) {
			printf("%02d ", i);
		}
		printf("\n ");
		for (i=0; e[i] != '\0'; i++) {
			printf("%c  ", e[i]);
		}
		printf("\n");
		for (i=0; e[i] != '\0'; i++) {
			printf("%02d ", to_number(e[i]));
		}
		printf("\n");
		for (i=0; e[i] != '\0'; i++) {
			int j = (k*i)%n;
			printf("%02d ", j);
		}
		printf("\n ");
		for (i=0; e[i] != '\0'; i++) {
			int j = (k*i)%n;
			printf("%c  ", to_char((to_number(e[j])+j)%28));
		}
		printf("\n");
		for (i=0; e[i] != '\0'; i++) {
			int j = (k*((k*i)%n))%n;
			printf("%02d ", j);
		}
		printf("\n");
		*/
	}

	return 0;
}
