#include <cstdio>
#include <cstdlib>

int grid[110][110];
int n,m;

bool crossx(int x, int y) {
	int i,j;
	int maxh = grid[x][y];
	//printf("maxh: %d\n", maxh);
	for (i=0; i < m; i++) {
		if (grid[x][i] > maxh) return false;
	}
	return true;
}

bool crossy(int x, int y) {
	int i,j;
	int maxh = grid[x][y];
	for (i=0; i < n; i++) {
		if (grid[i][y] > maxh) return false;
	}
	return true;
}

int main() {
	int t;
	scanf("%d\n", &t);
	int i,j,k;
	for (i=0; i < t; i++) {
		scanf("%d %d\n",&n,&m);
		for (j=0; j < n; j++) {
			for (k=0; k < m; k++) {
				int z;
				scanf("%d", &z);
				grid[j][k] = z;
				//printf("z: %d\n", grid[j][k]);
			}
		}
		/*
		printf("grid:\n");
		for (j=0; j < n; j++) {
			for (k=0; k < m; k++) {
				printf("%d ", grid[j][k]);
			}
			printf("\n");
		}
		printf("\n");*/
		
		//printf("crossx(%d,%d): %d\n", 1,1,crossx(1,1));
		//continue;
		
		
		bool yes = true;
		for (j=0; j < n && yes; j++) {
			for (k=0; k < m && yes; k++) {
				//printf("Checking %d,%d\n", j,k);
				if (!crossx(j,k) && !crossy(j,k)) {
					yes = false;
				}
			}
		}
		if (!yes) {
			printf("Case #%d: NO\n", i+1);
			continue;
		}
		
		printf("Case #%d: YES\n", i+1);
	}
}
