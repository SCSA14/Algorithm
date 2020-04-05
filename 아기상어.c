#if 1

#include <stdio.h>

int N, M;
int map[25][25];
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int que[10000][3];
int front, rear;
int shark[2];
int fish[2];
int time;
int size = 2;
int eat;

int check_time(int sx, int sy, int dx, int dy) {

	int path[25][25] = { 0, };
	front = 0;
	rear = 0;
	que[rear][0] = sx;
	que[rear][1] = sy;
	que[rear][2] = 0;
	rear++;

	while (front < rear) {
		int x = que[front][0];
		int y = que[front][1];
		int t = que[front][2];
		front++;
		for (int i = 0; i < 4; i++) {
			int xx = x + dir[i][0];
			int yy = y + dir[i][1];
			if (xx < 0 || xx >= N || yy < 0 || yy >= N || (xx == sx && yy == sy)) continue;
			if (map[xx][yy] <= size && path[xx][yy] == 0) {
				que[rear][0] = xx;
				que[rear][1] = yy;
				que[rear][2] = t + 1;
				rear++;
				path[xx][yy] = t + 1;
				if (xx == dx && yy == dy) return path[dx][dy];
			}
		}
	}
}

void target() {

	int nearest = 30000;

	fish[0] = -1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == shark[0] && j == shark[1]) continue;
			if (map[i][j] && map[i][j] < size) {
				int t = check_time(shark[0], shark[1], i, j);
				if (t == 0) continue;
				if (t < nearest) {
					fish[0] = i;
					fish[1] = j;
					nearest = t;
				}
			}
		}
	}
	if (fish[0] == -1) return;
	time += nearest;

}

void solve() {
	fish[0] = 0;
	fish[1] = 0;
	while (1) {
		target();
		if (fish[0] == -1) break;



		map[fish[0]][fish[1]] = 9;
		map[shark[0]][shark[1]] = 0;
		shark[0] = fish[0];
		shark[1] = fish[1];
		eat++;
		if (eat == size) {
			eat = 0;
			size++;
		}
	}
	return;
}



int main() {

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) {
				shark[0] = i;
				shark[1] = j;
			}
		}
	}

	solve();

	printf("%d", time);

	return 0;

}
#endif