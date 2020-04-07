#if 1
#include <stdio.h>
#include <stdlib.h>
#define MAX 50
int map[MAX][MAX];
int pop[MAX][MAX];

typedef struct _point
{
	int x;
	int y;
}point;
int n, l, r;

int dirx[4] = { 1,0,-1,0 };
int diry[4] = { 0,1,0,-1 };
int dist = 1;
int popSum[2501][2];

int cnt;

void inputData();
int solve();
void district(point p);
void clear();
int main()
{
	inputData();
	printf("%d", solve());
	return 0;
}
void inputData()
{
	scanf("%d %d %d", &n, &l, &r);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
}
int solve()
{
	int temp[MAX][MAX];

	for (;;)
	{
	int endFlag = 0;


		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				temp[i][j] = map[i][j];
			}

		clear();

		//union
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (!pop[i][j])
				{
					point start = { i,j };
					district(start);
					dist++;
				}


		//move
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				map[i][j] = popSum[pop[i][j]][0] / popSum[pop[i][j]][1];
			}

		//endFlag
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (temp[i][j] != map[i][j])  endFlag++; 

		if (!endFlag) break;
		cnt++;
	}
	return cnt;
}
void district(point start)
{
	pop[start.x][start.y] = dist;
	popSum[dist][0] += map[start.x][start.y];
	popSum[dist][1]++;

	for (int dir = 0; dir < 4; dir++)
	{
		int nextx = start.x + dirx[dir];
		int nexty = start.y + diry[dir];
		if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= n) continue;
		if (pop[nextx][nexty]) continue;
		if (abs(map[nextx][nexty] - map[start.x][start.y]) < l) continue;
		if (abs(map[nextx][nexty] - map[start.x][start.y]) > r) continue;
		point next = { nextx,nexty };
		district(next);
	}
}

void clear()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			pop[i][j] = 0;
		}
	}
	for (int i = 1; i <= dist; i++)
	{
		popSum[i][0] = 0; popSum[i][1] = 0;
	}
	dist = 1;
}
#endif
