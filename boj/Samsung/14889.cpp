/*
problem : https://www.acmicpc.net/problem/14889
solution :
	팀을 나누는 모든 경우를 해볼 수 밖에 없다고 생각
	전체적인 틀은 팀을 나누는 모든 경우의 수를 구하고 능력치의 차를 조사하는 방식으로
	완전탐색해야하는데 bitmask를 이용하려 했으나 잘 떠오르지 않음, 순열 생각했지만 구현을 하지 못함
	각 정점에서 다른 정점으로의 간선이 모두 존재하는 그래프라고 생각
	어차피 한 가지 정점에 대하여 dfs 돌리면 나머지 팀 정보도 알 수 있음
	팀을 나눌 수 있는 경우의 수 : (N C N/2)/2
	dfs 탐색을 통해 방문한 정점의 수가 N/2개일 때 멈추는 방식
	l==N/2일 때 방문한 정점(start팀) 방문하지 않는 정점(link팀)의 차를 구하는 gap() 함수 구현
	
	** '식별자를 찾을 수 없습니다.' gap 함수를 dfs 함수보다 나중에 선언해서 발생
	템플릿 선언 안할꺼면 절차적으로 순서에 맞게 구현할 것
*/
#include <cstdio>
#include <algorithm>
#define INF 987654321
using namespace std;
int n, ans = INF, s[20][20];
bool chk[20];
int gap() {
	int start = 0, link = 0;
	for (int i = 0; i < n; ++i) {
		if (chk[i]) {
			for (int j = 0; j < n; ++j) {
				if (chk[j]) start += s[i][j];
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (!chk[i]) {
			for (int j = 0; j < n; ++j) {
				if (!chk[j]) link += s[i][j];
			}
		}
	}
	return abs(start - link);
}
void dfs(int v, int l) {
	chk[v] = true;
	if (l == n / 2) {
		ans = min(ans, gap());
		chk[v] = false;
		return;
	}
	for (int i = v + 1; i < n; ++i) {
		if (!chk[i]) dfs(i, l + 1);
	}
	chk[v] = false;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) scanf("%d", &s[i][j]);
	}
	dfs(0, 1);
	printf("%d", ans);
	return 0;
}