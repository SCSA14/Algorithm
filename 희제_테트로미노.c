#define _CRT_SECURE_NO_WARNINGS

#if 1
#include <stdio.h>

int n, m;
int map[500 + 10][500 + 10];
int visited[500 + 10][500 + 10];
int max;

void DFS(int i, int j, int cnt, int sum, int visited[500 + 10][500 + 10]) {
    if (cnt >= 4) {
        if (max < sum) max = sum;
        return;
    }

    visited[i][j] = 1;
    sum += map[i][j];

    if (j + 1 < m && visited[i][j + 1] == 0) DFS(i, j + 1, cnt + 1, sum, visited);
    if (i + 1 < n && visited[i + 1][j] == 0) DFS(i + 1, j, cnt + 1, sum, visited);
    if (j - 1 >= 0 && visited[i][j - 1] == 0) DFS(i, j - 1, cnt + 1, sum, visited);
    if (i - 1 >= 0 && visited[i - 1][j] == 0) DFS(i - 1, j, cnt + 1, sum, visited);

    visited[i][j] = 0;
    sum -= map[i][j];

}

void fuck(int i, int j) {
    if (i - 1 >= 0 && i + 1 < n && j + 1 < m && j >= 0) {
        int tmp = map[i][j] + map[i][j + 1] + map[i - 1][j + 1] + map[i + 1][j + 1];
        max = max < tmp ? tmp : max;
    }

    if (i - 1 >= 0 && i + 1 < n && j < m && j - 1 >= 0) {
        int tmp = map[i][j] + map[i][j - 1] + map[i - 1][j - 1] + map[i + 1][j - 1];
        max = max < tmp ? tmp : max;
    }

    if (i >= 0 && i + 1 < n && j + 1 < m && j - 1 >= 0) {
        int    tmp = map[i][j] + map[i + 1][j + 1] + map[i + 1][j] + map[i + 1][j - 1];
        max = max < tmp ? tmp : max;
    }

    if (i - 1 >= 0 && i < n && j + 1 < m && j - 1 >= 0) {
        int tmp = map[i][j] + map[i - 1][j - 1] + map[i - 1][j] + map[i - 1][j + 1];
        max = max < tmp ? tmp : max;
    }
}


int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cnt = 0;
            int sum = 0;

            DFS(i, j, cnt, sum, visited);
            fuck(i, j);
            visited[i][j] = 0;
        }
    }

    printf("%d\n", max);

    return 0;
}
#endif

