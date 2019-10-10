#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int n, m;
bool chk[1000 + 1];
vector<pii > vpii[1000 + 1];
priority_queue<pii > pq;
int prim(int flg) {
	memset(chk, 0, sizeof(chk));
	int ret = 0;
	for (pii x : vpii[0])
		pq.push({ x.first * flg, x.second });
	chk[0] = 1;
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cw = pq.top().first;
		pq.pop();
		if (chk[cur]) continue;
		chk[cur] = 1;
		ret += (cw == 0);
		for (pii x : vpii[cur]) {
			int next = x.second;
			int nw = x.first;
			if (!chk[next])
				pq.push({ nw * flg,next });
		}
	}
	return ret * ret;
}
int main() {
	scanf("%d%d", &n, &m);
	m++;
	while (m--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		vpii[a].push_back({ c,b });
		vpii[b].push_back({ c,a });
	}
	printf("%d", prim(-1) - prim(1));
	return 0;
}