/*
Problem : https://www.acmicpc.net/problem/6064
Author: 10jobss
Time complexity: O(N)
solution :
	�ܼ��� 1�� �����ؼ��� O(MN)�̱� ������ TLE �̴�
	�ణ?�� Ʈ���� �ʿ��ѵ� x, y�� �Ѱ��� ������ ��� �� ���� ����Ŭ��ŭ Ȯ���� �ָ� �ȴ�
	���� ��� x, y �� x�� �����̶�� �ϸ� �׻� x�� ����Ŭ��ŭ ������Ų��
	�ʱ� ���¸� <x:x>, x��° �ض�� �����ϰ� �ݺ����� ������
	������ ���� x�� y�� �Ѱ��� n�� �Ѵ��� �ʱ⿡ Ȯ�����־�� �Ѵٴ� ��
	cnt�� lcm�� �Ѿ�� �׸� Ž���Ѵ�
*/
#include <cstdio>
int gcd(int a, int b) { return !b ? a : gcd(b, a%b); }
int lcm(int a, int b) { return (a*b) / gcd(a, b); }
int main() {
	int tc, m, n, x, y, ans;
	scanf("%d", &tc);
	while (tc--) {
		ans = -1;
		scanf("%d%d%d%d", &m, &n, &x, &y);
		int cnt = x, ty = x;
		int MAX = lcm(m, n);
		while (1) {
			if (cnt > MAX) break;
			while (ty > n) ty -= n;
			if (ty == y) {
				ans = cnt;
				break;
			}
			ty += m, cnt += m;
		}
		printf("%d\n", ans);
	}
	return 0;
}