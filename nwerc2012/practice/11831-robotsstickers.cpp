#include <stdio.h>
#include <cstring>
using namespace std;

int N, M, S;
char map[110][110];

int main() {
	while (true) {
		scanf("%d %d %d\n", &N, &M, &S);
		if (N == 0 && M == 0 && S == 0) {
			break;
		}
		char start_dir;
		char tmp;
		int start_x, start_y;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%c", &tmp);
				map[i][j] = tmp;
				if (tmp == 'N' || tmp == 'S' || tmp == 'L' || tmp == 'O') {
					start_dir = tmp;
					start_y = i;
					start_x = j;
				}
			}
			scanf("%c", &tmp);
		}
		//scanf("%c", &tmp);

		char cmd;
		int points = 0;
		for (int i = 0; i < S; i++) {
			int old_x = start_x, old_y = start_y;
			scanf("%c", &cmd);
			//printf("command: %c\n", cmd);
			if (cmd == 'F') {
				//printf("forward: %c\n", start_dir);
				if (start_dir == 'N') {
					start_y--;
				} else if (start_dir == 'S') {
					start_y++;
				} else if (start_dir == 'L') {
					start_x++;
				} else if (start_dir == 'O') {
					start_x--;
				}
			} else if (cmd == 'D') { // right
				if (start_dir == 'N') {
					start_dir = 'L';
				} else if (start_dir == 'S') {
					start_dir = 'O';
				} else if (start_dir == 'L') {
					start_dir = 'S';
				} else if (start_dir == 'O') {
					start_dir = 'N';
				}
			} else if (cmd == 'E') { // left
				if (start_dir == 'N') {
					start_dir = 'O';
				} else if (start_dir == 'S') {
					start_dir = 'L';
				} else if (start_dir == 'L') {
					start_dir = 'N';
				} else if (start_dir == 'O') {
					start_dir = 'S';
				}
			}

			//printf("pos %d %d %c\n", start_x, start_y, start_dir);
			if (start_y < 0 || start_y >= N) start_y = old_y;
			if (start_x < 0 || start_x >= M) start_x = old_x;
			if (map[start_y][start_x] == '*') {
				points++;
				map[start_y][start_x] = '.';
			} else if (map[start_y][start_x] == '#') {
				start_x = old_x;
				start_y = old_y;
			}
			//printf("pos %d %d %c\n", start_x, start_y, start_dir);
		}
		printf("%d\n", points);
/*
		printf("%d %d %d %c\n", N, M, S, start_dir);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				printf("%c", map[i][j]);
			}
			printf("\n");
		}*/
	}
	return 0;
}
