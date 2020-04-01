#include <stdio.h>
int n, k, l, flag, sec;
int d = 0;
int dirx[4] = { 0,1,0,-1 };
int diry[4] = { 1,0,-1,0 };

int apple[101];
int map[101][101];
int direct[10001];
int queue[1010000][2];

void bfs() {
    int i, j, read = 0, write = 0, re, mov, idx = 0;

    map[1][1] = 1;
    queue[write][0] = 1;
    queue[write++][1] = 1;
    while (read != write) {
        re = queue[read - idx][0];
        mov = queue[read - idx][1];
        int xx = queue[read][0];
        int yy = queue[read++][1];

        if (direct[sec] == 3) {
            if (d == 0) d = 3;
            else d -= 1;
        }
        else if (direct[sec] == 4) {
            if (d == 3) d = 0;
            else d += 1;
        }
        
        if (xx + dirx[d] == 0 || yy + diry[d] == 0 || xx + dirx[d] > n || yy + diry[d] > n) {
            sec++;
            return;
        }

        if (map[xx + dirx[d]][yy + diry[d]] == 1) {
            sec++;
            return;
        }

        if (map[xx + dirx[d]][yy + diry[d]] == 0) {
            map[xx + dirx[d]][yy + diry[d]] = 1;
            queue[write][0] = xx + dirx[d];
            queue[write++][1] = yy + diry[d];
            map[re][mov] = 0;
        }
        if (map[xx + dirx[d]][yy + diry[d]] == 5) {
            map[xx + dirx[d]][yy + diry[d]] = 1;
            queue[write][0] = xx + dirx[d];
            queue[write++][1] = yy + diry[d];
            idx++;
        }
        sec++;
    }
}

int main() {
    int i, j, a, b;
    char c;
    scanf("%d", &n);
    scanf("%d", &k);
    for (i = 0; i < k; i++) {
        scanf("%d %d", &a, &b);
        map[a][b] = 5;
    }
    scanf("%d", &l);
    for (i = 0; i < l; i++) {
        scanf("%d %c", &a, &c);
        if (c == 'D') direct[a] = 4;
        else direct[a] = 3;
    }
    
    bfs();
    
    printf("%d\n", sec);

}
