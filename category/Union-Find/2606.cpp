/*
Problem : https://www.acmicpc.net/problem/1753
Author: 10jobss
Time complexity: O(M*logN)
solution :
	BFS, DFS�ε� ���������� Union-Find�� Ȱ���ߴ�
	merge���� Ư���� �������� �ʴ� ���
	root�� ��� �ٲ� �� �ִ� !!!! <-- ����
	���� ������ ���� �� find(i) == 1�� �ƴ� find(i)==find(1)�� ���־�� �Ѵ�

	Union-Find�� ������ ���� ���� ���� �� �����ؾ��� �ʿ䰡 ���� �� ����
*/
#include <cstdio>
#include <cstring>
int p[101];
int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a;
}
int main() {
	memset(p, -1, sizeof(p));
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		merge(a, b);
	}
	int i, ans = 0;
	for (i = 2; i <= n; i++) {
		if (find(i) == find(1)) ans++;
	}
	printf("%d", ans);
	return 0;
}