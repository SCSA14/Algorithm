#if 0
#include <stdio.h>
#define MAX 101

int r, c, m;

typedef struct _fish
{
	int num;
	int x;
	int y;
	int speed;
	int dir;
	int size;
}fish;

int map[MAX][MAX];
fish sharks[MAX * MAX + 2];

int amount;

int dirx[4] = { -1,1,0,0 };
int diry[4] = { 0,0,1,-1 };

int inputData();
int fishing(int sec);
int moveShark();
int clear();

int main()
{
	inputData();
	for (int i = 0; i < c; i++)
	{
		fishing(i);
		moveShark();
	}
	printf("%d", amount);
	return 0;
}
int inputData()
{
	scanf("%d %d %d", &r, &c, &m);
	for (int i = 0; i < m; i++)
	{
		int x, y, speed, dir, size;
		scanf("%d %d %d %d %d", &x,&y,&speed,&dir,&size);

		fish shark = { (i+1), (x-1), (y-1), speed, (dir-1), size };
		map[shark.x][shark.y] = shark.num;
		shark.speed = shark.dir < 2 ? shark.speed % (2 * r - 2) : shark.speed % (2 * c - 2);
		sharks[i+1] = shark;
	}
	return 0;
}
int fishing(int sec)
{
	for (int i = 0; i < r; i++)
	{
		if (!map[i][sec]) continue;

		fish shark = sharks[map[i][sec]];
		if (!shark.size) continue;

		amount += shark.size;

		sharks[map[i][sec]].size = 0;
		map[i][sec] = 0;
		return 0;
	}

}

int moveShark()
{
	//move
	for (int i = 1; i <= m; i++)
	{
		if (!sharks[i].size) continue;

		//fish shark = sharks[i];
		for (int j = 0; j < sharks[i].speed; j++)
		{
			int nextx = sharks[i].x + dirx[sharks[i].dir];
			int nexty = sharks[i].y + diry[sharks[i].dir]; 
			if (nextx < 0 || nextx >= r || nexty < 0 || nexty >= c)
			{
				switch (sharks[i].dir)
				{
				case 0: sharks[i].dir = 1; break;
				case 1: sharks[i].dir = 0; break;
				case 2: sharks[i].dir = 3; break;
				case 3: sharks[i].dir = 2; break;
				}
			}

			sharks[i].x = sharks[i].x + dirx[sharks[i].dir];
			sharks[i].y = sharks[i].y + diry[sharks[i].dir];

		}
		//sharks[i] = shark;
	}

	clear();
	
	//put sharks on map
	for (int i = 1; i <= m; i++)
	{
		if (!sharks[i].size) continue;	
		fish shark = sharks[i];
		if (!map[shark.x][shark.y] || sharks[map[shark.x][shark.y]].size < shark.size)
		{
			if(map[shark.x][shark.y]) sharks[map[shark.x][shark.y]].size = 0;
			map[shark.x][shark.y] = shark.num;
		}
		else sharks[i].size = 0;
	}



	return 0;
}
int clear()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			map[i][j] = 0;
		}
	}
	return 0;
}
#endif
