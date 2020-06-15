/*
problem : https://www.acmicpc.net/problem/2098
solution :
	DP + Bitmask
	16! 이기 때문에 순열을 사용할 수 없음
	Cycle임을 고려하면 시작점의 위치는 중요하지 않기 때문에 시작점을 0번 노드로 고정해도 문제 없음
	모든 노드를 방문 했을 때 1<<n - 1 일 때 0번 노드로 갈 수 있는지 확인 해 줘야함.
	못가면 INF
	tsp 호출 flow 써가면서 다시 확인해 볼 것
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;
int n, w[16][16], cache[16][1 << 16];
int tsp(int v, int state) {
	//printf("%d %d\n", v, state);
	int &ret = cache[v][state];
	if (ret != -1) return ret;
	if (state == (1 << n) - 1) {
		return w[v][0] ? w[v][0] : INF;
	}
	ret = INF;
	for (int i = 0; i < n; ++i) {
		if (state&(1 << i) || !w[v][i]) continue;
		ret = min(ret, tsp(i, state | (1 << i)) + w[v][i]);
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) scanf("%d", &w[i][j]);
	}
	memset(cache, -1, sizeof(cache));
	printf("%d", tsp(0, 1));
	return 0;
}
