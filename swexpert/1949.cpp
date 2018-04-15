#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, k, ans;
int a[8][8];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
void _init() {
	ans = 0;
	memset(a, 0, sizeof(a));
}
void input() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
}
int findMx() {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ret = max(ret, a[i][j]);
		}
	}
	return ret;
}
int dfs(int y, int x) {
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (a[y][x] <= a[ny][nx]) continue;
		ret = max(ret, dfs(ny, nx) + 1);
	}
	return ret;
}
void solve() {
	int smx = findMx();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == smx) ans = max(ans, dfs(i, j));
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp = a[i][j];
			for (int h = 1; h <= k; h++) {
				a[i][j] -= h;
				a[i][j] = a[i][j] < 0 ? 0 : a[i][j];
				for (int ii = 0; ii < n; ii++) {
					for (int jj = 0; jj < n; jj++) {
						if (a[ii][jj] == smx) ans = max(ans, dfs(ii, jj));
					}
				}
				a[i][j] = tmp;
			}
			a[i][j] = tmp;
		}
	}
}
int main() {
	//setbuf(stdin, NULL);
	//freopen("sample_input.txt", "r", stdin);
	int tc;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		_init();
		input();
		solve();
		printf("#%d %d\n", t, ans);
	}
}