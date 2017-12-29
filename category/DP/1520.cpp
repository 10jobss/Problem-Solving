/*
problem : https://www.acmicpc.net/problem/1520
solution :
	Top-down DP
	�� �ٽ� Ǯ������� ���� (��)
	dp�迭 ä��� ���� �߿�...
	��ȭ�� �ǹ̿� ���� ȣ���ϴ� ����� �޶���
*/
#include <cstdio>
#include <cstring>
#define MAX 500
int m, n, a[MAX][MAX], d[MAX][MAX];
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
int f(int y, int x) {
	if (y == m - 1 && x == n - 1) {
		return 1;
	}
	if (d[y][x] != -1) return d[y][x];
	d[y][x] = 0;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (0 <= ny && ny < m && 0 <= nx && nx < n && a[y][x] > a[ny][nx]) {
			d[y][x] += f(ny, nx);
		}
	}
	return d[y][x];
}
int main() {
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) scanf("%d", &a[i][j]);
	}
	memset(d, -1, sizeof(d));
	printf("%d\n", f(0, 0));
	return 0;
}