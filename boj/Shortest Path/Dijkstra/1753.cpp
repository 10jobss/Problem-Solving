/*
problem : https://www.acmicpc.net/problem/1753
solution :
	Dijkstra
	Time complexity -> O(ElogV)
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#define MAX 20000
#define INF 987654321
using namespace std;
typedef pair<int, int> pii;
int v, e, k;
vector<pii> vi[MAX];
vector<int> d;
priority_queue<pii, vector<pii>, greater<pii> > pq;
int main() {
	scanf("%d%d%d", &v, &e, &k);
	d = vector<int>(v, INF);
	int u, vv, w, i;
	while (e--) {
		scanf("%d%d%d", &u, &vv, &w);
		vi[--u].push_back({ --vv,w });
	}
	d[--k] = 0;
	pq.push({ d[k],k });
	while (!pq.empty()) {
		int cur = pq.top().second;
		pq.pop();
		for (i = 0; i < vi[cur].size(); i++) {
			if (d[vi[cur][i].first] > d[cur] + vi[cur][i].second) {
				d[vi[cur][i].first] = d[cur] + vi[cur][i].second;
				pq.push({ d[vi[cur][i].first], vi[cur][i].first });
			}
		}
	}
	for (i = 0; i < v; i++) {
		d[i] == INF ? printf("INF\n") : printf("%d\n", d[i]);
	}
	return 0;
}
