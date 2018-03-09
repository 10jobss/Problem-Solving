/*
Problem : https://www.acmicpc.net/problem/1717
Author: 10jobss
Time complexity: O(M*logN)
solution :
	Union-Find 기본 문제
	merge 함수 내 =, == 때문에 계속 틀렸음 조심하자 제발
*/
#include <cstdio>
#define MAX 1000001
int p[MAX];
int find(int x) {
	if (p[x]==x) return x;
	else return p[x] = find(p[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	p[y] = x;
}
int main() {
	int n, m, cmd, a, b, i;
	scanf("%d%d", &n, &m);
	for (i = 0; i <= n; i++) {
		p[i] = i;
	}
	while (m--) {
		scanf("%d%d%d", &cmd, &a, &b);
		if (cmd) {
			find(a) == find(b) ? puts("YES") : puts("NO");
		}
		else {
			merge(a, b);
		}
	}
	return 0;
}