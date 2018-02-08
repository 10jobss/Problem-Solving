/*
problem : https://www.acmicpc.net/problem/1261
solution :
	BFS 탐색 변형
	아무생각 없이 queue를 이용해서 BFS 탐색으로 풀었으나 TLE (반드시 고쳐야할 부분!!)
	부수는 벽의 갯수를 최소화해야 하기 때문에 길인 곳을 우선으로 보는 로직
	deque을 이용해 길인 경우 push_front(), 벽인 경우 push_back()
	priority queue를 이용한 풀이도 가능

	<새롭게 깨달은 사실>
	1. memset > for loop > std::fill (속도 빠른 순)
	std:fill이 매우 느리다는 사실을 깨달았다.. (fill을 계속썼는데 TLE, 앞으론 fill을 쓸 일 있으면 그냥 for loop)
	
	2. c와 c++의 struct 차이점
	https://www.geeksforgeeks.org/difference-c-structures-c-structures/

	문제를 풀 떄 더 최적화가 가능한지 생각해보는 습관을 가져야겠다
	(우선순위를 부여하거나 자료구조를 통해 최적화 탐색이 가능한지)
	완전탐색의 경우는 어쩔 수 없지만
	가능하다면 탐색 시 불필요한 부분을 배제해 최적화하는 습관을 가져야 겠다(느낌은 Backtracking 같다..)
	
	DP, Dijkstra를 이용한 풀이도 해볼 것
*/
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
int m, n, cnt[100][100];
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
bool a[100][100];
deque<pii> dq;
int main() {
	int i, j;
	scanf("%d%d", &m, &n);
	memset(cnt, -1, sizeof(cnt));
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) scanf("%1d", &a[i][j]);
	}
	cnt[0][0] = 0;
	dq.push_front({ 0,0 });
	while (!dq.empty() && cnt[n - 1][m - 1] == -1) {
		int cy = dq.front().first;
		int cx = dq.front().second;
		dq.pop_front();
		for (i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (cnt[ny][nx] == -1) {
				if (a[ny][nx]) {
					cnt[ny][nx] = cnt[cy][cx] + 1;
					dq.push_back({ ny,nx });
				}
				else {
					cnt[ny][nx] = cnt[cy][cx];
					dq.push_front({ ny,nx });
				}
			}
		}
	}
	printf("%d", cnt[n - 1][m - 1]);
	return 0;
}