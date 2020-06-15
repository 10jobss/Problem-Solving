/*
problem : https://www.acmicpc.net/problem/1613
solution :
	단순 DFS로 해결
	Floyd-Warshall 공부 후 다시 풀기
*/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int n, k, s;
vector<int> a[401];
bool chk[401];
void dfs(int v) {
	chk[v] = true;
	for (int i = 0; i < a[v].size(); ++i) {
		if (!chk[a[v][i]]) dfs(a[v][i]);
	}
}
int main() {
	scanf("%d%d", &n, &k);
	while (k--) {
		int u, w;
		scanf("%d%d", &u, &w);
		a[u].push_back(w);
	}
	scanf("%d", &s);
	while (s--) {
		memset(chk, 0, sizeof(chk));
		int a, b;
		scanf("%d%d", &a, &b);
		dfs(a);
		if (chk[b]) {
			puts("-1");
			continue;
		}
		memset(chk, 0, sizeof(chk));
		dfs(b);
		if (chk[a]) {
			puts("1");
			continue;
		}
		puts("0");
	}
	return 0;
}