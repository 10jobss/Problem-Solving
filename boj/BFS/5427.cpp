/*
problem : https://www.acmicpc.net/problem/5427
solution :
	https://www.acmicpc.net/problem/3055 동일
	단, 테두리에 도착했는지 확인하는 것은 모든 테두리를 조사하는 것 보다
	상근이의 위치를 확인할 때 그 점이 테두리인지 확인하는 것이 효과적
*/
#include <cstdio>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
char adj[1000][1001];
int h, w, q_size, Q_size;
int dy[] = { 1,0,-1,0 }, dx[] = { 0,1,0,-1 };
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int ans = 0;
		bool flag = false;
		queue<pii> q;
		queue<pii> Q;
		scanf("%d%d", &w, &h);
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				scanf(" %c", &adj[i][j]);
				if (adj[i][j] == '@') q.push(make_pair(i, j));
				else if (adj[i][j] == '*') Q.push(make_pair(i, j));
			}
		}
		while (1) {
			ans++;
			q_size = q.size();
			Q_size = Q.size();
			if (!q_size) {
				flag = false;
				break;
			}
			for (int k = 0; k < Q_size; ++k) {
				int fc_y = Q.front().first;
				int fc_x = Q.front().second;
				Q.pop();
				for (int i = 0; i < 4; ++i) {
					int fn_y = fc_y + dy[i];
					int fn_x = fc_x + dx[i];
					if (fn_y < 0 || fn_y >= h || fn_x < 0 || fn_x >= w) continue;
					if (adj[fn_y][fn_x] == '#' || adj[fn_y][fn_x] == '*') continue;
					if (adj[fn_y][fn_x] == '.' || adj[fn_y][fn_x] == '@') {
						adj[fn_y][fn_x] = '*';
						Q.push(make_pair(fn_y, fn_x));
					}
				}
			}
			for (int k = 0; k < q_size; ++k) {
				int cy = q.front().first;
				int cx = q.front().second;
				if (cy == 0 || cy == h - 1 || cx == 0 || cx == w - 1) {
					flag = true;
					break;
				}
				q.pop();
				for (int i = 0; i < 4; ++i) {
					int ny = cy + dy[i];
					int nx = cx + dx[i];
					if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
					if (adj[ny][nx] == '#' || adj[ny][nx] == '@') continue;
					if (adj[ny][nx] == '.') {
						adj[ny][nx] = '@';
						q.push(make_pair(ny, nx));
					}
				}
			}
			if (flag) break;
		}
		if (flag) printf("%d\n", ans);
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}
