/*
Problem : https://www.acmicpc.net/problem/1976
Author: 10jobss
Time complexity: O(M*logN)
solution :
�� �����غ��� �ߺ��湮 ó���� �Ű澵 �ʿ䰡 ����
���� ������ ���� ������ ������ ��ȹ�� ��θ� ����̰� �湮�� �� �ִٴ� ��
���� DFS, BFS�ε� Ǯ���� �����̴� O(N^2)

Union-Find�� �����ϸ� ���� ���� ���� �ִ� ������ ��� �湮�� �� �ֱ⿡
�������� route���� �ϳ��� �ٸ� �θ� ������ �ִٸ� NO, ��� ���� �θ��̸� YES
*/
#include <cstdio>
#include <cstring>
int p[201], arr[201][201], route[1000];
int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	p[y] = x;
}
int main() {
	memset(p, -1, sizeof(p));
	int i, j, n, m;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) scanf("%d", &arr[i][j]);
	}
	for (i = 0; i < m; i++) scanf("%d", &route[i]);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (j <= i) continue;
			if (arr[i][j]) {
				merge(i, j);
			}
		}
	}
	int root = find(route[0]);
	for (i = 1; i < m; i++) {
		if (root != find(route[i])) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}