/*
problem : https://www.acmicpc.net/problem/2251
solution :
	BFS를 이용한 완전탐색 문제
	방문한 상태를 제외하고 a에서, b에서, c에서 각각 나머지 물통으로 이동했을 때 생각
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int va, vb, vc;
struct node {
	int a, b, c;
};
bool chk[201][201][201];
int main() {
	scanf("%d%d%d", &va, &vb, &vc);
	queue<node> q;
	vector<int> ans;
	chk[0][0][vc] = true;
	q.push({ 0,0,vc });
	while (!q.empty()) {
		node cur = q.front();
		if (cur.a == 0) ans.push_back(cur.c);
		q.pop();
		if (cur.a > 0) {
			if (vb - cur.b >= cur.a) {
				if (!chk[0][cur.b + cur.a][cur.c]) {
					chk[0][cur.b + cur.a][cur.c] = true;
					q.push({ 0, cur.b + cur.a, cur.c });
				}
			}
			else {
				if (!chk[cur.a + cur.b - vb][vb][cur.c]) {
					chk[cur.a + cur.b - vb][vb][cur.c] = true;
					q.push({ cur.a + cur.b - vb, vb, cur.c });
				}
			}
			if (vc - cur.c >= cur.a) {
				if (!chk[0][cur.b][cur.c + cur.a]) {
					chk[0][cur.b][cur.c + cur.a] = true;
					q.push({ 0, cur.b, cur.c + cur.a });
				}
			}
			else {
				if (!chk[cur.a + cur.c - vc][cur.b][vc]) {
					chk[cur.a + cur.c - vc][cur.b][vc] = true;
					q.push({ cur.a + cur.c - vc, cur.b, vc });
				}
			}
		}
		if (cur.b > 0) {
			if (va - cur.a >= cur.b) {
				if (!chk[cur.a + cur.b][0][cur.c]) {
					chk[cur.a + cur.b][0][cur.c] = true;
					q.push({ cur.a + cur.b, 0, cur.c });
				}
			}
			else {
				if (!chk[va][cur.b + cur.a - va][cur.c]) {
					chk[va][cur.b + cur.a - va][cur.c] = true;
					q.push({ va, cur.b + cur.a - va, cur.c });
				}
			}
			if (vc - cur.c >= cur.b) {
				if (!chk[cur.a][0][cur.c + cur.b]) {
					chk[cur.a][0][cur.c + cur.b] = true;
					q.push({ cur.a, 0, cur.c + cur.b });
				}
			}
			else {
				if (!chk[cur.a][cur.b + cur.c - vc][vc]) {
					chk[cur.a][cur.b + cur.c - vc][vc] = true;
					q.push({ cur.a, cur.b + cur.c - vc, vc });
				}
			}
		}
		if (cur.c > 0) {
			if (va - cur.a >= cur.c) {
				if (!chk[cur.a + cur.c][cur.b][0]) {
					chk[cur.a + cur.c][cur.b][0] = true;
					q.push({ cur.a + cur.c, cur.b, 0 });
				}
			}
			else {
				if (!chk[va][cur.b][cur.c + cur.a - va]) {
					chk[va][cur.b][cur.c + cur.a - va] = true;
					q.push({ va, cur.b, cur.c + cur.a - va });
				}
			}
			if (vb - cur.b >= cur.c) {
				if (!chk[cur.a][cur.b + cur.c][0]) {
					chk[cur.a][cur.b + cur.c][0] = true;
					q.push({ cur.a, cur.b + cur.c, 0 });
				}
			}
			else {
				if (!chk[cur.a][vb][cur.c + cur.b - vb]) {
					chk[cur.a][vb][cur.c + cur.b - vb] = true;
					q.push({ cur.a, vb, cur.c + cur.b - vb });
				}
			}
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); ++i)
		printf("%d ", ans[i]);
	return 0;
}