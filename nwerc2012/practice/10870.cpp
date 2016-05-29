#include <cstdio>
#include <cstring>

#define MAX_N 20
struct Matrix { long long int mat[MAX_N][MAX_N]; };
int d, m;

Matrix matMul(Matrix a, Matrix b) {
	Matrix ans; int i, j, k;
	for (i = 0; i < d; i++) {
		for (j = 0; j < d; j++) {
			for (ans.mat[i][j] = k = 0; k < d; k++) {
				ans.mat[i][j] += a.mat[i][k] * b.mat[k][j] % m;
			}
		}
	}
	return ans;
}

Matrix matPow(Matrix base, int p) {
	Matrix ans; int i, j, k;
	for (i = 0; i < d; i++) {
		for (j = 0; j < d; j++) {
			ans.mat[i][j] = (i == j);
		}
	}
	while(p) {
		if (p & 1) ans = matMul(ans, base);
		base = matMul(base, base);
		p >>= 1;
	}
	return ans;
}

void matPrint(Matrix p) {
	int i, j;
	printf("%d\n",d);
	for (i = 0; i < d; i++) {
		for (j = 0; j < d; j++) {
			printf("%lld ", p.mat[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int n,i,z=0;
	while (true) {
		scanf("%d %d %d\n",&d,&n,&m);
		if (d==0&&n==0&&m==0) break;
		Matrix ma;
		memset(ma.mat, 0, sizeof ma.mat);
		for(i=0;i<d;i++) {
			scanf("%lld", &ma.mat[0][i]);
		}
		for(i=1;i<d;i++) {
			ma.mat[i][i-1] = 1;
		}
		Matrix mult;
		for(i=d-1;i>=0;i--) {
			scanf("%lld", &mult.mat[i][0]);
		}
		if (d < n) {
			Matrix myres = matPow(ma,n-d);
			myres = matMul(myres, mult);
			printf("%lld\n", myres.mat[0][0] % m);
		} else {printf("%lld\n",mult.mat[d-1-(n-1)][0] % m);}
	}
	return 0;
}
