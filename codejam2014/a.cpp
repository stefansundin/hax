#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <bitset>

using namespace std;

int main() {
	int t,i;
	scanf("%d", &t);
	for (i=0; i < t; i++) {
		int a, p[20], temp, j;
		memset(p, 0, sizeof p);

		scanf("%d", &a);
		// printf("a1: %d\n", a);

		for (j=1; j <= 16; j++) {
			scanf("%d", &temp);
			// printf("(%d < %d || %d < %d)\n", j, (a-1)*4, a*4, j);
			if (j <= (a-1)*4 || a*4 < j) {
				// printf("skipping: %d\n", temp);
			}
			else {
				// printf("a1 row number: %d\n", temp);
				p[temp]++;
				// printf("process: %d\n", temp);
			}
		}

		// skip to row a1
		/*
		for (j=1; j < (a-1)*4; j++) {
			scanf("%d", &temp);
			printf("skipping: %d\n", temp);
		}
		// read row numbers as possible digits
		for (j=0; j < 4; j++) {
			scanf("%d", &temp);
			printf("a1 row number: %d\n", temp);
			p[temp] = 1;
		}
		// skip rest of rows
		for (j=a; j <= 4*4; j++) {
			scanf("%d", &temp);
			printf("skipping: %d\n", temp);
		}
		*/

		scanf("%d", &a);
		// printf("a2: %d\n", a);

		for (j=1; j <= 16; j++) {
			scanf("%d", &temp);
			// printf("(%d < %d || %d < %d)\n", j, (a-1)*4, a*4, j);
			if (j <= (a-1)*4 || a*4 < j) {
				// printf("skipping: %d\n", temp);
			}
			else {
				// printf("a2 row number: %d\n", temp);
				p[temp]++;
				// printf("process: %d\n", temp);
			}
		}

// 		for (j=1; j <= 16; j++) {
// 			scanf("%d", &temp);
// 			if (j < a*4 || a*4+4 < 16) {
// 				printf("skipping: %d\n", temp);
// 			}
// 			else {
// 				printf("process: %d\n", temp);
// 			}
// 		}

/*
		// skip to row a2
		for (j=1; j < (a-1)*4; j++) {
			scanf("%d", &temp);
			printf("skipping: %d\n", temp);
		}
		// read row numbers as possible digits
		for (j=0; j < 4; j++) {
			scanf("%d", &temp);
			printf("a2 row number: %d\n", temp);
			p[temp] = 1;
		}
		// skip rest of rows
		for (j=a; j <= 4*4; j++) {
			scanf("%d", &temp);
			printf("skipping: %d\n", temp);
		}
*/

		int n_solutions = 0;
		int solution = 0;
		for (j=1; j <= 16; j++) {
			if (p[j] == 2) {
				// printf("Possible solution: %d\n", j);
				n_solutions++;
				solution = j;
			}
		}

		if (n_solutions == 0) {
			printf("Case #%d: Volunteer cheated!\n", i+1);
		}
		else if (n_solutions == 1) {
			printf("Case #%d: %d\n", i+1, solution);
		}
		else {
			printf("Case #%d: Bad magician!\n", i+1);
		}
	}
}
