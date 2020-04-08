#include <stdio.h>
int N, M, sol = 999999, flag, idx;
int state[51][51];
int timeCnt[51][51];
int tmpCnt[22][51][51];
int isactive[51][51];
int virus[22];
int queue[100000];
int dirx[4] = { 0, 0, 1, -1 };
int diry[4] = { 1, -1, 0, 0 };

int check() {
	int max = -50;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (state[i][j] == 0 && timeCnt[i][j] == 0) return 0;
			if (state[i][j] == 0 && timeCnt[i][j] > max) max = timeCnt[i][j];
		}
	}
	if (max == -50) sol = 1;
	else if (sol > max) sol = max;
	return 1;
}
void BFS(int firstX, int firstY) {
	int read = 0;
	int write = 0;
	int visit[51][51] = { 0, };
	queue[write++] = firstX;
	queue[write++] = firstY;
	visit[firstX][firstY] = 1;
	timeCnt[firstX][firstY] = 1;
	while (read < write) {
		int x = queue[read++];
		int y = queue[read++];
		int cnt = timeCnt[x][y];
		for (int i = 0; i < 4; i++) {
			int newx = x + dirx[i];
			int newy = y + diry[i];
			if (newx < 0 || newx >= N || newy < 0 || newy >= N) continue;
			if (state[newx][newy] != 1 && visit[newx][newy] == 0) {
				if(timeCnt[newx][newy] == 0 || timeCnt[newx][newy] > cnt + 1) timeCnt[newx][newy] = cnt + 1;
				visit[newx][newy] = 1;
				queue[write++] = newx;
				queue[write++] = newy;
			}
		}
	}
}

void DFS(int x, int cnt) {
	if (x > idx) return;
	if (cnt == M) {
		if(check()) flag = 1;
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tmpCnt[x][i][j] = timeCnt[i][j];
		}
	}
	BFS(virus[x], virus[x + 1]); // BFS는 좌표 값을 넘겨줌
	isactive[virus[x]][virus[x + 1]] = 1;
	DFS(x + 2, cnt + 1); //DFS는 인덱스값
	
	if (x > idx) return;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			timeCnt[i][j] = tmpCnt[x][i][j];
		}
	}
	isactive[virus[x]][virus[x + 1]] = 0;
	DFS(x + 2, cnt);
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &state[i][j]);
			if (state[i][j] == 2) {
				virus[idx++] = i;
				virus[idx++] = j;
			}
		}
	}


	DFS(0, 0);

	if (flag == 1) printf("%d", sol - 1); 
	else printf("-1");

	return 0;
}
