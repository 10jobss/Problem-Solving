/*
problem : https://www.acmicpc.net/problem/14501
solution :
	DP Ȱ��
	d[i][N] N��° �� ������ ������� ��(�ϰų� ���� �ʰų�) �ִ� ���� (i=0,1 ���X, ���O)
	���� �ش糯¥�� ��� �������� Ȯ��, ���ϸ� a[0][N] = 0
	N�Ͽ� ����� ���� �ʾҴٸ� N-1�Ͽ� ����� �� ���� ���� �ʾ��� �� �� �ִ밪 (optimal substructure??)
	N�Ͽ� ����� �Ѵٸ� 1 ~ N-1���� �߿��� **����� ������ ��** �� �ִ밪
	(���⼭ ����. �� �Ͽ��� ����� ���� ���� ���, ���� �ʾ��� ���� ����ϸ� ���ܹ߻�.. �ٵ� ���� ������ Ǯ����)
	�����ľ�, ���� �� �ڵ��� ��.. ������ �̷��� ���
	DP ������ �� �ʿ�.
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