// not finished

#include <cstdio>
#include <cstring>
#include <cmath>

#define INF 1000000000

int pyramid(int h) {
	int i,n=0;
	for (i=1; i <= h; i++) {
		n += i*i;
	}
	return n;
}

int cube(int h) {
	return h*h*h;
}

int maxcube(int N) {
	return pow(N, 1.0/3.0);
}

int best_so_far;
int dp[40100];

int best(int N, int depth) {
	if (depth > best_so_far) return INF;
	if (N < 0) return INF;
	if (N == 0) return 0;
	if (dp[N] != -1) return dp[N];

	int i;
	int b = INF;
	int mc = maxcube(N);
	for (i=mc; i > 0; i--) {
		int r = depth+1+best(N-cube(i), depth+1);
		if (r < b) b = r;
		if (r < best_so_far) best_so_far = r;
	}
	for (i=1;; i++) {
		int n = pyramid(i);
		if (n > N) break;
		int r = depth+1+best(N-n, depth+1);
		if (r < b) b = r;
		if (r < best_so_far) best_so_far = r;
	}
	dp[N] = b;
	return b;
}

int main() {
	for (;;) {
		int N;
		scanf("%d", &N);
		if (N == -1) break;
		memset(dp, -1, sizeof dp);
		best_so_far = INF;

		//printf("maxcube(%d): %d\n", N, maxcube(N));

		printf("%d\n", best(N,0));
	}

	return 0;
}
