/*
Problem : https://www.acmicpc.net/problem/6064
Author: 10jobss
Time complexity: O(N)
solution :
	단순히 1씩 증가해서는 O(MN)이기 때문에 TLE 이다
	약간?의 트릭이 필요한데 x, y중 한가지 기준을 잡고 그 기준 싸이클만큼 확인해 주면 된다
	예를 들어 x, y 중 x를 기준이라고 하면 항상 x의 싸이클만(m)큼 증가시킨다
	초기 상태를 <x:x>, x번째 해라고 가정하고 반복문을 돌린다
	주의할 점은 y가 y의 한계인 n을 넘는지 초기에 확인해주어야 한다는 점
	cnt가 lcm을 넘어가면 그만 탐색한다
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
