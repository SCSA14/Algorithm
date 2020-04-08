#if 01
#include <stdio.h>
int N, L, R, flag, sol;
int map[51][51];
int visit[51][51];
int dirx[4] = { 0, 0, 1, -1 };
int diry[4] = { 1, -1, 0, 0 };
int Queue[100000];

int abs(int a) {
	if (a < 0) return -a;
	else return a;
}

void BFS(int firstX, int firstY) {
	int read = 0;
	int write = 0;
	int sum = 0, cnt = 0;
	Queue[write++] = firstX;
	Queue[write++] = firstY;
	visit[firstX][firstY] = 1;

	while (read < write) {
		int x = Queue[read++];
		int y = Queue[read++];
		cnt++;
		sum += map[x][y];
	
		for (int k = 0; k < 4; k++) {
			int newx = x + dirx[k];
			int newy = y + diry[k];
			if (newx < 0 || newx >= N || newy < 0 || newy >= N) continue;
			if (visit[newx][newy] == 0 && abs(map[newx][newy] - map[x][y]) >= L && abs(map[newx][newy] - map[x][y]) <= R) {
				visit[newx][newy] = 1;
				Queue[write++] = newx;
				Queue[write++] = newy;		
				flag = 1;
			}
		}
	}

	sum /= cnt;
	for (int i = 0; i < write; i += 2) {
		map[Queue[i]][Queue[i + 1]] = sum;
	}
}
int main() {
	scanf("%d %d %d", &N, &L, &R);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	while (1) {
		flag = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visit[i][j] != 0) continue;
				BFS(i, j);
			}
		}
		
		if (flag == 0) break;
		else sol++;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visit[i][j] = 0;
			}
		}
	}
	printf("%d", sol);
	return 0;
}
#endif


//ÈñÁ¦²¨
#if 0

#include <stdio.h>
#include <stdlib.h>

int n;
int l, r, flag;
int a[50 + 10][50 + 10];
int visited[50 + 10][50 + 10];
int queue[100000];
int sol;

void BFS(int si, int sj) {
    int read = 0;
    int write = 0;
    int cnt = 1;
    int sum = 0;

    queue[write++] = si;
    queue[write++] = sj;
    visited[si][sj] = 1;
    sum += a[si][sj];

    while (read < write) {
        int i = queue[read++];
        int j = queue[read++];

        if (j + 1 < n && visited[i][j + 1] == 0) {
            if (l <= abs(a[i][j] - a[i][j + 1]) && abs(a[i][j] - a[i][j + 1]) <= r) {
                queue[write++] = i;
                queue[write++] = j + 1;
                visited[i][j + 1] = 1;
                sum += a[i][j + 1];
                cnt++;
                flag = 1;
            }
        }
        if (i + 1 < n && visited[i + 1][j] == 0) {
            if (l <= abs(a[i][j] - a[i + 1][j]) && abs(a[i][j] - a[i + 1][j]) <= r) {
                queue[write++] = i + 1;
                queue[write++] = j;
                visited[i + 1][j] = 1;
                sum += a[i + 1][j];
                cnt++;
                flag = 1;
            }
        }
        if (j - 1 >= 0 && visited[i][j - 1] == 0) {
            if (l <= abs(a[i][j] - a[i][j - 1]) && abs(a[i][j] - a[i][j - 1]) <= r) {
                queue[write++] = i;
                queue[write++] = j - 1;
                visited[i][j - 1] = 1;
                sum += a[i][j - 1];
                cnt++;
                flag = 1;
            }
        }
        if (i - 1 >= 0 && visited[i - 1][j] == 0) {
            if (l <= abs(a[i][j] - a[i - 1][j]) && abs(a[i][j] - a[i - 1][j]) <= r) {
                queue[write++] = i - 1;
                queue[write++] = j;
                visited[i - 1][j] = 1;
                sum += a[i - 1][j];
                cnt++;
                flag = 1;
            }
        }
    }

    int tmp = sum / cnt;

    for (int i = 0; i < write; i+=2) {
        a[queue[i]][queue[i + 1]] = tmp;
    }
    return;
}

int main() {
    scanf("%d %d %d", &n, &l, &r);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    while (1) {

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 0) {
                    BFS(i, j);      
                }
            }
        }

        if (flag == 0) break;
        sol++;
        flag = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = 0;
            }
        }
    }

    printf("%d\n", sol);

    return 0;
}

#endif
