#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
int n, m, v, k, mod;
int c[(int)2e6 + 1], mp[(int)2e6 + 1];
int main() {
	scanf("%d%d%d", &n, &m, &v);
	for (int i = 1; i <= n; i++)
		scanf("%d", c + i);
	mod = n - v + 1;
	for (int i = v; i <= n; i++)
		mp[(i - 1) % mod] = i;
	while (m--) {
		scanf("%d", &k);
		if (k + 1 < v) printf("%d\n", c[k + 1]);
		else printf("%d\n", c[mp[k % mod]]);
	}
	return 0;
}
