/*
problem : https://www.acmicpc.net/problem/1937
solution :
	DFS + Top-down DP
	d[y][x] = y�� x������ ������� �� �̵��� �� �ִ� ���� ��� ����
	dfs�Լ� if���� ó���� ret += dfs(ny,nx)�� �ߴµ� �������� ������
	�������� �ƴ� �ִ밪�̱� ������ tmp������ �� ����� ���̸� ���ϰ� �� �� �ִ밪�� dp�迭�� ����
	�� ��ĺ��� �� ����ϰ� ������ �� ����. * �ٸ���� �ڵ� ����
*/
#include <cstdio>
#include <cstring>
int n, ans = 1, a[500][500], d[500][500];
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
int dfs(int y, int x) {
	int &ret = d[y][x];
	if (ret != -1) return ret;
	ret = 1;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		int tmp = 1;
		if (0 <= ny && ny < n && 0 <= nx && nx < n && a[ny][nx] > a[y][x]) {
			tmp += dfs(ny, nx);
			ret = ret > tmp ? ret : tmp;
		}
	}
	ans = ans > ret ? ans : ret;
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) scanf("%d", &a[i][j]);
	}
	memset(d, -1, sizeof(d));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dfs(i, j);
		}
	}
	printf("%d", ans);
	return 0;
}