/*
problem : https://www.acmicpc.net/problem/2098
solution :
	DP + Bitmask
	16! �̱� ������ ������ ����� �� ����
	Cycle���� ����ϸ� �������� ��ġ�� �߿����� �ʱ� ������ �������� 0�� ���� �����ص� ���� ����
	��� ��带 �湮 ���� �� 1<<n - 1 �� �� 0�� ���� �� �� �ִ��� Ȯ�� �� �����.
	������ INF
	tsp ȣ�� flow �ᰡ�鼭 �ٽ� Ȯ���� �� ��
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;
int n, w[16][16], cache[16][1 << 16];
int tsp(int v, int state) {
	printf("%d %d\n", v, state);
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