#include <stdio.h>
#include <string.h>

char grid[1010][1010];
int n;

typedef struct {
	int x;
	int y;
} point;
typedef struct {
	point list[100000];
	int pos;
} queue;
queue q;

int printn = 1;
void printgrid() {
	return;
	char fn[100];
	sprintf(fn, "robots/robots-%08d.txt", printn);
	printn++;
	FILE *f = fopen(fn, "w");
	
	int i,j,x;
	for (i=0; i < n; i++) {
		for (j=0; j < n; j++) {
			int marked = 0;
			for (x=0; x <= q.pos; x++) {
				if (q.list[x].x == j && q.list[x].y == i) {
					marked = 1;
					break;
				}
			}
			if (marked) {
				putc('*', f);
				continue;
			}
			
			putc(grid[i][j], f);
		}
		putc('\n', f);
	}
	
	fclose(f);
}

void qpush(int x, int y) {
	q.pos++;
	q.list[q.pos].x = x;
	q.list[q.pos].y = y;
	if (grid[y][x] != '.') {
		fprintf(stderr, "pushing wrong target color at (%d,%d)!\n", x,y);
	}
	if (q.pos >= 100000) {
		fputs("queue overflow!\n", stderr);
	}
	//fprintf(stderr, "pushing (%d,%d)\n", x,y);
}

void flood() {
	int x,y;
	
	while (q.pos != -1) {
		// pop
		x = q.list[q.pos].x;
		y = q.list[q.pos].y;
		q.pos--;
		
		// check if already filled
		if (grid[y][x] == '!') continue;
		else if (grid[y][x] != '.') printf("error!");
		
		// go left
		int x2;
		for (x2=x; x2 > 0 && grid[y][x2-1] == '.'; x2--) { }
		
		// check up and down while going right
		//int wallup = (y > 0 && grid[y-1][x2] == '.'),
		//    walldown = (y < n-1 && grid[y+1][x2] == '.');
		int wallup=1, walldown=1;
		while (x2 <= n-1) {
			if (grid[y][x2] != '.') break;
			grid[y][x2] = '!';
			
			if (y > 0) {
				if (wallup && grid[y-1][x2] == '.') {
					qpush(x2, y-1);
					wallup = 0;
				}
				else if (grid[y-1][x2] == '#') {
					wallup = 1;
				}
			}
			if (y < n-1) {
				if (walldown && grid[y+1][x2] == '.') {
					qpush(x2, y+1);
					walldown = 0;
				}
				else if (grid[y+1][x2] == '#') {
					walldown = 1;
				}
			}
			x2++;
			
			// print grid
			printgrid();
		}
		
		/*
		// go right
		x2 = x+1;
		wallup = walldown = 1;
		while (x2 <= n-1) {
			//printf("checking (%d,%d)\n", x2,y);
			if (grid[y][x2] != '.') break;
			grid[y][x2] = '!';
			
			if (y > 0) {
				if (wallup && grid[y-1][x2] == '.') {
					qpush(x2, y-1);
					wallup = 0;
				}
				else if (grid[y-1][x2] == '#') {
					wallup = 1;
				}
			}
			if (y < n-1) {
				if (walldown && grid[y+1][x2] == '.') {
					qpush(x2, y+1);
					walldown = 0;
				}
				else if (grid[y+1][x2] == '#') {
					walldown = 1;
				}
			}
			x2++;
			
			// print grid
			printgrid();
		}
		*/
	}
}

int main() {
	// init
	q.pos = -1;
	//memset(q->list, -1, sizeof q);
	
	// read
	scanf("%d\n", &n);
	int i;
	for (i=0; i < n; i++) {
		gets(grid[i]);
	}
	
	// add (0,0) to q
	qpush(0, 0);
	flood();
	
	// result
	if (grid[n-1][n-1] == '!') {
		printf("THE GAME IS A LIE\n");
	}
	else {
		printf("INCONCEIVABLE\n");
	}
}
