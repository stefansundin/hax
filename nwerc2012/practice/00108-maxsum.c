#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define max( a, b ) ( ((a) > (b)) ? (a) : (b) )
#define min( a, b ) ( ((a) < (b)) ? (a) : (b) )
#define NINF -1000000000

int dp[105][105];
char matrix[105][105];

int main() {
	int n,i,j,k,l;
	scanf("%d", &n);
	for (i=0; i < n; i++) {
		for (j=0; j < n; j++) {
			scanf("%d", &dp[i][j]);
			if (i > 0) dp[i][j] += dp[i-1][j];
			if (j > 0) dp[i][j] += dp[i][j-1];
			if (i > 0 && j > 0) dp[i][j] -= dp[i-1][j-1];
		}
	}
	
	int maxSubRect = -128*100*100;
	
	
	for (i=0; i < n; i++) {
		for (j=0; j < n; j++) {
			for (k=i; k < n; k++) {
				for (l=j; l < n; l++) {
					int subRect = dp[k][l];
					if (i > 0) subRect -= dp[i-1][l];
					if (j > 0) subRect -= dp[k][j-1];
					if (i > 0 && j > 0) subRect += dp[i-1][j-1];
					maxSubRect = max(maxSubRect, subRect);
				}
			}
		}
	}
	
	printf("%d\n", maxSubRect);
}
