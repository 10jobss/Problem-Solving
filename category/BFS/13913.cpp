/*
problem : https://www.acmicpc.net/problem/13913
solution :
	BFS Ž���� �ִܰ��, �ִܰŸ� ���ϴ� ����
	d[i] = i�� ó�� �����ϴ� �Ÿ�, p[i] = i�� �θ�
	��θ� ����ϴ� ���� ����
	pprint(int s, int e) --> ���� �������� recursive�� ���� ������ ������� ���� call
	�� s ~ e�� ����ϴ� ���� s ~ e�� ���� ��带 ����ϰ� e�� ����ϴ� ����
*/
#include <cstdio>
#include <cstring>
#include <queue>
#define MAX (int)2e5
#define INF 987654321
using namespace std;
int n, k, d[MAX+1], p[MAX+1];
queue<int> q;
void bfs(int v) {
	d[v] = 0, p[v] = INF;
	q.push(v);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == k) break;
		if (cur + 1 <= MAX && d[cur + 1] == -1) {
			d[cur + 1] = d[cur] + 1;
			p[cur + 1] = cur;
			q.push(cur + 1);
		}
		if (2 * cur <= MAX && d[2 * cur] == -1) {
			d[2 * cur] = d[cur] + 1;
			p[2 * cur] = cur;
			q.push(2*cur);
		}
		if (cur - 1 >= 0 && d[cur - 1] == -1) {
			d[cur - 1] = d[cur] + 1;
			p[cur - 1] = cur;
			q.push(cur - 1);
		}
	}
}
void pprint(int s, int e) {
	if (s == e) {
		printf("%d ", s);
		return;
	}
	pprint(s, p[e]);
	printf("%d ", e);
}
int main() {
	scanf("%d%d", &n, &k);
	if (n >= k) {
		printf("%d\n", n - k);
		for (int i = n; i >= k; i--) printf("%d ", i);
		return 0;
	}
	memset(d, -1, sizeof(d));
	memset(p, -1, sizeof(p));
	bfs(n);
	printf("%d\n", d[k]);
	pprint(n, k);
	return 0;
}