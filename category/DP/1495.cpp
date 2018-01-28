#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, s, m, ans = -1, v[100], cache[100][1001];
int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d%d%d", &n, &s, &m);
	for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
	if (s + v[0] <= m) cache[0][s + v[0]] = 1;
	if (s - v[0] >= 0) cache[0][s - v[0]] = 1;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (cache[i - 1][j] != -1) {
				if (j + v[i] <= m) cache[i][j + v[i]] = 1;
				if (j - v[i] >= 0) cache[i][j - v[i]] = 1;
			}
		}
	}
	for (int j = 0; j <= m; ++j) {
		if (cache[n - 1][j] == 1) ans = max(ans, j);
	}
	printf("%d", ans);
	return 0;
}