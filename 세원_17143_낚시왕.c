#include<stdio.h>
#include<stdlib.h>
int R, C, M, sol;
struct shark {
    int r; //행
    int c; //열
    int s; //속력
    int d; //이동방향
    int z; //크기
    int isdied; //생사 여부
}sharks[10100];
int map[101][101];
int personL = 0;
int dir[2] = { -1, 1 };

void checkSharks() {
    for (int current = 1; current <= M; current++) {
        if (map[sharks[current].r][sharks[current].c] != 0) {
            int prev = map[sharks[current].r][sharks[current].c];
            if (sharks[current].isdied == 0 && sharks[prev].isdied == 0) {
                if (sharks[current].z > sharks[prev].z) {
                    sharks[prev].isdied = 1;
                    sharks[prev].r = 0;
                    sharks[prev].c = 0;
                    sharks[prev].s = 0;
                    sharks[prev].d = 0;
                    sharks[prev].z = 0;
                    map[sharks[current].r][sharks[current].c] = current;
                }
                else {
                    sharks[current].isdied = 1;
                    sharks[current].r = 0;
                    sharks[current].c = 0;
                    sharks[current].s = 0;
                    sharks[current].d = 0;
                    sharks[current].z = 0;
                }
            }
        }
        else map[sharks[current].r][sharks[current].c] = current;
    }
}

void catchSharks() {
    for (int i = 1; i <= M; i++) {
        if (sharks[i].isdied == 0 && sharks[i].c == personL) {
            sharks[i].isdied = 1;
            sol += sharks[i].z;
            sharks[i].r = 0;
            sharks[i].c = 0;
            sharks[i].s = 0;
            sharks[i].d = 0;
            sharks[i].z = 0;
            break;
        }
    }
}

void moveSharks() {
    for (int i = 1; i <= M; i++) {
        if (sharks[i].s == 0 || sharks[i].isdied != 0) continue;
        if (sharks[i].d == 1 || sharks[i].d == 2) {
            for (int j = 0; j < sharks[i].s; j++) {
                sharks[i].r += dir[sharks[i].d - 1];
                if (sharks[i].r == R + 1) {
                    sharks[i].r = R - 1;
                    sharks[i].d = 1;
                }
                else if (sharks[i].r == 0) {
                    sharks[i].r = 2;
                    sharks[i].d = 2;
                }
            }
        }
        else {
            for (int j = 0; j < sharks[i].s; j++) {
                sharks[i].c -= dir[sharks[i].d - 3];
                if (sharks[i].c == C + 1) {
                    sharks[i].c = C - 1;
                    sharks[i].d = 4;
                }
                else if (sharks[i].c == 0) {
                    sharks[i].c = 2;
                    sharks[i].d = 3;
                }
            }
        }
    }

}

int compare(const void* a, const void* b) {
    struct shark* x = (struct shark*)a;
    struct shark* y = (struct shark*)b;
    if (x->c == y->c) {
        return x->r - y->r;
    }
    return x->c - y->c;
}
int main() {

    scanf("%d %d %d", &R, &C, &M);
    for (int i = 1; i <= M; i++) {
        scanf("%d %d %d %d %d", &sharks[i].r, &sharks[i].c, &sharks[i].s, &sharks[i].d, &sharks[i].z);
        sharks[i].s = sharks[i].d < 3 ? sharks[i].s % (2 * R - 2) : sharks[i].s % (2 * C - 2);
    }
    if (M > 0) {
        while (personL < C) {
            personL++;
            qsort(sharks, M + 1, sizeof(struct shark), compare);
            catchSharks();
            moveSharks();
            checkSharks();
            for (int i = 1; i <= M; i++) {
                map[sharks[i].r][sharks[i].c] = 0;
            }
        }
    }

    printf("%d", sol);
    return 0;
}
