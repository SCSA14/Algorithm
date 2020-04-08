#include <stdio.h>
int N, M, cctvNum, min = 99999;
int office[10][10];
int tmp[8][10][10];
int visitD[10][4];
int cctvXY[10][2];
int dirx[5] = { 0, 1, -1, 0, 0 }; // �Ʒ� �� ������ ����
int diry[5] = { 0, 0, 0, 1, -1 }; // 0    1   2    3 // k
int check() { //�簢����(0) ����
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (office[i][j] == 0) cnt++;
		}
	}
	return cnt;
}
void setCCTV(int idx, int k) { //����Ƽ��� Ȯ�� ������ ���� -1�� ��ĥ
	int newx = cctvXY[idx][0];
	int newy = cctvXY[idx][1];
	while (1) {
		newx += dirx[k];
		newy += diry[k];
		if (newx < 0 || newx >= N || newy < 0 || newy >= M) break;
		if (office[newx][newy] == 0) office[newx][newy] = -1;
		else if (office[newx][newy] == 6) break;
	}
}
void setDir(int idx, int cnt) { //�� ����Ƽ���� ���� ����, ��Ʈ��ŷ�� �̿��� �ٽ� �ʱ�ȭ �� �ٸ� �������� ����. 
	if (cnt == cctvNum) {
		int result = check();
		if (min > result) min = result;
		return;
	}
	if (idx >= cctvNum) return;
	int k = office[cctvXY[idx][0]][cctvXY[idx][1]];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tmp[cnt][i][j] = office[i][j];
		}
	}
	if (k == 1) {
		setCCTV(idx, 1);
		setDir(idx + 1, cnt + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				office[i][j] = tmp[cnt][i][j];
			}
		}
		setCCTV(idx, 2);
		setDir(idx + 1, cnt + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				office[i][j] = tmp[cnt][i][j];
			}
		}
		setCCTV(idx, 3);
		setDir(idx + 1, cnt + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				office[i][j] = tmp[cnt][i][j];
			}
		}
		setCCTV(idx, 4);
		setDir(idx + 1, cnt + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				office[i][j] = tmp[cnt][i][j];
			}
		}
	}
	else if (k == 2) {
		setCCTV(idx, 1);
		setCCTV(idx, 2);
		setDir(idx + 1, cnt + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				office[i][j] = tmp[cnt][i][j];
			}
		}
		
		setCCTV(idx, 3);
		setCCTV(idx, 4);
		setDir(idx + 1, cnt + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				office[i][j] = tmp[cnt][i][j];
			}
		}
	}
	else if (k == 3) {
		setCCTV(idx, 1); // �Ʒ� ����
		setCCTV(idx, 4);
		setDir(idx + 1, cnt + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				office[i][j] = tmp[cnt][i][j];
			}
		}

		setCCTV(idx, 2); // �� ������
		setCCTV(idx, 3);
		setDir(idx + 1, cnt + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				office[i][j] = tmp[cnt][i][j];
			}
		}

		setCCTV(idx, 3); // ������ �Ʒ�
		setCCTV(idx, 1);
		setDir(idx + 1, cnt + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				office[i][j] = tmp[cnt][i][j];
			}
		}
		setCCTV(idx, 4); // ���� ��
		setCCTV(idx, 2);
		setDir(idx + 1, cnt + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				office[i][j] = tmp[cnt][i][j];
			}
		}
	}
	else if (k == 4) {
		setCCTV(idx, 1); // �Ʒ� ���� ������
		setCCTV(idx, 4);
		setCCTV(idx, 3);
		setDir(idx + 1, cnt + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				office[i][j] = tmp[cnt][i][j];
			}
		}

		setCCTV(idx, 2); // �� ������ ����
		setCCTV(idx, 3);
		setCCTV(idx, 4);
		setDir(idx + 1, cnt + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				office[i][j] = tmp[cnt][i][j];
			}
		}

		setCCTV(idx, 3); // ������ �Ʒ� ��
		setCCTV(idx, 1);
		setCCTV(idx, 2);
		setDir(idx + 1, cnt + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				office[i][j] = tmp[cnt][i][j];
			}
		}
		setCCTV(idx, 4); // ���� �� �Ʒ�
		setCCTV(idx, 2);
		setCCTV(idx, 1);
		setDir(idx + 1, cnt + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				office[i][j] = tmp[cnt][i][j];
			}
		}
	}
	else if (k == 5) {
		setCCTV(idx, 1);
		setCCTV(idx, 2);
		setCCTV(idx, 3);
		setCCTV(idx, 4);
		setDir(idx + 1, cnt + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				office[i][j] = tmp[cnt][i][j];
			}
		}
	}
	setDir(idx + 1, cnt);
}
int main() {
	int idx = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &office[i][j]);
			if (office[i][j] != 0 && office[i][j] != 6) {
				cctvXY[idx][0] = i;
				cctvXY[idx++][1] = j; //����Ƽ�� ��ǥ ���� ����
			}
		}
	}
	cctvNum = idx;
	setDir(0, 0);
	printf("%d", min);
	return 0;
}