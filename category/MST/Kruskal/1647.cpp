#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct Edge {
	int u, v, w;
	bool operator <(const Edge& O)const { return w < O.w; }
}Edge;
Edge ed, e[(int)1e6];
int n, m, a, b, c, mx, ans, p[(int)1e5 + 1], rnk[(int)1e5 + 1];
int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (rnk[x] > rnk[y]) swap(x, y);
	p[x] = y;
	if (rnk[x] == rnk[y])
		rnk[x]++;
}
int main() {
	memset(p, -1, sizeof(p));
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		ed.u = a, ed.v = b, ed.w = c;
		e[i] = ed;
	}
	sort(e, e + m);
	for (int i = 0; i < m; i++) {
		int p1 = find(e[i].u);
		int p2 = find(e[i].v);
		if (p1 ^ p2) {
			merge(e[i].u, e[i].v);
			mx = max(mx, e[i].w);
			ans += e[i].w;
		}
	}
	printf("%d", ans - mx);
	return 0;
}