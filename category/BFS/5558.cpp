/*
Problem : https://www.acmicpc.net/problem/5558
Author: 10jobss
Time complexity: O(N*H*W)
solution :
	BFS�� ������ �õ��ؾ� �ϴ� �����̴�
	ó���� chk �迭 ����ó���� ���� �ʾ� MLE�� �޾Ҵ�
	ġ� ��ȣ ������� �Ծ�� �ϹǷ� �������� �ٲ��ָ鼭 BFSŽ���� ���ָ� �ȴ�
	BFS 1���� O(H*W) �̹Ƿ� �ִ� N�� ȣ���ؾ� �ϹǷ� �ð����⵵�� O(N*H*W)�̴�
*/
#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 1000
using namespace std;
typedef pair<int, int> pii;
int h, w, n, ans;
int sy, sx;
char a[MAX][MAX];
bool chk[MAX][MAX];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
void bfs(int y, int x, int k) {
	memset(chk, 0, sizeof(chk));
	queue<pii > q;
	q.push(make_pair(y, x));
	chk[y][x] = 1;
	while (!q.empty()) {
		int qs = q.size();
		ans++;
		while (qs--) {
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop();
			for (int i = 0; i<4; i++) {
				int ny = cy + dy[i];
				int nx = cx + dx[i];
				if (ny<0 || ny >= h || nx<0 || nx >= w) continue;
				if (a[ny][nx] == 'X') continue;
				if (chk[ny][nx]) continue;
				if (a[ny][nx] - '0' == k) {
					sy = ny, sx = nx;
					return;
				}
				else {
					chk[ny][nx] = 1;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &h, &w, &n);
	for (int i = 0; i<h; i++) {
		for (int j = 0; j<w; j++) {
			scanf(" %c", &a[i][j]);
			if (a[i][j] == 'S') sy = i, sx = j;
		}
	}
	for (int i = 1; i <= n; i++) {
		bfs(sy, sx, i);
	}
	printf("%d", ans);
	return 0;
}