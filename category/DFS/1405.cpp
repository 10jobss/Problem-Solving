/*
problem : https://www.acmicpc.net/problem/1405
solution :
	배반사건을 구하는 것이 구현이 더 까다로움
	parameter로 횟수, 확률을 이용해 dfs 탐색
	재귀함수 돌아가는 로직 다시 확인해 볼 것
	초기화 조심!
*/
#include <cstdio>
int n, a[29][29];
double ans, p[4];
bool chk[29][29];
int dy[4] = { 0,0,1,-1 }, dx[4] = { 1,-1,0,0 };
void dfs(int y, int x, int l, double prob) {
	chk[y][x] = true;
	if (l == n) {
		ans += prob;
		chk[y][x] = false;
		return;
	}
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (0 <= ny && ny < 29 && 0 <= nx && nx < 29 && !chk[ny][nx]) {
			dfs(ny, nx, l + 1, prob*p[i]);
		}
	}
	chk[y][x] = false;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < 4; ++i) {
		scanf("%lf", &p[i]);
		p[i] /= 100;
	}
	dfs(14, 14, 0, 1.0);
	printf("%.9f", ans);
	return 0;
}