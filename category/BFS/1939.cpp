/*
Problem : https://www.acmicpc.net/problem/1939
Author: 10jobss
Time complexity: O(N+M)
solution :
	정보를 조금 더 추가해주면 되는 BFS 문제
	현재까지의 경로상의 최소 무게가 기준이므로 저장해주면 된다 (중간에 최소보다 크면 애초에 갈 수 없는 경로)
	처음 풀때는 Dijkstra 같은 문제인줄 알고 잘못 풀었다
	문제 설명 중 '한 번의 이동' 이란 말이 헷갈리는데
	출발 노드에서 도착 노드까지 중복없이 간다는 뜻으로 생각하면 된다
	결국 경로상에서 항상 최소값을 유지하되 그 최소값 중 최대값을 찾으면 된다

	참고) 이분탐색 + BFS 풀이
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100001
#define INF 1000000001
using namespace std;
typedef pair<int, int> pii;
int n, m;
int s, e;
vector<pii> vpii[MAX];
int w[MAX];
void bfs() {
	queue<pii> q;
	w[s] = 0;
	q.push(make_pair(s, INF));
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			int cur = q.front().first;
			int nw = q.front().second;
			q.pop();
			for (int i = 0; i < vpii[cur].size(); i++) {
				int next = vpii[cur][i].second;
				if (w[next] == -1) {
					w[next] = min(nw, vpii[cur][i].first);
					q.push(make_pair(next, w[next]));
				}
				else {
					if (w[next] < min(nw, vpii[cur][i].first)) {
						w[next] = min(nw, vpii[cur][i].first);
						q.push(make_pair(next, w[next]));
					}
				}
			}
		}
	}
}
int main() {
	memset(w, -1, sizeof(w));
	scanf("%d%d", &n, &m);
	while (m--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		vpii[a].push_back(make_pair(c, b));
		vpii[b].push_back(make_pair(c, a));
	}
	scanf("%d%d", &s, &e);
	bfs();
	printf("%d", w[e]);
	return 0;
}