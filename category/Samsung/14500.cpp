/*
problem : https://www.acmicpc.net/problem/14500
solution :
	그냥 구현으로 하려 했으나 회전, 대칭이 있어 까다롭다고 생각
	DFS 탐색을 통해 4칸까지 탐색
	중복되지 않고 한붓그리기? 느낌으로 여러 모양 해결
	ㅓ,ㅏ,ㅗ,ㅜ 는 한붓그리기 불가능하기 때문에 그냥 구현
	나중에 그냥 구현도 연습할 예정
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int N, M, ans, a[500][500];
bool chk[500][500];
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
void dfs(int y, int x, int l, int ret) {
	chk[y][x] = true;
	if (l == 4) {
		ans = max(ans, ret);
		chk[y][x] = 0;
		return;
	}
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (0 <= ny && ny < N && 0 <= nx && nx < M && !chk[ny][nx])
			dfs(ny, nx, l + 1, ret + a[ny][nx]);
	}
	chk[y][x] = 0;
	return;
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) scanf("%d", &a[i][j]);
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) dfs(i, j, 1, a[i][j]);
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (j - 1 >= 0 && j + 1 < M && i - 1 >= 0) {
				ans = max(ans, a[i][j] + a[i][j - 1] + a[i][j + 1] + a[i - 1][j]);
			}
			if (j - 1 >= 0 && j + 1 < M && i + 1 < N) {
				ans = max(ans, a[i][j] + a[i][j - 1] + a[i][j + 1] + a[i + 1][j]);
			}
			if (j - 1 >= 0 && i - 1 >= 0 && i + 1 < N) {
				ans = max(ans, a[i][j] + a[i][j - 1] + a[i - 1][j] + a[i + 1][j]);
			}
			if (j + 1 < M && i - 1 >= 0 && i + 1 < N) {
				ans = max(ans, a[i][j] + a[i][j + 1] + a[i - 1][j] + a[i + 1][j]);
			}
		}
	}
	printf("%d", ans);
	return 0;
}