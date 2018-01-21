/*
problem : https://www.acmicpc.net/problem/10971
solution :
	N이 10이라서 그냥 완전탐색으로 풀이
	https://www.acmicpc.net/problem/2098 과 같이 n이 16만 되도 dfs방식, 순열은 TLE
	DP + bistmask 방법 공부하기
*/
/*
1. DFS
l == n 일 때 마지막 점과 출발점의 연결상태를 확인해야했음 (그렇지 않아서 처음에 WA)
이런 식의 재귀함수에서 chk 해제하는 것 조심
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

/*
2. Permutation
순열을 이용해 경로를 나열하는 방식
10! 이므로 시간 내 가능 (n이 크다면 불가능)
마지막 정점 --> 출발점을 처리하기 위해서 modular 사용
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
int n, w[10][10], ans = INF;
int main() {
	scanf("%d", &n);
	vector<int> p(n);
	for (int i = 0; i<n; ++i) p[i] = i;
	for (int i = 0; i<n; ++i) {
		for (int j = 0; j<n; ++j) scanf("%d", &w[i][j]);
	}
	do {
		int cost = 0;
		bool flag = true;
		for (int i = 0; i<n; ++i) {
			if (!w[p[i%n]][p[(i + 1)%n]]) {
				flag = false;
				break;
			}
			cost += w[p[i%n]][p[(i + 1)%n]];
		}
		if (flag) ans = min(ans, cost);
	} while (next_permutation(p.begin(), p.end()));
	printf("%d", ans);
	return 0;
}
