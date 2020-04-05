﻿#if 1

#include <stdio.h>

int N, M;
int map[25][25]; ///////물고기와 아기상어의 위치
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} }; ////////사방 움직임
int que[10000][3];////////BFS구현을 위한 큐
int front, rear;
int shark[2];///////////아기상어의 위치
int fish[2];//////////잡아먹을 물고기의 위치
int time;///////////아기상어가 돌아다니는 시간
int size = 2;////////////아기상어의 사이즈
int eat;////////////아기상어가 먹은 물고기 수

int check_time(int sx, int sy, int dx, int dy) {

	//sx = 아기상어의 x좌표
	//sy = 아기상어의 y좌표
	//dx = 물고기의 x좌표 
	//dy = 물고기의 y좌표

	//BFS 알고리즘으로 최단거리를 계산하여 아기 상어가 대상이 되는 물고기까지 이동하기 위해 걸리는 시간을 리턴하는 함수이다.
	//물고기가 있는 위치까지 이동하는 것이 불가능할 시 초기값인 0을 리턴한다.

	int path[25][25] = { 0, }; ////아기 상어에서 해당 칸까지의 거리를 저장한다. 0으로 초기화 되어 있다.

	front = 0;
	rear = 0;
	que[rear][0] = sx;
	que[rear][1] = sy;
	que[rear][2] = 0;
	rear++;

	while (front < rear) {
		int x = que[front][0];
		int y = que[front][1];
		int t = que[front][2];
		front++;
		for (int i = 0; i < 4; i++) {
			int xx = x + dir[i][0];
			int yy = y + dir[i][1];
			if (xx < 0 || xx >= N || yy < 0 || yy >= N || (xx == sx && yy == sy)) continue;
			if (map[xx][yy] <= size && path[xx][yy] == 0) {
				que[rear][0] = xx;
				que[rear][1] = yy;
				que[rear][2] = t + 1;
				rear++;
				path[xx][yy] = t + 1;
				if (xx == dx && yy == dy) return path[dx][dy];
			}
		}
	}
}


void target() {

	//check_time 함수를 호출하여 가장 가까이 있는 물고기를 탐색하는 함수이다.
	//왼쪽 위부터 탐색하여 물고기가 더 가까이 있을 경우에만 잡아먹을 물고기의 위치와 이동 시에 걸리는 시간을 갱신해준다.
	//탐색이 끝난 후 총 이동시간에 잡아먹을 물고기까지 이동하는 데 걸리는 시간을 더해준다.
	//더 이상 잡아먹을 물고기가 없을 시 fish[0]이 -1인채로 리턴한다.

	int nearest = 30000;

	fish[0] = -1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == shark[0] && j == shark[1]) continue;
			if (map[i][j] && map[i][j] < size) {
				int t = check_time(shark[0], shark[1], i, j);
				if (t == 0) continue;
				if (t < nearest) {
					fish[0] = i;
					fish[1] = j;
					nearest = t;
				}
			}
		}
	}
	if (fish[0] == -1) return;
	time += nearest;

}



void solve() {

	//target 함수를 지속적으로 호출하여 아기 상어가 엄마 상어의 도움없이 돌아다니는 총 시간을 계산해주는 함수이다.
	//target함수 호출 후 fish[0] 좌표가 -1일 시 리턴한다.
	//잡아먹힌 물고기의 좌표 값, 아기상어의 좌표, 잡아먹은 물고기 수, 아기상어의 사이즈를 변경해준다.

	fish[0] = 0;
	fish[1] = 0;
	while (1) {
		target();
		if (fish[0] == -1) break;

		map[fish[0]][fish[1]] = 9;
		map[shark[0]][shark[1]] = 0;
		shark[0] = fish[0];
		shark[1] = fish[1];
		eat++;
		if (eat == size) {
			eat = 0;
			size++;
		}
	}
	return;
}



int main() {

	///입력값을 받아주고 solve 함수 호출 후 이동시간을 출력한다.

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) {
				shark[0] = i;
				shark[1] = j;
			}
		}
	}

	solve();

	printf("%d", time);

	return 0;

}
#endif