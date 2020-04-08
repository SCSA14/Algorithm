#include <stdio.h>
int R, C, T, idx, sol;
int clear[2];
int A[52][52];
int result_m[52][52];
int result_wind[52][52];
int dirx[4] = { 0, 0, -1, 1 };
int diry[4] = { 1, -1, 0, 0 };
void munji(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int newx = x + dirx[i];
		int newy = y + diry[i];
		if (newx <= 0 || newx > R || newy <= 0 || newy > C) continue;
		if (A[newx][newy] == -1) continue;
		result_m[newx][newy] += (A[x][y] / 5);
		cnt++;
	}
	result_m[x][y] += (A[x][y] - (A[x][y] / 5) * cnt);
}
void wind() {
	for (int i = 1; i <= clear[0]; i++) {
		for (int j = 1; j <= C; j++) {
			if (i == 1 && j < C) result_wind[i][j] = result_m[i][j + 1];
			else if (i == clear[0] && j > 1) result_wind[i][j] = result_m[i][j - 1];
			else if (j == 1 && i > 1) result_wind[i][j] = result_m[i - 1][j];
			else if (j == C && i < R) result_wind[i][j] = result_m[i + 1][j];
			else result_wind[i][j] = result_m[i][j];
		}
	}
	for (int i = clear[1]; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (i == clear[1] && j > 1) result_wind[i][j] = result_m[i][j - 1];
			else if (i == R && j < C) result_wind[i][j] = result_m[i][j + 1];
			else if (j == 1 && i < R) result_wind[i][j] = result_m[i + 1][j];
			else if (j == C && i > 1) result_wind[i][j] = result_m[i - 1][j];
			else result_wind[i][j] = result_m[i][j];
		}
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (result_wind[i][j] == -1) result_wind[i][j] = 0;
		}
	}
	result_wind[clear[0]][1] = -1;
	result_wind[clear[1]][1] = -1;
}
int main() {
	scanf("%d %d %d", &R, &C, &T);
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			scanf("%d", &A[i][j]);
			if (A[i][j] == -1) {
				clear[idx++] = i;
			}
		}
	}
	
	while (T > 0) {
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if(A[i][j] > 0) munji(i, j);
			}
		}
		
		wind();

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				result_m[i][j] = 0;
				A[i][j] = result_wind[i][j];
			}
		}
		T--;
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (A[i][j] != -1) sol += A[i][j];
		}
	}
	printf("%d", sol);
	return 0;
}
