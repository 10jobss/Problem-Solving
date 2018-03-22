/*
Problem : https://www.acmicpc.net/problem/1939
Author: 10jobss
Time complexity: O(N+M)
solution :
	������ ���� �� �߰����ָ� �Ǵ� BFS ����
	��������� ��λ��� �ּ� ���԰� �����̹Ƿ� �������ָ� �ȴ� (�߰��� �ּҺ��� ũ�� ���ʿ� �� �� ���� ���)
	ó�� Ǯ���� Dijkstra ���� �������� �˰� �߸� Ǯ����
	���� ���� �� '�� ���� �̵�' �̶� ���� �򰥸��µ�
	��� ��忡�� ���� ������ �ߺ����� ���ٴ� ������ �����ϸ� �ȴ�
	�ᱹ ��λ󿡼� �׻� �ּҰ��� �����ϵ� �� �ּҰ� �� �ִ밪�� ã���� �ȴ�

	����) �̺�Ž�� + BFS Ǯ��
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