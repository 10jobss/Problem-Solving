/*
Problem : https://www.acmicpc.net/problem/2503
Author: 10jobss
Time complexity: O(N)
solution :
	쿼리에 대해서 모든 숫자에 대해 스트라이크, 볼 갯수를 조사해야 한다
	1. 100,10,1의 자리에서 0이 존재하는 경우, 같은 숫자가 있는 경우 제외
	2. 각 쿼리마다 스트라이크, 볼 갯수 조사
	(여기서 연산자 우선순위 때문에 처음에 답이 0이 나왔음
	실전에서는 의심가면 괄호치는 방향으로)
	N번의 쿼리에 대해 [100,1000) 조사하므로 O(N*900) --> O(N)
*/
#include <stdio.h>
int a[1001];
int main() {
	int n, num, x, y, ans = 0;
	for (int i = 100; i<1000; i++) {
		if (i / 100 == (i % 100) / 10 || i / 100 == (i % 100) % 10 || (i % 100) / 10 == (i % 100) % 10
			|| i / 100 == 0 || (i % 100) % 10 == 0 || (i % 100) / 10 == 0) {
			a[i] = 1;
		}
	}
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d%d", &num, &x, &y);
		for (int i = 100; i<1000; i++) {
			if (a[i]) continue;
			int xx = 0, yy = 0;
			xx += (i / 100 == num / 100) + ((i % 100) / 10 == (num % 100) / 10) + ((i % 100) % 10 == (num % 100) % 10);
			yy += (i / 100 == (num % 100) / 10) + (i / 100 == (num % 100) % 10) + ((i % 100) / 10 == num / 100) +
				((i % 100) / 10 == (num % 100) % 10) + ((i % 100) % 10 == num / 100) + ((i % 100) % 10 == (num % 100) / 10);
			if (x != xx || y != yy) a[i] = 1;
		}
	}
	for (int i = 100; i<1000; i++) ans += a[i] == 0;
	printf("%d", ans);
	return 0;
}