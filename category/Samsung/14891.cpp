/*
problem : https://www.acmicpc.net/problem/14891
solution :
	Bitmasking Ȱ��
	������ ���� �� ���¿��� ȸ������ ���� Ȯ�� �� ���Ƽ� ȸ���ؾ���
	���� ȸ���ϸ� ����� �ٲ� ȸ������ ���ΰ� �ٲ� �� ����
	�Լ��� �ǵ��� �Ѱ��� ����� �ϵ��� �����ϴ� ���� ������ ����
	gr[4] - 0 ȸ������, 1 �ð����, -1 �ݽð���� ���� ������ ���� �迭
	������ �յ� Ȯ��, ���� ��ϰ� ȸ�� ���ϸ� �� ���� ��� ȸ�� ����
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