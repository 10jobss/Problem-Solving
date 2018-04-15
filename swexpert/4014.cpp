#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, x, a[20][20], ans;
bool chk[20][20];
void _init() {
	memset(a, 0, sizeof(a));
	memset(chk, 0, sizeof(chk));
	ans = 0;
}
void input() {
	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
	}
}
void rr() {
	for (int i = 0; i < n; i++) {
		bool flag = true;
		for (int j = 0; j < n - 1; j++) {
			if (a[i][j] == a[i][j + 1]) continue;
			if (abs(a[i][j] - a[i][j + 1]) == 1) {
				if (a[i][j] > a[i][j + 1]) {
					int tmp = a[i][j + 1];
					for (int k = j + 1; k <= j + x; k++) {
						if (k >= n || chk[i][k]) { flag = false; break; }
						if (a[i][k] != tmp) { flag = false; break; }
					}
					if (!flag) continue;
					for (int k = j + 1; k <= j + x; k++) {
						chk[i][k] = 1;
					}
				}
				else {
					int tmp = a[i][j];
					for (int k = j; k >= j - x + 1; k--) {
						if (k < 0 || chk[i][k]) { flag = false; break; }
						if (a[i][k] != tmp) { flag = false; break; }
					}
					if (!flag) continue;
					for (int k = j; k >= j - x + 1; k--) {
						chk[i][k] = 1;
					}
				}
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag) ans++;
	}
}
void cc() {
	memset(chk, 0, sizeof(chk));
	for (int j = 0; j < n; j++) {
		bool flag = true;
		for (int i = 0; i < n - 1; i++) {
			if (a[i][j] == a[i + 1][j]) continue;
			if (abs(a[i][j] - a[i + 1][j]) == 1) {
				if (a[i][j] > a[i + 1][j]) {
					int tmp = a[i + 1][j];
					for (int k = i + 1; k <= i + x; k++) {
						if (k >= n || chk[k][j]) { flag = false; break; }
						if (a[k][j] != tmp) { flag = false; break; }
					}
					if (!flag) continue;
					for (int k = i + 1; k <= i + x; k++) {
						chk[k][j] = 1;
					}
				}
				else {
					int tmp = a[i][j];
					for (int k = i; k >= i - x + 1; k--) {
						if (k < 0 || chk[k][j]) { flag = false; break; }
						if (a[k][j] != tmp) { flag = false; break; }
					}
					if (!flag) continue;
					for (int k = i; k >= i - x + 1; k--) {
						chk[k][j] = 1;
					}
				}
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag) ans++;
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
		rr();
		cc();
		printf("#%d %d\n", t, ans);
	}
	return 0;
}