/*
Problem : https://icpc.me/9370
Author: 10jobss
Time complexity: O(M*logN)
solution :
	'�ִܰŸ��� �ִܰŸ���� �̷������' ��� ������ ����Ǯ���� �����̾���.
	�����(s)���� ���� ������(g, h)�� ���� ���� �ĺ��� �����ؾ��Ѵ�.
	���������� (����� ~ ���� �ĺ� �Ÿ�) = (����� ~ ������) + (������ ~ �����ĺ��Ÿ�)�� �������� ����Ѵ�.

	1) �����(s)�� ������(g,h)�� ���Ͽ� ���� ���ͽ�Ʈ�� �˰����� ���� (�� 3ȸ)
	2) (s ~ �����ĺ��Ÿ�) = min( {(s~g) + (g~�����ĺ�)}, {(s~h) + (h~�����ĺ�)} )�� �ĺ������� ���Ѵ�

	https://icpc.me/1504 ������ ����ϴ�.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
const int INF = 2000 * 1000 + 1;
vector<pii > vpii[2000 + 1];
vector<int> ans;
int dst[3][2000 + 1], to[3], from[100 + 1];
int main() {
	int tc, n, m, t;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		scanf("%d%d%d%d%d%d", &n, &m, &t, &to[0], &to[1], &to[2]);
		for (int i = 1; i <= n; i++) {
			dst[0][i] = dst[1][i] = dst[2][i] = INF;
			vpii[i].clear();
		}
		ans.clear();
		while (m--) {
			int a, b, d;
			scanf("%d%d%d", &a, &b, &d);
			vpii[a].push_back({ b,d });
			vpii[b].push_back({ a,d });
		}
		for (int i = 0; i < t; i++)
			scanf("%d", from + i);
		priority_queue<pii > pq;
		for (int i = 0; i < 3; i++) {
			dst[i][to[i]] = 0;
			pq.push({ 0, to[i] });
			while (!pq.empty()) {
				int cur = pq.top().second;
				int cw = -pq.top().first;
				pq.pop();
				if (dst[i][cur] < cw) continue;
				for (int j = 0; j < (int)vpii[cur].size(); j++) {
					int next = vpii[cur][j].first;
					int nw = vpii[cur][j].second;
					if (dst[i][next] > cw + nw) {
						dst[i][next] = cw + nw;
						pq.push({ -dst[i][next], next });
					}
				}
			}
		}
		for (int i = 0; i < t; i++) {
			int tmp1 = dst[0][to[1]] + dst[1][to[2]] + dst[2][from[i]];
			int tmp2 = dst[0][to[2]] + dst[2][to[1]] + dst[1][from[i]];
			if (dst[0][from[i]] >= min(tmp1, tmp2))
				ans.push_back(from[i]);
		}
		sort(ans.begin(), ans.end());
		for (int x : ans)
			printf("%d ", x);
		puts("");
	}
	return 0;
}