/*
problem : https://www.acmicpc.net/problem/9466
solution :
	Cycle 찾는 문제. 스타일 상 일단 DFS
	Cycle은 시작점의 위치는 중요하지 않음. 1,2,3,4 노드가 Cycle Component(CC)일 때 어느 점에서 시작하든 동일
	N = 10^5이므로 매 정점마다 초기화해서 다시 탐색하면 TLE
	즉, 한 번 탐색 시 각 정점이 CC에 속하는지 여부를 판단해야 함
	bcylce은 각 정점의 상태로
	0 : 초기 상태, 1 : 방문했으나 CC인지는 모름
	2 : 방문도 하고 CC 3 : 방문하고 CC 아님
	다음 정점이 초기 상태가 아니고 1 상태라면 f 호출(CC check) 후 return
	숫자가 작은 정점부터 강제로 호출하기 때문에 '잘못 생각한 부분'에 v>=a[v] 라고 해서 WA
	1 -> 7 -> 3 -> 7 인 경우 3이 7을 호출할 때 문제 생김
*/
#include <cstdio>
#include <cstring>
#define MAX (int)1e+5
int tc, n, ans, a[MAX], bcycle[MAX];
void f(int v) {
	bcycle[v] = 2;
	if (bcycle[a[v]] != 2) f(a[v]);
}
void dfs(int v) {
	bcycle[v] = 1;
	if (!bcycle[a[v]]) dfs(a[v]); // 잘못 생각한 부분
	else if (bcycle[a[v]] == 1) {
		f(a[v]);
		return;
	}
	if (bcycle[v] != 2) bcycle[v] = 3;
}
int main() {
	scanf("%d", &tc);
	while (tc--) {
		ans = 0;
		memset(bcycle, false, sizeof(bcycle));
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			a[i]--;
		}
		for (int i = 0; i < n; ++i) {
			if (!bcycle[i]) dfs(i);
		}
		for (int i = 0; i < n; ++i) {
			if (bcycle[i] != 2) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
