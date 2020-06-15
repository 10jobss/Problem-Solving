/*
Problem : https://www.acmicpc.net/problem/15565
Author: 10jobss
Time complexity: O(N)
solution :
	ó������ DP�ΰ� ���������� Two Pointer�� Ǯ �� �־���.
	���̾� ������ K�� �̻��̶�� ������ ��Ȯ�� K���� �����ϸ� ����.
	�� ������ ���� ���� ���ӵ� �������� ���� ũ�⸦ ���ϴ� ���̹Ƿ�
	K�� �̻� ���ʹ� ��� �����̵� �߰��� ������ ����̴�.

	�� ��ü ���̾� ������ K�� �̸��� ��� -1�� ����ϵ��� �ߴ�.
*/

#include <cstdio>
#define MAX (int)1e6
int a[MAX];
int main() {
	int i, n, k, ans, cnt = 0, left = 0, right = 0;
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 1) cnt++;
	}
	if (cnt < k) {
		printf("-1");
		return 0;
	}
	cnt = 0, ans = n;
	while (1) {
		if (cnt >= k) {
			ans = ans > right - left ? right - left : ans;
			if (a[left] == 1) cnt--;
			left++;
		}
		else if (right == n) {
			break;
		}
		else {
			if (a[right] == 1) cnt++;
			right++;
		}
	}
	printf("%d", ans);
	return 0;
}