/*
Problem : https://www.acmicpc.net/problem/1753
Author: 10jobss
Time complexity: O(M*logN)
solution :
	BFS, DFS로도 가능하지만 Union-Find를 활용했다
	merge에서 특별히 정의하지 않는 경우
	root가 계속 바뀔 수 있다 !!!! <-- 주의
	따라서 정답을 구할 시 find(i) == 1이 아닌 find(i)==find(1)을 해주어야 한다

	Union-Find는 집합의 갯수 등을 구할 때 조심해야할 필요가 있을 것 같다
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
