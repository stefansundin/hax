#include <stdio.h>
#include <string.h>
#include <limits.h>

char grid[110][110];
char ins[50100];
char ori = '\0';
int posx;
int posy;

int n,m,s;

int main() {
	while (1) {
		scanf("%d %d %d\n", &n, &m, &s);
		if (n == 0 && m == 0 && s == 0) break;
		
		int i,j;
		for (i=0; i < n; i++) {
			gets(grid[i]);
			for (j=0; j < n; j++) {
				if (grid[i][j] == 'N'    // north
				 || grid[i][j] == 'S'    // south
				 || grid[i][j] == 'L'    // east
				 || grid[i][j] == 'O') { // west
					ori = grid[i][j];
					grid[i][j] = '.';
					posy = i;
					posx = j;
					//printf("start at (%d,%d)\n", posx, posy);
					break;
				}
			}
		}
		gets(ins);
		
		int r = 0;
		char *c;
		for (c=ins; *c != '\0'; c++) {
			if (*c == 'E') { // turn left
				if      (ori == 'N') ori='O'; //north -> west
				else if (ori == 'S') ori='L'; //south -> east
				else if (ori == 'L') ori='N'; //east  -> north
				else if (ori == 'O') ori='S'; //west  -> south
				//printf("turn left to %c\n", ori);
			}
			else if (*c == 'D') { // turn right
				if      (ori == 'N') ori='L'; //north -> east
				else if (ori == 'S') ori='O'; //south -> west
				else if (ori == 'L') ori='S'; //east  -> south
				else if (ori == 'O') ori='N'; //west  -> north
				//printf("turn right to %c\n", ori);
			}
			else if (*c == 'F') { // forward
				int nx=posx, ny=posy;
				if      (ori == 'N') ny--; // go north
				else if (ori == 'S') ny++; // go south
				else if (ori == 'L') nx++; // go east
				else if (ori == 'O') nx--; // go west
				
				if (ny < 0 || ny > n-1 || nx < 0 || nx > m-1 || grid[ny][nx] == '#') continue;
				
				posx = nx;
				posy = ny;
				
				//printf("new pos: (%d,%d)\n", posx,posy);
				
				if (grid[posy][posx] == '*') {
					grid[posy][posx] = '.';
					r++;
				}
			}
		}
		
		printf("%d\n", r);
	}
	
}
