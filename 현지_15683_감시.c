#if 0
#include <stdio.h>
#define MAX 10
int n, m;
int map[MAX][MAX];
typedef struct cctv_
{
	int type;
	int x;
	int y;
}cctv;
cctv cctvs[10];
int idx;
int min = MAX*MAX;

int dirx[4] = { 1,0,-1,0 };
int diry[4] = { 0,1,0,-1 };


void inputData();
void solve();
void watch(int i);
void runCCTV(int idx, int type, int dir);
int count();
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
			if (map[i][j] >= 1 && map[i][j] <= 5) 
			{
				cctv CCTV = { map[i][j], i, j };
				cctvs[idx++] = CCTV;
			}
		}
	}
}
void solve()
{
	watch(0);
	if (idx == 0) printf("%d", count());
	else printf("%d", min);
}
void watch(int i)
{
	cctv now = cctvs[i];
	int temp[MAX][MAX];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			temp[i][j] = map[i][j];

	for (int dir = 0; dir < 4; dir++)
	{
		if (now.type == 2 && dir > 1) continue;
		if (now.type == 5 && dir > 0) continue;
	
		runCCTV(i, now.type, dir);
		
		if (i == idx - 1)
		{
			int temp = count();
			if (min > temp) min = temp;
		}

		for (int j = i+1; j < idx; j++)
		{
			watch(j);
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				map[i][j] = temp[i][j];

	}

}

void runCCTV(int idx, int type, int dir)
{
	int nextx = cctvs[idx].x + dirx[dir];
	int nexty = cctvs[idx].y + diry[dir];
	
	map[cctvs[idx].x][cctvs[idx].y] = 7;
	switch (type)
	{
		case 1:
			while (nextx < n && nextx >= 0 && nexty < m && nexty >= 0)
			{
				if (map[nextx][nexty] == 6) break;
				map[nextx][nexty] = 7;
				nextx += dirx[dir];
				nexty += diry[dir];
			}
			break;
		case 2:
			runCCTV(idx, 1, dir);
			runCCTV(idx, 1,(dir + 2) % 4);
			break;
		case 3:
			//³² ¼­ ºÏ µ¿
			runCCTV(idx, 1, dir);
			runCCTV(idx, 1, (dir + 1) % 4);
			break;
		case 4:
			runCCTV(idx, 1, dir);
			runCCTV(idx, 2, (dir + 1) % 4);
			break;
		case 5:
			runCCTV(idx, 2, dir);
			runCCTV(idx, 2, (dir + 1) % 4);
			break;
	}
}

int count()
{
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!map[i][j]) cnt++;
		}
	}

	return cnt;
}
#endif
