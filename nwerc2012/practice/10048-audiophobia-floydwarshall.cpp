#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int AdjMat[110][110];
#define INF 1000000000

void reset() {
	for (int i=0; i < 110; i++) {
		for (int j=0; j < 110; j++) {
			AdjMat[i][j] = INF;
		}
	}
}

int main() {
	for (int n=1; 1; n++) {
		int c,s,q;
		scanf("%d %d %d", &c,&s,&q);
		if (c == 0 && s == 0 && q == 0) break;
		reset();
		
		while (s--) {
			int c1,c2,d;
			scanf("%d %d %d", &c1,&c2,&d);
			c1--; c2--;
			AdjMat[c1][c2] = d;
			AdjMat[c2][c1] = d;
		}
		
		for (int k=0; k < c; k++) {
			for (int i=0; i < c; i++) {
				for (int j=0; j < c; j++) {
					AdjMat[i][j] = min(AdjMat[i][j], max(AdjMat[i][k],AdjMat[k][j]));
				}
			}
		}
		
		
		
		if (n > 1) printf("\n");
		printf("Case #%d\n", n);
		while (q--) {
			int c1,c2;
			scanf("%d %d", &c1,&c2);
			c1--; c2--;
			if (AdjMat[c1][c2] < INF) {
				printf("%d\n", AdjMat[c1][c2]);
			}
			else {
				printf("no path\n");
			}
		}
	}
}

