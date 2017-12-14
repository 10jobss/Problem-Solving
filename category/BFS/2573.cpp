/*
problem : https://www.acmicpc.net/problem/2573
solution :
	0�� �ƴ� ���� enqueue // put()
	empty queue�� ��� return false (���� �� ����)
	�ֺ��� 0�� �� Ž�� �� ���� �ʿ��� ���ش�
	d�迭�� �ٽ� �ʱ�ȭ�ϰ� return true (���� ���� ����) // search()
	conected component�� ���� BFS // bfs(int, int)
	��� ���� conected component�� 2�� �̻��̸� ����
*/
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int N, M;
int adj[300][300], d[300][300];
bool chk[300][300];
int dy[] = { 1,0,-1,0 }, dx[] = { 0,1,0,-1 };
queue<pii> Q;
void put() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			if (adj[i][j] != 0) Q.push({ i,j });
	}
}
bool search() {
	put();
	if (Q.empty()) return false;
	while (!Q.empty()) {
		int cy = Q.front().first;
		int cx = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (adj[ny][nx] != 0) continue;
			d[cy][cx]++;
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			adj[i][j] -= d[i][j];
			if (adj[i][j] < 0) adj[i][j] = 0;
		}
	}
	memset(d, 0, sizeof(d));
	return true;
}
void bfs(int y, int x) {
	queue<pii> q;
	q.push({ y,x });
	chk[y][x] = true;
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (!adj[ny][nx] || chk[ny][nx]) continue;
			chk[ny][nx] = true;
			q.push({ ny,nx });
		}
	}
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			scanf("%d", &adj[i][j]);
	}
	int ans = 0;
	while (1) {
		int nc = 0;
		if (search()) {
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < M; ++j) {
					if (adj[i][j] != 0 && !chk[i][j]) {
						bfs(i, j);
						nc++;
					}
				}
			}
			memset(chk, 0, sizeof(chk));
			ans++;
		}
		else {
			ans = 0;
			break;
		}
		if (nc >= 2) break;
	}
	printf("%d", ans);
	return 0;
}