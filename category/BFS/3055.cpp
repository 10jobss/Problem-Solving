/*
problem : https://www.acmicpc.net/problem/3055
solution :
물 이동 후 고슴도치 이동 (번갈아가면서 BFS)
노드가 같은 레벨에 여러 개있는 경우 동시에 진행되므로 q_size, Q_size만큼 반복
*/
#include <cstdio>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int R, C, q_size, Q_size;
char adj[50][50];
int dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };
bool safe(int y, int x) {
	if (y < 0 || y >= R || x < 0 || x >= C) return false;
	if (adj[y][x] == 'X') return false;
	return true;
}
int main() {
	int ey, ex;
	scanf("%d%d", &R, &C);
	queue<pii> Q;
	queue<pii> q;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			scanf(" %c", &adj[i][j]);
			if (adj[i][j] == 'S') { Q.push({ i,j }); }
			else if (adj[i][j] == 'D') { ey = i, ex = j; }
			else if (adj[i][j] == '*') { q.push({ i,j }); }
		}
	}
	int ans = 0;
	while (1) {
		if (adj[ey][ex] == 'S') break;
		q_size = q.size();
		Q_size = Q.size();
		if (Q_size == 0) {
			printf("KAKTUS");
			return 0;
		}
		for (int k = 0; k < q_size; k++) {
			int wc_y = q.front().first;
			int wc_x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int wn_y = wc_y + dy[i];
				int wn_x = wc_x + dx[i];
				if (!safe(wn_y, wn_x)) continue;
				if (adj[wn_y][wn_x] == 'D') continue;
				if (adj[wn_y][wn_x] == '*') continue;
				adj[wn_y][wn_x] = '*';
				q.push({ wn_y,wn_x });
			}
		}
		for (int k = 0; k < Q_size; k++) {
			int cy = Q.front().first;
			int cx = Q.front().second;
			Q.pop();
			for (int i = 0; i < 4; ++i) {
				int ny = cy + dy[i];
				int nx = cx + dx[i];
				if (!safe(ny, nx)) continue;
				if (adj[ny][nx] == '*') continue;
				if (adj[ny][nx] == 'S') continue;
				adj[ny][nx] = 'S';
				Q.push({ ny,nx });
			}
		}
		ans++;
	}
	printf("%d", ans);
	return 0;
}