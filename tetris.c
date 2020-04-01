#if 1
/*
�ܼ��� DFS�� ����� üũ�ϴ� �͸����� ������ Ž���� �����ϴ�.
�ٸ� �� ��� ���� ���� ���� ó���� ����� �Ѵ�.
*/
#include <stdio.h>
int N, M;
int map[510][510];
int sums[510][510]; /////////��ϵ��� ���� �հ踦 �����Ѵ�.
int cnt; ///���° ��������� ��Ÿ����.
int dir[4][2] = { {1,0}, {-1,0}, {0,-1}, {0,1} }; ///�����̴� ����
int straight[4]; //�� �������� ��� �������� ���������� üũ. �� ��� ���ܸ� üũ�ϱ� ���� �ʿ�.
int max = -1;
void DFS(int x, int y, int sum) { ////////////////���ο� x��ǥ,y��ǥ, �׸��� �� �� ��ϱ����� ���� �հ踦 �μ��� ����.
    int newx = 0;
    int newy = 0;
    int i = 0;
    sums[x][y] = sum + map[x][y];
    if (cnt == 3) { ///////////////////////////////////4��° ����̸� ��������� max�� ���ؼ� ����.
        if (sums[x][y] > max) max = sums[x][y];
        return;
    }

    for (i = 0; i < 4; i++) { //////////////////////���üũ.
        newx = x + dir[i][0];
        newy = y + dir[i][1];
        if (newx < 0 || newx >= N || newy < 0 || newy >= M) continue;
        if (sums[newx][newy]) continue;
        cnt++;
        straight[i]++;
        DFS(newx, newy, sums[x][y]);
        if (straight[i] == 2 && cnt == 2) { ///////////���������� ���� �� �� ���� �̵��߰�, ���� ��ġ�� ����° ����̸� �� ��� ����� �հ踦 üũ.
            int fx = x + dir[i][1];
            int fy = y + dir[i][0];
            if (!(fx < 0 || fx >= N || fy < 0 || fy >= M)) {
                if (sums[newx][newy] + map[fx][fy] > max) max = sums[newx][newy] + map[fx][fy];
            }
        }
        sums[newx][newy] = 0; /////////////��Ʈ��ŷ.
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
    for (i = 0; i < N;i++) { /////////////////��� ��ǥ���� DFS�� ��� ��ϵ��� üũ.
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