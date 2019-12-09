#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#define MAX 100
using namespace std;
typedef struct Node {
	int y, x;
	bool flg;
	Node(int _y, int _x, bool _flg) : y(_y), x(_x), flg(_flg) {};
}Node;
int n, m, t, T, a[MAX][MAX];
bool chk[MAX][MAX][2];
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
int main() {
	scanf("%d%d%d", &n, &m, &T);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	queue<Node> q;
	q.push(Node(0, 0, false));
	for (t = 0; t <= T; t++) {
		if (chk[n - 1][m - 1][0] || chk[n - 1][m - 1][1]) break;
		int qs = (int)q.size();
		for (int i = 0; i < qs; i++) {
			Node cur = q.front();
			q.pop();
			if (cur.y == n - 1 && cur.x == m - 1) break;
			for (int j = 0; j < 4; j++) {
				int ny = cur.y + dy[j];
				int nx = cur.x + dx[j];
				if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
					if (!cur.flg && !chk[ny][nx][0] && a[ny][nx] != 1) {
						chk[ny][nx][0] = true;
						q.push(Node(ny, nx, a[ny][nx] == 2));
					}
					else if (cur.flg && !chk[ny][nx][1]) {
						chk[ny][nx][1] = true;
						q.push(Node(ny, nx, cur.flg));
					}
				}
			}
		}
	}
	chk[n - 1][m - 1][0] || chk[n - 1][m - 1][1] ? printf("%d", t) : printf("Fail");
}
