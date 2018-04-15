#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int ans, n;
int a[20][20];
bool d[101];
int dy[4] = { 1,1,-1,-1 };
int dx[4] = { 1,-1,-1,1 };
inline bool bnd(int y, int x) { return y >= 0 && y < n&&x >= 0 && x < n; }
void input() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
	}
}
void dfs(int y, int x, int sy, int sx, int dir, int cnt) {
	if (dir == 3 && y == sy && x == sx) {
		ans = max(ans, cnt - 1);
		return;
	}
	if (d[a[y][x]]) return;
	d[a[y][x]] = 1;
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	if (bnd(ny, nx)) dfs(ny, nx, sy, sx, dir, cnt + 1);
	if (dir != 3) {
		int yy = y + dy[dir + 1];
		int xx = x + dx[dir + 1];
		if (bnd(yy, xx)) {
			dfs(yy, xx, sy, sx, dir + 1, cnt + 1);
		}
	}
	d[a[y][x]] = 0;
}
void solve() {
	for (int i = 0; i < n - 2; i++) {
		for (int j = 1; j < n - 1; j++) {
			memset(d, 0, sizeof(d));
			if (i + 1 < n&&j + 1 < n&&a[i][j] != a[i + 1][j + 1]) {
				dfs(i, j, i, j, 0, 1);
			}
		}
	}
}
int main() {
	//setbuf(stdin, NULL);
	//freopen("sample_input.txt", "r", stdin);
	int tc;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		ans = -1;
		input();
		solve();
		printf("#%d %d\n", t, ans<4 ? -1 : ans);
	}
	return 0;
}