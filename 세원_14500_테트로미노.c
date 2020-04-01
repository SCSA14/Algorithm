#if 0
#include <stdio.h>
int n, m, sum, max = -1, originX, originY;
int map[501][501];
int visited[501][501];
int dirx[4] = { 0, 0, 1, -1 };
int diry[4] = { 1, -1, 0, 0 };

void DFS(int x, int y, int cnt) {
	if (cnt == 1) {
		originX = x;
		originY = y;
		sum += map[x][y];
		visited[x][y] = 1;
	}

	if (cnt == 3) {
		if (originX + 2 == x && originY == y) {
			int newxx = (originX + x) / 2;
			int newyy = y - 1;
			int newyy2 = y + 1;
			if (newxx >= 0 && newxx < n && newyy >= 0 && newyy < m) {
				sum += map[newxx][newyy];
				if (max < sum) max = sum;
				sum -= map[newxx][newyy];
			}
			if (newxx >= 0 && newxx < n && newyy2 >= 0 && newyy2 < m) {
				sum += map[newxx][newyy2];
				if (max < sum) max = sum;
				sum -= map[newxx][newyy2];
			}
		}
		if (originX == x && originY + 2 == y) {
			int newxx = x + 1;
			int newxx2 = x - 1;
			int newyy = (originY + y) / 2;
			if (newxx >= 0 && newxx < n && newyy >= 0 && newyy < m) {
				sum += map[newxx][newyy];
				if (max < sum) max = sum;
				sum -= map[newxx][newyy];
			}
			if (newxx2 >= 0 && newxx2 < n && newyy >= 0 && newyy < m) {
				sum += map[newxx2][newyy];
				if (max < sum) max = sum;
				sum -= map[newxx2][newyy];
			}
		}
	}

	if (cnt == 4) {
		if (max < sum) max = sum;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int newx = x + dirx[i];
		int newy = y + diry[i];
		if (newx >= 0 && newx < n && newy >= 0 && newy < m && visited[newx][newy] == 0) {
			sum += map[newx][newy];
			visited[newx][newy] = 1;
			DFS(newx, newy, cnt + 1);
			sum -= map[newx][newy];
			visited[newx][newy] = 0;
		}
	}

	return;
}

int main() {
	int i, j, k, l;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			sum = 0;
			for (k = i - 3; k <= i + 3; k++) {
				for (l = j - 3; l <= j + 3; l++) {
					if (k < 0 || k >= n || l < 0 || l >= m) continue;
					visited[k][l] = 0;
				}
			}
			DFS(i, j, 1);
		}
	}

	printf("%d\n", max);
	return 0;
}
#endif
