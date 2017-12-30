/*
problem : https://www.acmicpc.net/problem/1937
solution :
	DFS + Top-down DP
	d[y][x] = y행 x열에서 출발했을 때 이동할 수 있는 최장 경로 길이
	dfs함수 if문을 처음에 ret += dfs(ny,nx)로 했는데 누적값이 나왔음
	누적값이 아닌 최대값이기 때문에 tmp변수에 각 경로의 길이를 구하고 그 중 최대값을 dp배열에 저장
	이 방식보다 더 깔끔하게 구현할 수 있음. * 다른사람 코드 보기
*/
#include <cstdio>
#include <cstring>
int n, ans = 1, a[500][500], d[500][500];
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
int dfs(int y, int x) {
	int &ret = d[y][x];
	if (ret != -1) return ret;
	ret = 1;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		int tmp = 1;
		if (0 <= ny && ny < n && 0 <= nx && nx < n && a[ny][nx] > a[y][x]) {
			tmp += dfs(ny, nx);
			ret = ret > tmp ? ret : tmp;
		}
	}
	ans = ans > ret ? ans : ret;
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) scanf("%d", &a[i][j]);
	}
	memset(d, -1, sizeof(d));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dfs(i, j);
		}
	}
	printf("%d", ans);
	return 0;
}