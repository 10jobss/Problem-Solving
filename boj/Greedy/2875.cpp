/*
Problem : https://www.acmicpc.net/problem/2875
Author: 10jobss
Time complexity: O(1)
solution :
	Ǯ���� Ȯ���غ��� Greedy��µ� �´� ������ ���߿� �ؾ߰ڴ�

	1. ���л�, ���л� ���� ������ ��� ���� ���� �� �ּҰ��� ���Ѵ�
	2. ���� ������ ���� �л� ���� ���Ѵ�
	3. k ���� ���� ��쿡 ���� ���� ������ ���� �л����� ������ ä���
	   �������� ���� ��ü ��Ű�鼭 ä���
*/
#include <cstdio>
int main() {
	int n, m, k, ans;
	scanf("%d%d%d", &n, &m, &k);
	ans = n / 2 < m ? n / 2 : m;
	n -= ans * 2;
	m -= ans;
	if (n + m < k) {
		k -= (n + m);
		ans -= (k % 3 == 0) ? k / 3 : k / 3 + 1;
	}
	printf("%d", ans);
	return 0;
}