#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vii> adjlist;

int matrix[40][40];
char m, t;
long long int l;
char maxc = 'A';

void testcase() {
	t -= 'A';
	m -= 'A';
	long long int last = l;
	while (true) {
		if (last <= 0) {
			last = l - 1;
			matrix[t][t] = 2;
			printf("%c ", t + 'A');
		} else {
			last--;
		}
		int min = -1;
		for (int i = 0; i <= maxc - 'A'; i++) {
			if (t != i && m != i && matrix[m][i] != 0 && matrix[i][i] != 2) {
				if (min == -1 || matrix[m][i] < matrix[m][min])
					min = i;
			}
		}

		if (min == -1) {
			printf("/%c\n", m + 'A');
			return;
		}
		t = m;
		//printf("new pos: %c\n",m+'A');
		m = min;
	}

}

void printcase() {
	for (int i = 0; i <= maxc - 'A'; i++) {
		for (int j = 0; j <= maxc - 'A'; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}
int added = 1;
int main() {
	char read;
	memset(matrix, 0, sizeof matrix);
	while (scanf("%c", &read) == 1) {
		if (read == '#')
			return 0;

		if (read > maxc) {
			maxc = read;
		}
		char tmp;
		scanf(":%c", &tmp);
		while (tmp != ';' && tmp != '.') {
			if (tmp > maxc) {
				maxc = tmp;
			}

			matrix[read - 'A'][tmp - 'A'] = added++;
			scanf("%c", &tmp);
		}
		if (tmp == '.') {
			scanf(" %c %c %lld\n", &m, &t, &l);
			//printcase();
			testcase();
			memset(matrix, 0, sizeof matrix);
			maxc = 'A';
			added = 1;
		}
	}

	return 0;
}
