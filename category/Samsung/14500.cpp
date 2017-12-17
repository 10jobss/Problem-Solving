/*
problem : https://www.acmicpc.net/problem/14500
solution :
	�׳� �������� �Ϸ� ������ ȸ��, ��Ī�� �־� ��ٷӴٰ� ����
	DFS Ž���� ���� 4ĭ���� Ž��
	�ߺ����� �ʰ� �Ѻױ׸���? �������� ���� ��� �ذ�
	��,��,��,�� �� �Ѻױ׸��� �Ұ����ϱ� ������ �׳� ����
	���߿� �׳� ������ ������ ����
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int N, M, ans, a[500][500];
bool chk[500][500];
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
void dfs(int y, int x, int l, int ret) {
	chk[y][x] = true;
	if (l == 4) {
		ans = max(ans, ret);
		chk[y][x] = 0;
		return;
	}
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (0 <= ny && ny < N && 0 <= nx && nx < M && !chk[ny][nx])
			dfs(ny, nx, l + 1, ret + a[ny][nx]);
	}
	chk[y][x] = 0;
	return;
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) scanf("%d", &a[i][j]);
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) dfs(i, j, 1, a[i][j]);
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (j - 1 >= 0 && j + 1 < M && i - 1 >= 0) {
				ans = max(ans, a[i][j] + a[i][j - 1] + a[i][j + 1] + a[i - 1][j]);
			}
			if (j - 1 >= 0 && j + 1 < M && i + 1 < N) {
				ans = max(ans, a[i][j] + a[i][j - 1] + a[i][j + 1] + a[i + 1][j]);
			}
			if (j - 1 >= 0 && i - 1 >= 0 && i + 1 < N) {
				ans = max(ans, a[i][j] + a[i][j - 1] + a[i - 1][j] + a[i + 1][j]);
			}
			if (j + 1 < M && i - 1 >= 0 && i + 1 < N) {
				ans = max(ans, a[i][j] + a[i][j + 1] + a[i - 1][j] + a[i + 1][j]);
			}
		}
	}
	printf("%d", ans);
	return 0;
}