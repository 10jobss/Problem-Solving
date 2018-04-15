#include <cstdio>
#include <cstring>
int ans;
int p[4], a[12];
void _init() {
	memset(p, 0, sizeof(p));
	memset(a, 0, sizeof(a));
}
void input() {
	for (int i = 0; i < 4; i++) scanf("%d", &p[i]);
	for (int i = 0; i < 12; i++) scanf("%d", &a[i]);
	ans = p[3];
}
void solve(int pos, int sum) {
	if (pos >= 12) {
		ans = ans > sum ? sum : ans;
		return;
	}
	if (!a[pos]) solve(pos + 1, sum);
	solve(pos + 1, sum + a[pos] * p[0]);
	solve(pos + 1, sum + p[1]);
	solve(pos + 3, sum + p[2]);
}
int main() {
	//setbuf(stdin, NULL);
	//freopen("sample_input.txt", "r", stdin);
	int tc;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		_init();
		input();
		solve(0, 0);
		printf("#%d %d\n", t, ans);
	}
	return 0;
}