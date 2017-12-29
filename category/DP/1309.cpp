/*
problem : https://www.acmicpc.net/problem/1309
solution :
	���� DP �����ϴ� ���� �ٽ�
	2*N �迭���� N��°�� OX, XO, XX (d[N][0], d[N][1], d[N][2])
	������ �迭�� ��ȭ�� ����� ���� �����س��� ������
	https://www.acmicpc.net/problem/2133 ���� DP�� �ٽ� Ǯ���
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