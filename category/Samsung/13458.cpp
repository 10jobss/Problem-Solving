/*
problem : https://www.acmicpc.net/problem/13458
solution :
	�� �����忡�� �Ѱ������� ������ �� �ִ� ���� �⺻������ ���� ���
	�־��� ��� ���� �׻� �����ؾ���
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