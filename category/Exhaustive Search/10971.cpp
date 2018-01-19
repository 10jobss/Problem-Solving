/*
problem : https://www.acmicpc.net/problem/10971
solution :
	N이 10이라서 그냥 완전탐색으로 풀이
	l == n 일 때 마지막 점과 출발점의 연결상태를 확인해야했음 (그렇지 않아서 처음에 WA)
	이런 식의 재귀함수에서 chk를 해제하는 것은 한번만 해도 상관없음
	순열과 bitmasking을 활용한 다른 풀이도 확인해볼 것
*/
#include <cstdio>
#include <cstring>
#define INF 987654321
int n, ans = INF, w[10][10];
bool chk[10];
void dfs(int s, int v, int c, int l) {
	chk[v] = 1;
	if (l == n) {
		chk[v] = 0;
		if (!w[v][s]) return;
		ans = ans > c + w[v][s] ? c + w[v][s] : ans;
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (i == v || !w[v][i] || chk[i]) continue;
		dfs(s, i, c + w[v][i], l + 1);
	}
	chk[v] = 0;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) scanf("%d", &w[i][j]);
	}
	for (int i = 0; i < n; ++i) {
		memset(chk, 0, sizeof(chk));
		dfs(i, i, 0, 1);
	}
	printf("%d", ans);
	return 0;
}