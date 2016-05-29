#include <cstdio>
#include <cstdlib>

int main() {
	int n;
	scanf("%d\n", &n);
	int i;
	for (i=0; i < n; i++) {
		bool won = false;
		char grid[10][10];
		int j,k;
		for (j=0; j < 5; j++) {
			gets(grid[j]);
		}
		
		// check if X won
		for (j=0; j < 4; j++) {
			if (((grid[j][0] == 'X' || grid[j][0] == 'T')
			  && (grid[j][1] == 'X' || grid[j][1] == 'T')
			  && (grid[j][2] == 'X' || grid[j][2] == 'T')
			  && (grid[j][3] == 'X' || grid[j][3] == 'T'))
			 || ((grid[0][j] == 'X' || grid[0][j] == 'T')
			  && (grid[1][j] == 'X' || grid[1][j] == 'T')
			  && (grid[2][j] == 'X' || grid[2][j] == 'T')
			  && (grid[3][j] == 'X' || grid[3][j] == 'T'))) {
				won = true;
				break;
			}
		}
		if (((grid[0][0] == 'X' || grid[0][0] == 'T')
		  && (grid[1][1] == 'X' || grid[1][1] == 'T')
		  && (grid[2][2] == 'X' || grid[2][2] == 'T')
		  && (grid[3][3] == 'X' || grid[3][3] == 'T'))
		 || ((grid[0][3] == 'X' || grid[0][3] == 'T')
		  && (grid[1][2] == 'X' || grid[1][2] == 'T')
		  && (grid[2][1] == 'X' || grid[2][1] == 'T')
		  && (grid[3][0] == 'X' || grid[3][0] == 'T'))) {
			won = true;
		}
		if (won) {
			printf("Case #%d: X won\n", i+1);
			continue;
		}
		
		// check if O won
		for (j=0; j < 4; j++) {
			if (((grid[j][0] == 'O' || grid[j][0] == 'T')
			  && (grid[j][1] == 'O' || grid[j][1] == 'T')
			  && (grid[j][2] == 'O' || grid[j][2] == 'T')
			  && (grid[j][3] == 'O' || grid[j][3] == 'T'))
			 || ((grid[0][j] == 'O' || grid[0][j] == 'T')
			  && (grid[1][j] == 'O' || grid[1][j] == 'T')
			  && (grid[2][j] == 'O' || grid[2][j] == 'T')
			  && (grid[3][j] == 'O' || grid[3][j] == 'T'))) {
				won = true;
				break;
			}
		}
		if (((grid[0][0] == 'O' || grid[0][0] == 'T')
		  && (grid[1][1] == 'O' || grid[1][1] == 'T')
		  && (grid[2][2] == 'O' || grid[2][2] == 'T')
		  && (grid[3][3] == 'O' || grid[3][3] == 'T'))
		 || ((grid[0][3] == 'O' || grid[0][3] == 'T')
		  && (grid[1][2] == 'O' || grid[1][2] == 'T')
		  && (grid[2][1] == 'O' || grid[2][1] == 'T')
		  && (grid[3][0] == 'O' || grid[3][0] == 'T'))) {
			won = true;
		}
		if (won) {
			printf("Case #%d: O won\n", i+1);
			continue;
		}
		
		// is game incomplete?
		for (j=0; j < 4 && !won; j++) {
			for (k=0; k < 4 && !won; k++) {
				if (grid[j][k] == '.') {
					won = true;
				}
			}
		}
		if (won) {
			printf("Case #%d: Game has not completed\n", i+1);
			continue;
		}
		
		printf("Case #%d: Draw\n", i+1);
		
	}
}
