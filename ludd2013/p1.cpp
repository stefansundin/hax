#include <cstdio>
#include <cstring>

int main() {
	for (;;) {
		int N;
		scanf("%d", &N);
		if (N == 0) break;
		if (!(13 <= N && N < 100)) {
			fprintf(stderr, "Invalid input!\n");
			continue;
		}

		int M=1;
		for (;;M++) {
			//printf("M=%d\n",M);
			int regions[110];
			memset(regions, 1, sizeof regions);

			int i=0, m=0, has_power=N;
			for (;;) {
				if (regions[i]) {
					if (m == 0) {
						//printf("shutting down region %d\n",i);
						regions[i] = 0;
						m = M-1;
						has_power--;
						if (has_power == 0) break;
					}
					else {
						m--;
					}
				}
				i = (i+1)%N;
			}
			if (i == 12) break;
		}

		printf("%d\n", M);
	}

	return 0;
}
