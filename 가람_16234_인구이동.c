#if 1

#include <stdio.h>
#include <stdlib.h>

int pop[55][55];
int visit[55][55];
int que[100000][2];
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int front, rear;
int cnt;
int L, R;
int N;


int unions(int x, int y) {

	int country = 0;
	int population = 0;
	front = 0;
	rear = 0;
	que[rear][0] = x;
	que[rear][1] = y;
	rear++;
	visit[x][y] = 1;
	while (front < rear) {
		int xx = que[front][0];
		int yy = que[front][1];
		country++;
		population += pop[xx][yy];
		front++;
		for (int i = 0; i < 4; i++) {
			int next_x = xx + dir[i][0];
			int next_y = yy + dir[i][1];
			if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= N) continue;
			if (visit[next_x][next_y] == 0 && abs(pop[xx][yy] - pop[next_x][next_y]) >= L && abs(pop[xx][yy] - pop[next_x][next_y]) <= R) {
				que[rear][0] = next_x;
				que[rear][1] = next_y;
				rear++;
				visit[next_x][next_y] = 1;
			}
		}
	}

	if (rear == 1) return 0;

	int avg = population / country;
	for (int i = 0; i < rear;i++) {
		pop[que[i][0]][que[i][1]] = avg;
	}

	return 1;
}



int main() {

	scanf("%d %d %d", &N, &L, &R);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &pop[i][j]);
		}
	}

	for (int k = 0; k < 2000; k++) {

		int d_cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visit[i][j]) continue;
					int f = unions(i, j);
					if (f) {

						d_cnt++;
					}				
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visit[i][j] = 0;
			}
		}

		if (d_cnt == 0) break;
		cnt++;

	}

	printf("%d", cnt);

	return 0;
}

#endif