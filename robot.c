/*·Îº¿Ã»¼Ò±â*/
#if 1

#include <stdio.h>

int N, M;
int r, c, d;
int dir[4][2] = { {0,-1},{1,0},{0,1},{-1,0} }; // ¼­ ³² µ¿ ºÏ
int floor[55][55];
int visit[55][55];
int cnt = 0;
int endflag = 0;

void DFS(int x, int y, int di) {

    if (visit[x][y] == 0) {
        visit[x][y] = 1;
        cnt++;
    }


    int flag = 1;

    for (int i = 0; i < 4; i++) {

        int next = (di + i) % 4;
        if (!(x + dir[next][0] < 1 || x + dir[next][0] > N || y + dir[next][1] < 1 || y + dir[next][1] > M)) {
            if (!floor[x + dir[next][0]][y + dir[next][1]] && !visit[x + dir[next][0]][y + dir[next][1]]) {
                flag = 0;
                DFS(x + dir[next][0], y + dir[next][1], (next + 1) % 4);
                if (endflag == 1) return;
                break;
            }
        }
    }

    if (flag) {

        int next = (di + 1) % 4;

        if (!(x + dir[next][0] < 1 || x + dir[next][0] > N || y + dir[next][1] < 1 || y + dir[next][1] > M))
        {
            if (floor[x + dir[next][0]][y + dir[next][1]]) {
                endflag = 1;
                return;
            }
            else DFS(x + dir[next][0], y + dir[next][1], di);
        }

    }

}


int main() {

    scanf("%d %d", &N, &M);
    scanf("%d %d %d", &r, &c, &d);
    if (d == 1) d = 3;
    else if (d == 3) d = 1;
    for (int i = 0; i < N;i++) {
        for (int j = 0;j < M;j++) {
            scanf("%d", &floor[i][j]);
        }
    }
    DFS(r, c, d);
    printf("%d", cnt);

}



#endif