#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int ans, n, m;
int a[20][20];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
void _init() {
	ans = 0;
	memset(a, 0, sizeof(a));
}
void input() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
	}
}
void solve() {
	for (int k = 1; k <2 * n; k++) {
		int c = k*k + (k - 1)*(k - 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int cnt = 0;
				for (int ii = 0; ii < n; ii++) {
					for (int jj = 0; jj < n; jj++) {
						if (a[ii][jj] && abs(i - ii) + abs(j - jj) < k) cnt++;
					}
				}
				if (cnt*m >= c) ans = max(ans, cnt);
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
		_init();
		input();
		solve();
		printf("#%d %d\n", t, ans);
	}
	return 0;
}