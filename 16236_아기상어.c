#if 0
#include <stdio.h>
#define MAX 20
int n;
int map[MAX][MAX];
typedef struct point {
	int x;
	int y;
}point;
point queue[1000000];
point start;
int visit[MAX][MAX];
int fish[7];

int dirx[4] = { -1, 0, 0, 1 };	//북 서 동 남
int diry[4] = { 0, -1, 1, 0 };
int shark_size = 2, xp= 0;
int cnt;
struct temp_ {
	int x;
	int y;
	int cnt;
	int write;
}temp;
int sol;

void inputData();
int moveShark(point point);
void clear();
int isFishLeft();

int main()
{
	scanf("%d", &n);

	inputData();
	printf("%d", moveShark(start));
	return 0;
}

void inputData()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9)
			{
				map[i][j] = 0;
				start.x = i;
				start.y = j;
			}
			else if (map[i][j])
			{
				fish[map[i][j]]++;
			}
		}
}
int isFishLeft()
{
	int i;
	//아기상어보다 작은 물고기 남았으면 1
	for (i = 1; i < shark_size; i++)
	{
		if (fish[i]) break;
	}
	if (i == shark_size) return 0;
	else return 1;
}
void clear()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visit[i][j] = 0;
}
void sizeup()
{
	if (++xp == shark_size)
	{
		shark_size++; xp = 0;
	}
}
int moveShark(point start)
{
	int read = 0, write = 0;
	queue[write++] = start;
	visit[start.x][start.y] = 0;

	if (!isFishLeft()) return sol;

	while (read < write) 
	{
		point now = queue[read++];
		cnt = visit[now.x][now.y] + 1;
		if (temp.cnt && cnt > temp.cnt)
		{
			fish[map[temp.x][temp.y]]--;
			map[temp.x][temp.y] = 0;
			sol = temp.cnt;
			clear(); visit[temp.x][temp.y] = temp.cnt;	//현재 위치 제외 visit 초기화
			sizeup();
			if (!isFishLeft()) return sol;
			temp.cnt = 0;
			write = temp.write + 1;
			read = temp.write;
			continue;
		}

		for (int dir = 0; dir < 4; dir++)
		{
			int nextx = now.x + dirx[dir];
			int nexty = now.y + diry[dir];
			if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= n) continue;
			if (map[nextx][nexty] > shark_size) continue;
			if (visit[nextx][nexty]) continue;

			point next = { now.x + dirx[dir], now.y + diry[dir] };
			queue[write++] = next;
			visit[next.x][next.y] = cnt;
			if (map[nextx][nexty] && map[nextx][nexty] < shark_size)
			{
				//먹을 수 있는 물고기를 만났을 때
				if (!temp.cnt)
				{
					temp.cnt = cnt;
					temp.x = next.x; temp.y = next.y;
					temp.write = write - 1;
				}
				else if (temp.x > next.x || (temp.x==next.x && temp.y>=next.y))
				{
					temp.cnt = cnt;
					temp.x = next.x; temp.y = next.y;
					temp.write = write - 1;
				}
			}
		}
	}
	return sol;
}

#endif