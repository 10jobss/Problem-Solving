/*
problem : https://www.acmicpc.net/problem/10971
solution :
	N�� 10�̶� �׳� ����Ž������ Ǯ��
	l == n �� �� ������ ���� ������� ������¸� Ȯ���ؾ����� (�׷��� �ʾƼ� ó���� WA)
	�̷� ���� ����Լ����� chk�� �����ϴ� ���� �ѹ��� �ص� �������
	������ bitmasking�� Ȱ���� �ٸ� Ǯ�̵� Ȯ���غ� ��
*/
#include <cstdio>
#include <cstring>
#define INF 987654321
int n, ans = INF, w[10][10];
bool chk[10];
void dfs(int s, int v, int c, int l) {
	chk[v] = 1;
	if (l == n) {
		chk[v] = 0;
		if (!w[v][s]) return;
		ans = ans > c + w[v][s] ? c + w[v][s] : ans;
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (i == v || !w[v][i] || chk[i]) continue;
		dfs(s, i, c + w[v][i], l + 1);
	}
	chk[v] = 0;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) scanf("%d", &w[i][j]);
	}
	for (int i = 0; i < n; ++i) {
		memset(chk, 0, sizeof(chk));
		dfs(i, i, 0, 1);
	}
	printf("%d", ans);
	return 0;
}