/*
problem : https://www.acmicpc.net/problem/9663
solution :
	Recursive를 이용해서 가능한 경우만 탐색
	주먹구구식으로 구현했음
	N*N에 N개의 queen을 배치야하는데 queen이 놓여있는 좌표의 가로, 세로, 증가 및 감소 대각선에 다른 queen을 배치 못함
	'각 행에는 단 1개의 queen만 배치' <-- 이 생각이 포인트 (열로해도 상관없음)
	(y,x)에 queen을 배치하고 공격할 수 있는 모든 좌표를 check
	이 때 bool로 하면 reset 시 해당 단계에서 check한 좌표 이외에 전 단계의 좌표도 추가로 더  reset 할 수 있어서
	k번째 말을 두었을 때 check한 걸 따로 표시하기 위해 int 배열로 바꿈 (!!)
	cmd = 0 일 때 set, cmd = 1 일 때 reset
	좌표에서 증가 대각선, 감소 대각선 좌표 헷갈리기 쉬우니 주의할 것
*/
#include <cstdio>
#include <cstring>
int n, ans, chk[15][15];
void paint(int y, int x, int cmd) {
	int i, j;
	switch (cmd) {
	case 0:
		for (i = 1; i <= n; i++) {
			if (chk[y][i] == -1) chk[y][i] = y;
			if (chk[i][x] == -1) chk[i][x] = y;
		}
		for (i = y, j = x; i <= n && j <= n; i++, j++) {
			if (chk[i][j] == -1) chk[i][j] = y;
		}
		for (i = y, j = x; i >= 1 && j >= 1; i--, j--) {
			if (chk[i][j] == -1) chk[i][j] = y;
		}
		for (i = y, j = x; i >= 1 && j <= n; i--, j++) {
			if (chk[i][j] == -1) chk[i][j] = y;
		}
		for (i = y, j = x; i <= n && j >= 1; i++, j--) {
			if (chk[i][j] == -1) chk[i][j] = y;
		}
		break;
	case 1:
		for (i = 1; i <= n; i++) {
			if (chk[y][i] == y) chk[y][i] = -1;
			if (chk[i][x] == y) chk[i][x] = -1;
		}
		for (i = y, j = x; i <= n && j <= n; i++, j++) {
			if (chk[i][j] == y) chk[i][j] = -1;
		}
		for (i = y, j = x; i >= 1 && j >= 1; i--, j--) {
			if (chk[i][j] == y) chk[i][j] = -1;
		}
		for (i = y, j = x; i >= 1 && j <= n; i--, j++) {
			if (chk[i][j] == y) chk[i][j] = -1;
		}
		for (i = y, j = x; i <= n && j >= 1; i++, j--) {
			if (chk[i][j] == y) chk[i][j] = -1;
		}
	}
}
void f(int k) {
	if (k == n) {
		for (int i = 1; i <= n; i++) {
			if (chk[k][i]==-1) ans++;
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (chk[k][i]==-1) {
			paint(k, i, 0);
			f(k + 1);
			paint(k, i, 1);
		}
	}
}
int main() {
	memset(chk, -1, sizeof(chk));
	scanf("%d", &n);
	f(1);
	printf("%d", ans);
	return 0;
}
