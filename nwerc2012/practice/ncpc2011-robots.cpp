#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;
typedef pair<int,int> ii;

char grid[1010][1010];
int n;
queue<ii> q;

void flood() {	
	while (!q.empty()) {
		ii pt = q.front(); q.pop();
		int x = pt.first;
		int y = pt.second;
		
		if (grid[y][x] == '!') continue; // check if already filled
		else if (grid[y][x] != '.') fprintf(stderr,"error!\n");
		
		int x2; // go to far left
		for (x2=x; x2 > 0 && grid[y][x2-1] == '.'; x2--) { }
		
		// check up and down while going right
		bool wallup=true, walldown=true;
		while (x2 <= n-1) {
			if (grid[y][x2] != '.') break;
			grid[y][x2] = '!';
			
			if (y > 0) {
				if (wallup && grid[y-1][x2] == '.') {
					q.push(ii(x2, y-1));
					wallup = false;
				}
				else if (grid[y-1][x2] == '#') {
					wallup = true;
				}
			}
			if (y < n-1) {
				if (walldown && grid[y+1][x2] == '.') {
					q.push(ii(x2, y+1));
					walldown = false;
				}
				else if (grid[y+1][x2] == '#') {
					walldown = true;
				}
			}
			x2++;
} } }

int main() {
	scanf("%d\n", &n);
	int i;
	for (i=0; i < n; i++) {
		gets(grid[i]);
	}
	
	q.push(ii(0, 0));
	flood();
	
	if (grid[n-1][n-1] == '!') {
		printf("THE GAME IS A LIE\n");
	}
	else {
		printf("INCONCEIVABLE\n");
	}
}
