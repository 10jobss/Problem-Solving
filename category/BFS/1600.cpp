/*
Problem : https://www.acmicpc.net/problem/1600
Author: 10jobss
Time complexity: O(H*W*K)
solution :
	��ٷο� BFS ��������
	������ �ȹٷ� ���� �ʾƼ� ���� �̵��� ���� �� ������ �̵����� ������ �����ߴµ�
	(MLE, WA ���.......)
	0 0 0 1 1
	0 0 0 1 1
	0 0 0 1 1
	1 1 1 0 0
	1 1 1 0 0
	�̰� k=1�� ��찡 �ݷ�
	BFS Ư�� �� ���ʷ� �������� �������� ���� �ִܰŸ�
	chk[i][j][k] : (i,j)�̰� ���� �̵��� k�� ���� ����
*/
#include <cstdio>
#include <queue>
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define MAX 200
int k, w, h, a[MAX][MAX];
int dy[4] = { -1,0,1,0 }, dx[4] = { 0,1,0,-1 };
int kdy[8] = { -1,-2,-2,-1,1,2,2,1 }, kdx[8] = { -2,-1,1,2,2,1,-1,-2 };
bool chk[MAX][MAX][31];
using namespace std;
typedef struct state {
	int y, x, k, d;
	state(int _y, int _x, int _k, int _d) : y(_y), x(_x), k(_k), d(_d) {}
}STATE;
bool bnd(int y, int x) {
	if (y < 0 || y >= h || x < 0 || x >= w) return false;
	return true;
}
int bfs(int k) {
	queue<STATE> q;
	chk[0][0][k] = true;
	q.push(state(0, 0, k, 0));
	while (!q.empty()) {
		STATE cur = q.front();
		q.pop();
		if (cur.y == h - 1 && cur.x == w - 1) {
			return cur.d;
		}
		fup(i, 0, 3, 1) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if (!bnd(ny, nx)) continue;
			if (a[ny][nx]) continue;
			if (chk[ny][nx][cur.k]) continue;
			chk[ny][nx][cur.k] = true;
			q.push(state(ny, nx, cur.k, cur.d + 1));
		}
		if (cur.k == 0) continue;
		fup(i, 0, 7, 1) {
			int ny = cur.y + kdy[i];
			int nx = cur.x + kdx[i];
			if (!bnd(ny, nx)) continue;
			if (a[ny][nx]) continue;
			if (chk[ny][nx][cur.k - 1]) continue;
			chk[ny][nx][cur.k - 1] = true;
			q.push(state(ny, nx, cur.k - 1, cur.d + 1));
		}
	}
	return -1;
}
int main() {
	scanf("%d%d%d", &k, &w, &h);
	fup(i, 0, h - 1, 1) fup(j, 0, w - 1, 1) scanf("%d", &a[i][j]);
	printf("%d", bfs(k));
	return 0;
}