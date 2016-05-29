#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long long int tab[55][55];

long long int compute(int n, int k, int m) {
	if (n == 0 && k == 0) {
		return 1;
	}
	else if (n == 0 || k == 0) {
		return 0;
	}
	
	if (tab[n][k] == -1) {
		long long int nways = 0;
		int i;
		for (i=1; i<=m && i<=n; i++) {
			nways += compute(n-i, k-1, m);
		}
		tab[n][k] = nways;
	}
	return tab[n][k];
}

int main() {
	int n,k,m;
	while (scanf("%d %d %d", &n, &k, &m) != EOF) {
		memset(tab, -1, sizeof(tab));
		printf("%lld\n", compute(n,k,m));
	}
}
