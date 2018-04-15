#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;
int n, ans;
int a[16][16];
bool chk[16];
void _init() {
	ans = INF;
	memset(a, 0, sizeof(a));
	memset(chk, 0, sizeof(chk));
}
void input() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
	}
}
void dfs(int k, int l) {
	chk[k] = 1;
	if (l == n / 2) {
		int A = 0, B = 0;
		for (int i = 0; i < n; i++) {
			if (chk[i]) {
				for (int j = 0; j < n; j++) {
					if (chk[j]) A += a[i][j];
				}
			}
			else {
				for (int j = 0; j < n; j++) {
					if (!chk[j]) B += a[i][j];
				}
			}
		}
		ans = min(ans, abs(A - B));
		chk[k] = 0;
		return;
	}
	for (int i = k + 1; i < n; i++) {
		if (!chk[i]) dfs(i, l + 1);
	}
	chk[k] = 0;
}
int main() {
	//setbuf(stdin, NULL);
	//freopen("sample_input.txt", "r", stdin);
	int tc;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		_init();
		input();
		dfs(0, 1);
		printf("#%d %d\n", t, ans);
	}
	return 0;
}