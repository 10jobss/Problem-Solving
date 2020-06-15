/*
Problem : https://www.acmicpc.net/problem/2875
Author: 10jobss
Time complexity: O(1)
solution :
	풀고나서 확인해보니 Greedy라는데 맞는 증명은 나중에 해야겠다

	1. 남학생, 여학생 각각 기준을 잡아 팀을 만들 때 최소값을 구한다
	2. 팀에 속하지 않은 학생 수를 구한다
	3. k 보다 작은 경우에 먼저 팀에 속하지 않은 학생으로 인턴을 채우고
	   나머지는 팀을 해체 시키면서 채운다
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