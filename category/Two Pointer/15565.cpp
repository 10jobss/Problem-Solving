/*
Problem : https://www.acmicpc.net/problem/15565
Author: 10jobss
Time complexity: O(N)
solution :
	처음에는 DP인가 생각했지만 Two Pointer로 풀 수 있었다.
	라이언 인형이 K개 이상이라는 조건은 정확히 K개로 생각하면 쉽다.
	그 이유는 가장 작은 연속된 인형들의 집합 크기를 구하는 것이므로
	K개 이상 부터는 어느 인형이든 추가할 이유가 없어서이다.

	단 전체 라이언 인형이 K개 미만이 경우 -1을 출력하도록 했다.
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