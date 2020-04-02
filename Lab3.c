#include <stdio.h>

int n, m,idx,cnt,min = 100000000,total,brk,pin;
int map[55][55];
int num[55][55];
int visit[55][55];
int virus[11][2];
int queue[1001000][2];
int dirx[4] = { 0,1,0,-1 };
int diry[4] = { 1,0,-1,0 };

int check() {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (map[i][j] == 0 && visit[i][j] == 0) return 0;
		}
	}
	return 1;
}

void clr() {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			num[i][j] = 0;
			visit[i][j] = 0;
		}
	}
}

void bfs() {
	int i, j, zz, flag=0, read = 0, write = 0,max = 0;

	for (i = 0; i < 10; i++) {
		if (virus[i][2] == 1) {
			queue[write][0] = virus[i][0];
			queue[write++][1] = virus[i][1];
			visit[virus[i][0]][virus[i][1]]++;
		}
	}

	while (read != write) {
		int xx = queue[read][0];
		int yy = queue[read++][1];
		
		for (i = 0; i < 4; i++) {
			if (xx + dirx[i] < 0 || xx + dirx[i] >= n || yy + diry[i] < 0 || yy + diry[i] >= n) continue;
			
			if (map[xx + dirx[i]][yy + diry[i]] == 2 && visit[xx + dirx[i]][yy + diry[i]] == 0) {
				visit[xx + dirx[i]][yy + diry[i]]++;
				queue[write][0] = xx + dirx[i];
				queue[write++][1] = yy + diry[i];
				num[xx + dirx[i]][yy + diry[i]] = num[xx][yy] + 1;
			}

			if (map[xx + dirx[i]][yy + diry[i]] == 0 && visit[xx + dirx[i]][yy + diry[i]] == 0) {
				brk++;
				visit[xx + dirx[i]][yy + diry[i]]++;
				num[xx + dirx[i]][yy + diry[i]]= num[xx][yy]+1;
				queue[write][0] = xx + dirx[i];
				queue[write++][1] = yy + diry[i];
			}

			if (brk == total) {
				pin++;
				break;
			}
		}
		if (pin) break;
	}
	flag = check();
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (max < num[i][j]) max = num[i][j];
		}
	}

	if (min > max && flag == 1) min = max;

	clr();
	pin = brk = 0;
}

void dfs(int sta){
	int i;
	if (cnt == m) {
		bfs();
		return;
	}
	for (i = sta; i < idx;i++) {
		if (virus[i][2] == 0) {
			virus[i][2] = 1;
			cnt++;
			dfs(i);
			virus[i][2] = 0;
			cnt--;
		}
	}
}
int main() {
	int i, j;
	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) total++;
			if (map[i][j] == 2) {
				virus[idx][0] = i;
				virus[idx++][1] = j;
			}
		}
	}

	for (i = 0; i < idx; i++) {
		dfs(i);
		cnt = 0;
	}
	if (min == 100000000) printf("-1");
	else printf("%d", min);

}