/*
Problem : https://www.acmicpc.net/problem/2638
Author: 10jobss
Time complexity: O(N*M*max(N,M))
solution :
	구현이 까다로운 문제
	치즈 내부에 있는 공간을 구별해주는 것이 관건

	로직은 아래와 같음
	1. 치즈가 있는 공간의 4방향(동,서,남,북)을 탐색해서 빈 공간의 갯수를 d[i][j]에 저장
	   (d[i][j]는 a[i][j]==1 인 경우 (i,j) 주변에 빈 공간의 갯수) 
	2. 내부에 있는 공간을 고려하기 위해서
		2-1. '맨 가장자리에는 치즈가 놓이지 않는다'는 조건을 이용해서 (0,0)에서 bfs 탐색
			  이 때 빈 공간 (a[i][j]==0) 중에서 방문을 한 곳은 외부에 있는 빈 공간이고
			  방문을 하지 않았다면 그 공간은 치즈 내부에 있는 공간을 의미
		2-2. bfs 탐색 완료 후 빈 공간이면서 방문하지 않은 곳의 동,서,남,북을 탐색해
			치즈가 있는 곳이라면 d[i][j]를 감소시킨다
	3. 치즈가 있고 d[i][j]>=2 이상인 곳의 치즈를 녹인다 (sum--)
	
	solve() 한 번 호출이 O(NM)인데
	최악의 경우
	0000000000
	0111111110
	0111111110
	0111111110
	0111111110
	0000000000

	안쪽으로 녹아들어가는 형태라서 엄밀히 말하면 max(N/2, M/2)번 호출해서
	O(N*M*max(N/2, M/2))

	koi에 다른 풀이 확인해보기
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
