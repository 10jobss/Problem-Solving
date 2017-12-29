/*
problem : https://www.acmicpc.net/problem/1309
solution :
	상태 DP 정의하는 것이 핵심
	2*N 배열에서 N번째가 OX, XO, XX (d[N][0], d[N][1], d[N][2])
	일차원 배열로 점화식 세우는 것은 생각해내지 못했음
	https://www.acmicpc.net/problem/2133 상태 DP로 다시 풀어볼것
*/
#include <cstdio>
#define MOD 9901
int n, d[100000][3];
int main() {
	scanf("%d", &n);
	d[0][0] = d[0][1] = d[0][2] = 1;
	for (int i = 1; i < n; ++i) {
		d[i][0] = (d[i - 1][1] + d[i - 1][2]) % MOD;
		d[i][1] = (d[i - 1][0] + d[i - 1][2]) % MOD;
		d[i][2] = (d[i - 1][0] + d[i - 1][1] + d[i - 1][2]) % MOD;
	}
	printf("%d", (d[n - 1][0] + d[n - 1][1] + d[n - 1][2]) % MOD);
	return 0;
}