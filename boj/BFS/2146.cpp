/*
Problem : https://www.acmicpc.net/problem/2146
Author: 10jobss
Time complexity: O(N^4) ???
solution :
	BFS depth에 대해 다시 한번 깨닫게된 문제
	<기존에 생각했던 방식>
	- 연결요소별로 그룹번호 지정하는데 그곳에서 요소 하나만 q에 따로 저장한다(연결요소 갯수만큼 원소가 있다)
	- 그리고 BFS로 섬의 영역을 확장하는 식으로 시도했으나
	10
	1 1 1 0 0 0 0 0 0 0
	1 0 1 0 0 0 0 0 0 0
	0 0 1 0 0 0 0 0 0 0
	0 0 1 0 0 0 0 0 0 0
	0 0 1 0 0 0 0 0 0 0
	0 0 1 0 0 0 0 1 0 0
	0 0 0 0 0 0 1 1 0 0
	0 0 0 0 1 0 1 0 0 0
	0 0 0 0 1 1 1 0 0 0
	0 0 0 0 0 0 0 0 0 0
	위와 같은 반례가 발생 (답 : 3, 출력 : 4)
	- 생각해 보니 아래쪽 섬에서 우상단 방향으로 먼저 영역이 확장되어서 depth를 고려하지 않은채 확장되었음

	<개선 풀이>
	각각의 연결요소에 대해 BFS를 시행
	1. 땅인 부분 4방향을 우선탐색
	2. 4방향 중 바다가 1가지라도 존재한다면 enqueue (0인경우는 어차피 할 필요가 없음)
	3. depth를 고려한 탐색 시작
	   다음 영역이 바다인 경우 enqueue
	   바다가 아닌데 그룹 번호가 다르면 종료

	O(N^2)에 최악의 경우 섬의 크기 1이고 체스판처럼 놓인 상황에서
	(N^2)/2개의 연결요소가 존재하니까 O(N^4)이라고 생각했는데 AC 결과 O(N^3)??? 같은 결과가 나와서
	모르겠음
*/
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;
typedef pair<int, int> pii;
int n, ans=INF, arr[100][100];
bool chk[100][100];
int dy[4] = { -1,0,1,0 }, dx[4] = { 0,1,0,-1 };
queue<pii> q;
bool bnd(int y, int x) {
	return y >= 0 && y < n && x >= 0 && x < n;
}
void color(int y, int x, int c) {
	chk[y][x] = true;
	arr[y][x] = c;
	q.push(make_pair(y, x));
	while (!q.empty()) {
		pii cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];
			if (!bnd(ny, nx)) continue;
			if (!arr[ny][nx]) continue;
			if (chk[ny][nx]) continue;
			chk[ny][nx] = true;
			arr[ny][nx] = c;
			q.push(make_pair(ny, nx));
		}
	}
}
int bfs(int g) {
	queue<pii> Q;
	int i, j, k;
	int ret = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (arr[i][j] != g) continue;
			int cnt = 0;
			for (k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (!bnd(ny, nx)) continue;
				if (!arr[ny][nx]) cnt++;
			}
			if (cnt > 0) {
				chk[i][j] = true;
				Q.push(make_pair(i, j));
			}
		}
	}
	while (!Q.empty()) {
		int q_size = Q.size();
		while (q_size--) {
			pii cur = Q.front();
			Q.pop();
			for (i = 0; i < 4; i++) {
				int ny = cur.first + dy[i];
				int nx = cur.second + dx[i];
				if (!bnd(ny, nx)) continue;
				if (chk[ny][nx]) continue;
				if (!arr[ny][nx]) {
					chk[ny][nx] = true;
					Q.push(make_pair(ny, nx));
				}
				else if (arr[ny][nx] != arr[cur.first][cur.second]) {
					return ret;
				}
			}
		}
		ret++;
	}
}
int main() {
	scanf("%d", &n);
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) scanf("%d", &arr[i][j]);
	}
	int cc = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (arr[i][j] == 1 && !chk[i][j]) {
				color(i, j, ++cc);
			}
		}
	}
	//print_arr();
	for (i = 1; i <= cc; i++) {
		memset(chk, false, sizeof(chk));
		ans = min(ans, bfs(i));
	}
	printf("%d", ans);
	return 0;
}
