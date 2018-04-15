#include <cstdio>
#include <cstring>
#define MAX 100
int n, m, k;
int ans;
int a[MAX][MAX], d[MAX][MAX];
int dy[5] = { 0,-1,1,0,0 };
int dx[5] = { 0,0,0,-1,1 };
void _init() {
	ans = 0;
	memset(a, 0, sizeof(a));
	memset(d, 0, sizeof(d));
}
void input() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		int y, x, c, dir;
		scanf("%d%d%d%d", &y, &x, &c, &dir);
		a[y][x] = c;
		d[y][x] = dir;
	}
}
void solve() {
	for (int t = 0; t < m; t++) {
		int mm[MAX][MAX] = { { 0 } };
		int aa[MAX][MAX] = { { 0 } };
		int dd[MAX][MAX] = { { 0 } };
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j]) {
					int ny = i + dy[d[i][j]];
					int nx = j + dx[d[i][j]];
					if (aa[ny][nx]) {
						aa[ny][nx] += a[i][j];
						if (mm[ny][nx] < a[i][j]) {
							mm[ny][nx] = a[i][j];
							dd[ny][nx] = d[i][j];
						}
					}
					else {
						if (ny == 0 || ny == n - 1 || nx == 0 || nx == n - 1) {
							aa[ny][nx] = a[i][j] / 2;
							dd[ny][nx] = (d[i][j] == 1 || d[i][j] == 3) ? d[i][j] + 1 : d[i][j] - 1;
						}
						else {
							aa[ny][nx] = a[i][j];
							dd[ny][nx] = d[i][j];
							mm[ny][nx] = mm[ny][nx] < a[i][j] ? a[i][j] : mm[ny][nx];
						}
					}
				}
			}
		}
		memcpy(a, aa, sizeof(aa));
		memcpy(d, dd, sizeof(dd));
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) ans += a[i][j];
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
	return 0;
}