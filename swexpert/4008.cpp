#include <cstdio>
#include <cstring>
int k, ans;
int a[4], r[4], cmd[20][2];
void _init() {
	ans = 0;
	memset(a, 0, sizeof(a));
	memset(r, 0, sizeof(r));
	memset(cmd, 0, sizeof(cmd));
}
void input() {
	int x, n, dir;
	scanf("%d", &k);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%d", &x);
			if (x) a[i] |= (x << (7 - j));
		}
	}
	for (int i = 0; i < k; i++) {
		scanf("%d%d", &n, &dir);
		n--;
		cmd[i][0] = n, cmd[i][1] = dir;
	}
}
int pow(int p) {
	int ret = 1;
	for (int i = 0; i < p; i++) ret *= 2;
	return ret;
}
void rotate() {
	for (int i = 0; i < 4; i++) {
		if (r[i] == 1) {
			int z_bit = a[i] & (1 << 0) ? 1 : 0;
			a[i] >>= 1;
			if (z_bit) a[i] |= (1 << 7);
		}
		else if (r[i] == -1) {
			int s_bit = a[i] & (1 << 7) ? 1 : 0;
			a[i] <<= 1;
			if (s_bit) {
				a[i] |= (1 << 0);
				a[i] &= ~(1 << 8);
			}
		}
	}
}
void solve() {
	for (int i = 0; i < k; i++) {
		memset(r, 0, sizeof(r));
		r[cmd[i][0]] = cmd[i][1];
		int prev_b = a[cmd[i][0]] & (1 << 1) ? 1 : 0;
		for (int j = cmd[i][0] - 1; j >= 0; j--) {
			int next = a[j] & (1 << 5) ? 1 : 0;
			if (prev_b^next) {
				r[j] = -r[j + 1];
				prev_b = a[j] & (1 << 1) ? 1 : 0;
			}
			else break;
		}
		int prev_f = a[cmd[i][0]] & (1 << 5) ? 1 : 0;
		for (int j = cmd[i][0] + 1; j <= 3; j++) {
			int next = a[j] & (1 << 1) ? 1 : 0;
			if (prev_f^next) {
				r[j] = -r[j - 1];
				prev_f = a[j] & (1 << 5) ? 1 : 0;
			}
			else break;
		}
		rotate();
	}
	for (int i = 0; i < 4; i++) {
		if (a[i] & (1 << 7)) ans += pow(i);
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