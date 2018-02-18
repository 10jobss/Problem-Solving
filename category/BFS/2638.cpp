/*
Problem : https://www.acmicpc.net/problem/2638
Author: 10jobss
Time complexity: O(N*M*max(N,M))
solution :
	������ ��ٷο� ����
	ġ�� ���ο� �ִ� ������ �������ִ� ���� ����

	������ �Ʒ��� ����
	1. ġ� �ִ� ������ 4����(��,��,��,��)�� Ž���ؼ� �� ������ ������ d[i][j]�� ����
	   (d[i][j]�� a[i][j]==1 �� �� (i,j) �ֺ��� �� ������ ����) 
	2. ���ο� �ִ� ������ ����ϱ� ���ؼ�
		2-1. '�� �����ڸ����� ġ� ������ �ʴ´�'�� ������ �̿��ؼ� (0,0)���� bfs Ž��
			  �� �� �� ���� (a[i][j]==0) �߿��� �湮�� �� ���� �ܺο� �ִ� �� �����̰�
			  �湮�� ���� �ʾҴٸ� �� ������ ġ�� ���ο� �ִ� ������ �ǹ�
		2-2. bfs Ž�� �Ϸ� �� �� �����̸鼭 �湮���� ���� ���� ��,��,��,���� Ž����
			ġ� �ִ� ���̶�� d[i][j]�� ���ҽ�Ų��
	3. ġ� �ְ� d[i][j]>=2 �̻��� ���� ġ� ���δ� (sum--)
	
	solve() �� �� ȣ���� O(NM)�ε�
	�־��� ���
	0000000000
	0111111110
	0111111110
	0111111110
	0111111110
	0000000000

	�������� ��Ƶ��� ���¶� ������ ���ϸ� max(N/2, M/2)�� ȣ���ؼ�
	O(N*M*max(N/2, M/2))

	koi�� �ٸ� Ǯ�� Ȯ���غ���
*/
#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 100
using namespace std;
typedef pair<int, int> pii;
int n, m, sum, ans, a[MAX][MAX], d[MAX][MAX];
bool chk[MAX][MAX];
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
bool bound(int y, int x) {
	if (y < 0 || y >= n || x < 0 || x >= m) return false;
	return true;
}
void search() {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (a[i][j]) {
				if (bound(i - 1, j) && !a[i - 1][j]) d[i][j]++;
				if (bound(i, j - 1) && !a[i][j - 1]) d[i][j]++;
				if (bound(i + 1, j) && !a[i + 1][j]) d[i][j]++;
				if (bound(i, j + 1) && !a[i][j + 1]) d[i][j]++;
			}
		}
	}
}
void bfs(int y, int x) {
	queue<pii> q;
	chk[y][x] = true;
	q.push({ y,x });
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (bound(ny, nx) && !chk[ny][nx] && !a[ny][nx]) {
				chk[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
	}
}
void _chk() {
	bfs(0, 0);
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (!a[i][j] && !chk[i][j]) {
				if (bound(i - 1, j) && a[i - 1][j]) d[i - 1][j]--;
				if (bound(i, j-1) && a[i][j-1]) d[i][j-1]--;
				if (bound(i+1, j) && a[i + 1][j]) d[i + 1][j]--;
				if (bound(i, j+1) && a[i][j+1]) d[i][j+1]--;
			}
		}
	}
	memset(chk, false, sizeof(chk));
}
void melt() {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (a[i][j] && d[i][j] >= 2) {
				sum--;
				a[i][j] = 0;
			}
		}
	}
	memset(d, 0, sizeof(d));
}
void solve() {
	search();
	_chk();
	melt();
}
int main() {
	scanf("%d%d", &n, &m);
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j]) sum++;
		}
	}
	while (sum>0) {
		ans++;
		solve();
	}
	printf("%d", ans);
	return 0;
}