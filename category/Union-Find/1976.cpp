/*
Problem : https://www.acmicpc.net/problem/1976
Author: 10jobss
Time complexity: O(M*logN)
solution :
잘 생각해보면 중복방문 처리를 신경쓸 필요가 없다
같은 연결요소 내에 있으면 어차피 계획된 경로를 몇번이고 방문할 수 있다는 뜻
따라서 DFS, BFS로도 풀리는 문제이다 O(N^2)

Union-Find로 생각하면 같은 집합 내에 있는 노드들은 모두 방문할 수 있기에
마지막에 route에서 하나라도 다른 부모를 가지고 있다면 NO, 모두 같은 부모이면 YES
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