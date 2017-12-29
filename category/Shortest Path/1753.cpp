/*
problem : https://www.acmicpc.net/problem/1753
solution :
	Dijkstra 기본문제
	priority queue를 활용 (max heap)
	또 풀어볼 것
*/
#include <cstdio>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
typedef pair<int, int> pii;
int v, e, k;
vector<vector<pii> > adj;
vector<int> dist;
priority_queue<pii> pq;
int main() {
	scanf("%d %d %d", &v, &e, &k);
	adj = vector<vector<pii> >(v + 1);
	dist = vector<int>(v + 1, INF);
	dist[k] = 0;
	pq.push({ dist[k],k });
	while (e-- > 0) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back({ v,w });
	}
	while (!pq.empty()) {
		int from = pq.top().second;
		int w = -pq.top().first;
		pq.pop();
		for (int i = 0; i < adj[from].size(); ++i) {
			int to = adj[from][i].first;
			int d = adj[from][i].second;
			if (dist[to] > dist[from] + d) {
				dist[to] = dist[from] + d;
				pq.push({ -d,to });
			}
		}
	}
	for (int i = 1; i <= v; ++i) {
		if (dist[i] == INF) printf("INF\n");
		else printf("%d\n", dist[i]);
	}
	return 0;
}