/*
problem : https://www.acmicpc.net/problem/1495
solution :
	Bottom-up DP
	cache[i][j] = j볼륨으로 i번째 곡 연주 가능 여부 (-1 : 불가능, 1 : 가능)
	시간복잡도 O(N*M)으로 해결 가능
	처음에 풀땐 BFS로 풀이 node는 pair<볼륨, level>
	최악의 경우 n=100일 때 height 100의 트리가 2^100 - 1 개의 노드를 가질 수 있으므로
	메모리는 약 (2^100 - 1)*8byte 이므로 메모리초과
*/
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
