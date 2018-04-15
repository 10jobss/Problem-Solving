#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 987654321
#define NINF -123456789
using namespace std;
int n, a[12], op[4], mx, mn;
void _init() {
	mx = NINF, mn = INF;
	memset(op, 0, sizeof(op));
}
void input() {
	scanf("%d", &n);
	for (int i = 0; i < 4; i++) scanf("%d", &op[i]);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}
void solve(int k, int p, int m, int mt, int div, int res) {
	if (k == n - 1) {
		mx = max(mx, res);
		mn = min(mn, res);
		return;
	}
	if (p) solve(k + 1, p - 1, m, mt, div, res + a[k + 1]);
	if (m) solve(k + 1, p, m - 1, mt, div, res - a[k + 1]);
	if (mt) solve(k + 1, p, m, mt - 1, div, res * a[k + 1]);
	if (div) {
		if (res > 0) solve(k + 1, p, m, mt, div - 1, res / a[k + 1]);
		else solve(k + 1, p, m, mt, div - 1, -(-res / a[k + 1]));
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
		solve(0, op[0], op[1], op[2], op[3], a[0]);
		printf("#%d %d\n", t, abs(mx - mn));
	}
	return 0;
}
