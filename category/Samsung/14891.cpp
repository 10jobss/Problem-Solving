/*
problem : https://www.acmicpc.net/problem/14891
solution :
	Bitmasking 활용
	주의할 점은 현 상태에서 회전가능 여부 확인 후 몰아서 회전해야함
	먼저 회전하면 모양이 바뀌어서 회전가능 여부가 바뀔 수 있음
	함수는 되도록 한가지 기능을 하도록 구현하는 것이 나은것 같음
	gr[4] - 0 회전안함, 1 시계방향, -1 반시계방향 상태 저장을 위한 배열
	기준점 앞뒤 확인, 인접 톱니가 회전 못하면 그 이후 톱니 회전 못함
*/
#include <cstdio>
#include <cstring>
int k, n, dir, ans, a[4], gr[4];
int pow(int x, int p) {
	int ret = 1;
	for (int i = 0; i < p; ++i) ret *= x;
	return ret;
}
bool chk(int cur, int prev) {
	int cr = a[cur] & (1 << 1) ? 1 : 0;
	int pr = a[prev] & (1 << 5) ? 1 : 0;
	return cr^pr;
}
void rotate(int g, int d) {
	if (d == 1) {
		int end = a[g] & (1 << 0) ? 1 : 0;
		a[g] >>= 1;
		if (end) a[g] |= (1 << 7);
	}
	else if (d == -1) {
		int start = a[g] & (1 << 7) ? 1 : 0;
		a[g] <<= 1;
		if (start) {
			a[g] |= (1 << 0);
			a[g] &= ~(1 << 8);
		}
	}
}
int main() {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 8; ++j) {
			scanf("%1d", &n);
			a[i] += n*pow(2, 7 - j);
		}
	}
	scanf("%d", &k);
	while (k--) {
		memset(gr, 0, sizeof(gr));
		scanf("%d%d", &n, &dir);
		gr[--n] = dir;
		for (int i = n; i > 0; --i) {
			if (chk(i, i - 1)) gr[i - 1] = -gr[i];
			else break;
		}
		for (int i = n; i < 3; ++i) {
			if (chk(i + 1, i)) gr[i + 1] = -gr[i];
			else break;
		}
		for (int i = 0; i < 4; ++i) {
			if (gr[i]) rotate(i, gr[i]);
		}
	}
	for (int i = 0; i < 4; ++i) {
		a[i] = a[i] & (1 << 7) ? 1 : 0;
		ans += a[i] * pow(2, i);
	}
	printf("%d", ans);
	return 0;
}