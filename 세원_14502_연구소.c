#include <stdio.h>
int N, M, idx, sol;
int state[10][10];
int visit[10][10];
int virus[22];
int dirx[4] = { 0, 0, 1, -1 };
int diry[4] = { 1, -1, 0, 0 };

int check() {
	int safe = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] == 0 && state[i][j] != 1) safe++;
		}
	}
	if (sol < safe) sol = safe;
	return 1;
}

void DFS(int x, int y) {
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int newx = x + dirx[i];
		int newy = y + diry[i];
		if (newx < 0 || newx >= N || newy < 0 || newy >= M) continue;
		if (state[newx][newy] != 1 && visit[newx][newy] == 0) {
			DFS(newx, newy);
		}
	}
	return;
}

void DFSwall(int x, int y, int cnt) {
	if (cnt == 3) {
		for (int i = 0; i < idx; i += 2) DFS(virus[i], virus[i + 1]);
		check();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visit[i][j] = 0;
			}
		}
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (state[i][j] == 0) {
				state[i][j] = 1;
				cnt++;
				DFSwall(i, j, cnt);
				state[i][j] = 0;
				cnt--;
			}
		}
	}
}
int main() {
	int cnt = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &state[i][j]);
			if (state[i][j] == 2) {
				virus[idx++] = i;
				virus[idx++] = j;
			}
		}
	}

	DFSwall(0, 0, 0);

	printf("%d", sol);
}
