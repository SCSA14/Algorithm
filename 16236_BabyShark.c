#include <stdio.h>
int N, L, R, move;
int map[55][55];
int visit[55][55];
int queue[100100][2];
int dirx[4] = { 0,1,0,-1 };
int diry[4] = { 1,0,-1,0 };
int abb(int x) {
	if (x < 0) return x * -1;
	else return x;
}
void clr() {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			visit[i][j] = 0;
		}
	}
}
void bfs(int x, int y) {
	int i, read = 0, write = 0, cnt = 1,sum=0;
	visit[x][y] = 1;
	queue[write][0] = x;
	queue[write++][1] = y;
	while (read != write) {
		int xx = queue[read][0];
		int yy = queue[read++][1];
		int val = map[xx][yy];
		for (i = 0; i < 4; i++) {
			if (xx + dirx[i] < 0 || xx + dirx[i] >= N || yy + diry[i] < 0 || yy + diry[i] >= N) continue;
			
			if (abb(map[xx + dirx[i]][yy + diry[i]] - val) >= L && abb(map[xx + dirx[i]][yy + diry[i]] - val) <= R && visit[xx + dirx[i]][yy + diry[i]]==0) {
				visit[xx + dirx[i]][yy + diry[i]] = 1;
				cnt++;
				queue[write][0] = xx + dirx[i];
				queue[write++][1] = yy + diry[i];
			}
		}
	}
	for (i = 0; i < write; i++) {
		sum += map[queue[i][0]][queue[i][1]];
	}
	sum = sum / cnt;
	for (i = 0; i < write; i++) {
		map[queue[i][0]][queue[i][1]] = sum;
	}
}
int main() {
	int i,j;
	scanf("%d %d %d",&N, &L, &R);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	while (1) {
		int cnt = 0;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (visit[i][j] == 1) continue;
				cnt++;
				bfs(i, j);
			}
		}
		clr();
		if (cnt == N * N) break;
		move++;
		
	}
	printf("%d\n", move);
}
