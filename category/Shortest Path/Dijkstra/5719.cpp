/*
Problem : https://icpc.me/5719
Author: 10jobss
Time complexity: O(M*logN)
solution :
	다익스트라 알고리즘을 통해 최단경로의 간선을 파악하는 문제이다
	1) 다익스트라를 이용해 최단경로를 구한다
	2) DFS를 이용해 최단경로에 포함하는 간선들을 표시한다
	3) 기존 최단경로의 간선들을 제외한 새로운 최단경로를 구한다

	- init하는 과정에서 실수가 있었다. 함수 구현이 매끄럽지 못했음
	- 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_N 500
#define INF 500*1000+1
using namespace std;
typedef pair<int, int> pii;
vector<pii > vpii[MAX_N];
int n, m, s, e, u, v, p, d[MAX_N], chk[MAX_N], adj[MAX_N][MAX_N];
void init() {
	for (int i = 0; i < n; i++)
		d[i] = INF;
	memset(chk, 0, sizeof(chk));
}
void dijk() {
	priority_queue<pii > pq;
	d[s] = 0;
	pq.push({ d[s],s });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cw = pq.top().first;
		pq.pop();
		if (cur == e) continue;
		if (d[cur] < cw) continue;
		for (int i = 0; i < (int)vpii[cur].size(); i++) {
			int next = vpii[cur][i].second;
			int nw = vpii[cur][i].first;
			if (adj[cur][next] < 0) continue;
			if (d[next] > nw - cw) {
				d[next] = nw - cw;
				pq.push({ -d[next],next });
			}
		}
	}
}
void f() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			adj[i][j] = (adj[i][j] == 1 ? -1 : adj[i][j]);
}
void dfs(int k, int dst) {
	chk[k] = 1;
	if (k == e)
		f();
	for (int i = 0; i < (int)vpii[k].size(); i++) {
		int next = vpii[k][i].second;
		int nw = vpii[k][i].first;
		if (!chk[next] && dst + nw <= d[e]) {
			adj[k][next] = 1;
			dfs(next, dst + nw);
			adj[k][next] = (adj[k][next] < 0 ? adj[k][next] : 0); // 간선 정보 reset시 주의
		}
	}
	chk[k] = 0;
}
int main() {
	setbuf(stdout, NULL);
	//freopen("sample_input.txt", "r", stdin);
	n = -1, m = -1;
	while (1) {
		scanf("%d%d", &n, &m);
		if (!n && !m) break;
		scanf("%d%d", &s, &e);
		for (int i = 0; i < n; i++) // TC를 여러개 받는 문제는 항상 초기화 조심
			vpii[i].clear();
		while (m--) {
			scanf("%d%d%d", &u, &v, &p);
			vpii[u].push_back({ p,v });
		}
		init();
		memset(adj, 0, sizeof(adj));
		dijk();
		dfs(s, 0);
		init();
		dijk();
		d[e] == INF ? puts("-1") : printf("%d\n", d[e]);
	}
	return 0;
}