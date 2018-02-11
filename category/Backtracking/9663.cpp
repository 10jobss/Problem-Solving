/*
problem : https://www.acmicpc.net/problem/9663
solution :
	Recursive�� �̿��ؼ� ������ ��츸 Ž��
	�ָԱ��������� ��������
	N*N�� N���� queen�� ��ġ���ϴµ� queen�� �����ִ� ��ǥ�� ����, ����, ���� �� ���� �밢���� �ٸ� queen�� ��ġ ����
	'�� �࿡�� �� 1���� queen�� ��ġ' <-- �� ������ ����Ʈ (�����ص� �������)
	(y,x)�� queen�� ��ġ�ϰ� ������ �� �ִ� ��� ��ǥ�� check
	�� �� bool�� �ϸ� �ش� �ܰ迡�� check�� ��ǥ �̿ܿ� �߰��� �� ������ �� �־
	k��° ���� �ξ��� �� check�� �� ���� ǥ���ϱ� ���� int �迭�� �ٲ� (!!)
	cmd = 0 �� �� set, cmd = 1 �� �� reset
	��ǥ���� ���� �밢��, ���� �밢�� ��ǥ �򰥸��� ����� ������ ��
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