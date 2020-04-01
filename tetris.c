#if 1
/*
단순히 DFS로 사방을 체크하는 것만으로 완전히 탐색이 가능하다.
다만 ㅗ 모양 블럭은 따로 예외 처리를 해줘야 한다.
*/
#include <stdio.h>
int N, M;
int map[510][510];
int sums[510][510]; /////////블록들의 값의 합계를 저장한다.
int cnt; ///몇번째 블록인지를 나타낸다.
int dir[4][2] = { {1,0}, {-1,0}, {0,-1}, {0,1} }; ///움직이는 방향
int straight[4]; //한 방향으로 몇번 연속으로 움직였는지 체크. ㅗ 모양 예외를 체크하기 위해 필요.
int max = -1;
void DFS(int x, int y, int sum) { ////////////////새로운 x좌표,y좌표, 그리고 그 전 블록까지의 값의 합계를 인수로 받음.
    int newx = 0;
    int newy = 0;
    int i = 0;
    sums[x][y] = sum + map[x][y];
    if (cnt == 3) { ///////////////////////////////////4번째 블록이면 현재까지의 max와 비교해서 갱신.
        if (sums[x][y] > max) max = sums[x][y];
        return;
    }

    for (i = 0; i < 4; i++) { //////////////////////사방체크.
        newx = x + dir[i][0];
        newy = y + dir[i][1];
        if (newx < 0 || newx >= N || newy < 0 || newy >= M) continue;
        if (sums[newx][newy]) continue;
        cnt++;
        straight[i]++;
        DFS(newx, newy, sums[x][y]);
        if (straight[i] == 2 && cnt == 2) { ///////////시작점부터 연속 두 번 직선 이동했고, 현재 위치가 세번째 블록이면 ㅗ 모양 블록의 합계를 체크.
            int fx = x + dir[i][1];
            int fy = y + dir[i][0];
            if (!(fx < 0 || fx >= N || fy < 0 || fy >= M)) {
                if (sums[newx][newy] + map[fx][fy] > max) max = sums[newx][newy] + map[fx][fy];
            }
        }
        sums[newx][newy] = 0; /////////////백트래킹.
        straight[i]--;
        cnt--;
    }
    return;
}
void init() {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M;j++) {
            sums[i][j] = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        straight[i] = 0;
    }
}
int main() {
    int i, j, k;
    scanf("%d %d", &N, &M);
    for (i = 0; i < N;i++) {
        for (j = 0; j < M;j++) {
            scanf("%d", &map[i][j]);
        }
    }
    for (i = 0; i < N;i++) { /////////////////모든 좌표에서 DFS로 모든 블록들을 체크.
        for (j = 0; j < M;j++) {
            DFS(i, j, 0);
            for (k = 0; k < 4;k++) {
                straight[k] = 0;
            }
            sums[i][j] = 0;
        }
    }
    printf("%d\n", max);
    return 0;
}
#endif