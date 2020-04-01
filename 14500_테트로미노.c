#if 1
#include <stdio.h>
#define MAX 500
int n, m;
int map[MAX][MAX];
int visit[MAX][MAX];
int dirx[4] = { 0,1,0,-1 };
int diry[4] = { 1,0,-1,0 };
int sum, answer;
void inputData();
void solve();
void tetromino(int turn, int x, int y);
void tetromino2(int x, int y);
int main()
{
	inputData();
	solve();
	return 0;
}
void inputData()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
}
void solve()
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
				tetromino(1, i, j);
				visit[i][j] = 0;
				sum = 0;
				tetromino2(i, j);
		}
	}
	printf("%d", answer);

}
void tetromino(int turn, int x, int y)
{
	if (turn > 4)
	{
		if (answer < sum) answer = sum;
		return;
	}
	visit[x][y] = 1;
	sum += map[x][y];

	for (int dir = 0; dir < 4; dir++)
	{
		int nextx = x + dirx[dir];
		int nexty = y + diry[dir];
		if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m) continue;
		if (visit[nextx][nexty]) continue;
		tetromino(turn + 1, nextx, nexty);
	}
	visit[x][y] = 0;
	sum -= map[x][y];
}
void tetromino2( int x, int y)
{
	int side1=0, side2=0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int nextx = x - i + j;
			if (nextx < 0 || nextx >= n) continue;
			if (j == 1)
			{
				if (y + 1 < m) side1 = map[nextx][y + 1];
				if (y - 1 >= 0) side2 = map[nextx][y - 1];
			}
			sum += map[nextx][y];
		}
		if ((sum + side1) > answer) answer = sum + side1;
		if ((sum + side2) > answer) answer = sum + side2;
		sum = 0;
	}

	sum = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int nexty = y - i + j;
			if (nexty < 0 || nexty >= m) continue;
			if (j == 1)
			{
				if (x + 1 < n) side1 = map[x + 1][nexty];
				if (x - 1 >= 0) side2 = map[x - 1][nexty];
			}
			sum += map[x][nexty];
		}
		if ((sum + side1) > answer) answer = sum + side1;
		if ((sum + side2) > answer) answer = sum + side2;
		sum = 0;
	}

}
#endif