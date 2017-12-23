/*
problem : https://www.acmicpc.net/problem/3085
solution :
	i�� j���� ���Ͽ� ������, �Ʒ� ���� Ȯ�� �� ���� ������ ��� skip, �ٸ� ������ ��� swap �� solve
	���� �� ���� Ȯ�� (��, �ະ��)
	call by reference!!
*/
#include <cstdio>
int n, ans;
char adj[51][51];
void swap(char &x, char &y) {
	char tmp;
	tmp = x;
	x = y;
	y = tmp;
}
void solve() {
	int tmp = 0;
	for (int i = 1; i <= n; ++i) {
		int cnt = 1;
		for (int j = 1; j <= n - 1; ++j) {
			if (adj[i][j] == adj[i][j + 1]) cnt++;
			else cnt = 1;
			tmp = tmp < cnt ? cnt : tmp;
		}
		ans = ans < tmp ? tmp : ans;
	}
	for (int i = 1; i <= n; ++i) {
		int cnt = 1;
		for (int j = 1; j <= n - 1; ++j) {
			if (adj[j][i] == adj[j + 1][i]) cnt++;
			else cnt = 1;
			tmp = tmp < cnt ? cnt : tmp;
		}
		ans = ans < tmp ? tmp : ans;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf(" %c", &adj[i][j]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i + 1 <= n && j <= n) {
				if (adj[i][j] == adj[i + 1][j]) continue;
				swap(adj[i][j], adj[i + 1][j]);
				solve();
				swap(adj[i][j], adj[i + 1][j]);
			}
			if (i <= n &&j + 1 <= n) {
				if (adj[i][j] == adj[i][j + 1]) continue;
				swap(adj[i][j], adj[i][j + 1]);
				solve();
				swap(adj[i][j], adj[i][j + 1]);
			}
		}
	}
	printf("%d", ans);
	return 0;
}