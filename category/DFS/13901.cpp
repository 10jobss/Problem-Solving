/*
problem : https://www.acmicpc.net/problem/13901
solution :
	재귀함수 연습
	막힐 때까지 방향이 바뀌지 않는 것이 특징
	https://www.acmicpc.net/problem/14503 참고
*/
#include <cstdio>
int R, C, k, by, bx, sy, sx, ly, lx, cnt;
int adj[1000][1000];
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
int cmd[4] = { 0 };
void search(int y, int x, int d) {
	adj[y][x] = 1;
	for (int i = 0; i < 4; ++i, d = (d + 1) % 4) {
		int ny = y + dy[cmd[d]], nx = x + dx[cmd[d]];
		if (0 <= ny && ny < R && 0 <= nx && nx < C && !adj[ny][nx]) {
			search(ny, nx, d);
			return;
		}
	}
	ly = y, lx = x;
	return;
}
int main() {
	scanf("%d%d%d", &R, &C, &k);
	for (int i = 0; i < k; ++i) {
		scanf("%d%d", &by, &bx);
		adj[by][bx] = -1;
	}
	scanf("%d%d", &sy, &sx);
	adj[sy][sx] = 1;
	for (int i = 0; i < 4; ++i) {
		scanf("%d", &cmd[i]);
		cmd[i]--;
	}
	search(sy, sx, 0);
	printf("%d %d", ly, lx);
	return 0;
}