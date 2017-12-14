/*
problem : https://www.acmicpc.net/problem/11559
solution :
	BFS를 통해 넓이가 4이상인 경우 .으로 바꾸고 1, 그렇지 않으면 0 return
	터지고 나서 맵 변경 // down()
	현재 코드는 search 후 무조건 down인데 생각해보니 변하지 않았다면 down할 필요가 없음
*/
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
char adj[12][6];
bool chk[12][6];
int dy[] = { 1,0,-1,0 }, dx[] = { 0,1,0,-1 };
queue<pii> Q;
int bfs(int y, int x) {
	int l = 1;
	chk[y][x] = true;
	queue<pii> q;
	q.push({ y,x });
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || ny >= 12 || nx < 0 || nx >= 6) continue;
			if (adj[ny][nx] != adj[cy][cx]) continue;
			if (chk[ny][nx]) continue;
			chk[ny][nx] = true;
			l++;
			q.push({ ny,nx });
		}
	}
	if (l >= 4) {
		for (int i = 11; i >= 0; --i) {
			for (int j = 0; j < 6; ++j) {
				if (chk[i][j]) adj[i][j] = '.';
			}
		}
		return 1;
	}
	return 0;
}
void down() {
	for (int i = 0; i < 6; ++i) {
		int d = 0;
		for (int j = 11; j >= 0;) {
			if (j < 0) break;
			if (adj[j][i] == '.') { d++, j--; }
			else {
				char tmp = adj[j][i];
				adj[j][i] = '.';
				adj[j + d][i] = tmp;
				Q.push({ j + d,i });
				j = j + d - 1;
				d = 0;
			}
		}
	}
}
int main() {
	int cnt = 0;
	for (int i = 0; i < 12; ++i) {
		for (int j = 0; j < 6; ++j) {
			scanf(" %c", &adj[i][j]);
			if (adj[i][j] != '.') Q.push({ i,j });
		}
	}
	while (1) {
		int bn = 0;
		while (!Q.empty()) {
			int sy = Q.front().first;
			int sx = Q.front().second;
			Q.pop();
			int ret = bfs(sy, sx);
			if (ret == 1) bn++;
			memset(chk, 0, sizeof(chk));
		}
		down();
		if (bn > 0) cnt++;
		else break;
	}
	printf("%d", cnt);
	return 0;
}
