/*
problem : https://www.acmicpc.net/problem/14501
solution :
	DP 활용
	d[i][N] N번째 일 상담까지 고려했을 때(하거나 하지 않거나) 최대 이익 (i=0,1 상담X, 상담O)
	먼저 해당날짜가 상담 가능한지 확인, 못하면 a[0][N] = 0
	N일에 상담을 하지 않았다면 N-1일에 상담을 할 때와 하지 않았을 때 중 최대값 (optimal substructure??)
	N일에 상담을 한다면 1 ~ N-1까지 중에서 **상담이 가능할 때** 중 최대값
	(여기서 조심. 각 일에서 상담을 했을 때만 고려, 하지 않았을 때를 고려하면 예외발생.. 근데 거의 감으로 풀긴함)
	문제파악, 검증 후 코딩에 들어감.. 앞으로 이렇게 계속
	DP 연습이 더 필요.
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int n, a[2][16], d[2][16];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &a[0][i], &a[1][i]);
		if (i + a[0][i] > n + 1) a[0][i] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		d[0][i] = max(d[0][i - 1], d[1][i - 1]);
		if (!a[0][i]) continue;
		for (int j = 1; j < i; ++j) {
			if (j + a[0][j] <= i) {
				d[1][i] = max(d[1][i], d[1][j]);
			}
		}
		d[1][i] += a[1][i];
	}
	printf("%d", max(d[0][n], d[1][n]));
	return 0;
}