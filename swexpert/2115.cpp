#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, c, ans;
int a[100], d[100];
bool chk[100];
void input() {
	scanf("%d%d%d", &n, &m, &c);
	for (int i = 0; i < n*n; i++) {
		scanf("%d", &a[i]);
	}
}
void _init() {
	ans = 0;
	memset(chk, 0, sizeof(chk));
	memset(d, -1, sizeof(d));
}
void solve() {
	for (int i = 0; i < n*n; i++) {
		int hi = i + m - 1;
		if (hi >= n*n) continue;
		if (i / n != hi / n) continue;
		int sum = 0;
		for (int j = i; j <= hi; j++) {
			sum += a[j];
		}
		if (sum <= c) {
			d[i] = 0;
			for (int j = i; j <= hi; j++) d[i] += a[j] * a[j];
		}
		else {
			int tmp = 0;
			for (int j = 1; j < (1 << m); j++) {
				int ss = 0, sss = 0;
				for (int k = 0; k < m; k++) {
					if (j&(1 << k)) ss += a[i + k];
				}
				if (ss > c) continue;
				for (int k = 0; k < m; k++) {
					if (j&(1 << k)) sss += a[i + k] * a[i + k];
				}
				tmp = max(tmp, sss);
			}
			d[i] = tmp;
		}
	}
	int mxx = 0;
	int x = 0, y = 0;
	for (int i = 0; i < n*n; i++) {
		if (d[i] != -1) {
			if (x < d[i]) {
				x = d[i];
				mxx = i;
			}
		}
	}
	for (int i = mxx; i <= mxx + m - 1; i++) chk[i] = 1;
	for (int i = 0; i < n*n; i++) {
		if (d[i] != -1 && !chk[i] && !chk[i + m - 1]) {
			if (y < d[i]) y = d[i];
		}
	}
	ans = x + y;
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