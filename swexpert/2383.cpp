#include <cstdio>
#include <algorithm>
#define INF 987654321
using namespace std;
int n, ans;
int ppos, spos;
int a[10][10];
int p[10], s[2];
void _init() {
	ans = INF;
	spos = ppos = 0;
}
void input() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] >= 2) {
				s[spos++] = i * 10 + j;
			}
			else if (a[i][j] == 1) {
				p[ppos++] = i * 10 + j;
			}
		}
	}
}
void solve() {
	for (int st = 0; st < (1 << ppos); st++) {
		int as[10] = { 0 }, bs[10] = { 0 };
		int apos = 0, bpos = 0;
		for (int bt = 0; bt < ppos; bt++) {
			if (st&(1 << bt)) as[apos++] = abs(s[0] / 10 - p[bt] / 10) + abs(s[0] % 10 - p[bt] % 10);
			else bs[bpos++] = abs(s[1] / 10 - p[bt] / 10) + abs(s[1] % 10 - p[bt] % 10);
		}
		sort(as, as + apos);
		sort(bs, bs + bpos);
		int af[10] = { 0 }, bf[10] = { 0 };
		for (int i = 0; i < apos; i++) {
			if (i < 3) af[i] = as[i] + 1 + a[s[0] / 10][s[0] % 10];
			else {
				if (as[i] >= af[i - 3]) af[i] = as[i] + 1 + a[s[0] / 10][s[0] % 10];
				else af[i] = af[i - 3] + a[s[0] / 10][s[0] % 10];
			}
		}
		for (int i = 0; i < bpos; i++) {
			if (i < 3) bf[i] = bs[i] + 1 + a[s[1] / 10][s[1] % 10];
			else {
				if (bs[i] >= bf[i - 3]) bf[i] = bs[i] + 1 + a[s[1] / 10][s[1] % 10];
				else bf[i] = bf[i - 3] + a[s[1] / 10][s[1] % 10];
			}
		}
		if (apos > 0 && bpos > 0) ans = min(ans, max(af[apos - 1], bf[bpos - 1]));
		else if (apos > 0) ans = min(ans, af[apos - 1]);
		else if (bpos > 0) ans = min(ans, bf[bpos - 1]);
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