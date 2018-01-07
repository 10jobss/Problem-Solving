/*
problem : https://www.acmicpc.net/problem/13458
solution :
	각 시험장에서 총감독관이 감독할 수 있는 수를 기본적으로 빼고 계산
	최악의 경우 범위 항상 조심해야함
*/
#include <cstdio>
#define MAX (int)1e+6
typedef long long ll;
int n, b, c, a[MAX];
ll cnt;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	scanf("%d%d", &b, &c);
	for (int i = 0; i < n; ++i) {
		a[i] -= b;
		if (a[i] > 0) {
			if (a[i] % c == 0) cnt += (a[i] / c);
			else cnt += (a[i] / c + 1);
		}
	}
	printf("%lld", cnt + n);
	return 0;
}