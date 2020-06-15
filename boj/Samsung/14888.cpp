/*
problem : https://www.acmicpc.net/problem/14888
solution :
	숫자는 고정, 연산자를 일렬로 나열하는 방법을 생각
	next_permutation을 사용하는 풀이 시작
	sum의 초기값을 v[0]로 해야지 for문이 맞아 떨어짐
	1차 제출 WA의 이유 : min, max 값을 잘못 설정, 습관적으로 987654321을 min, 0을 max 값으로 함
	문제의 설명에 연산도중 -10억 ~ 10억을 벗어나는 범위가 없다고 하여 수정
	DFS를 활용한 풀이도 있어서 다시 풀어보기
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX (int)1e+9
using namespace std;
int main() {
	int n, i, x, idx = 0, mx = -MAX, mn = MAX;
	scanf("%d", &n);
	vector<int> v(n), a(n - 1);
	for (i = 0; i < n; ++i) scanf("%d", &v[i]);
	for (i = 0; i < 4; ++i) { // 0 덧셈, 1 뺄셈, 2 곱셈 , 3 나눗셈
		scanf("%d", &x);
		while (x--) a[idx++] = i;
	}
	do {
		int sum = v[0];
		for (i = 0; i < n - 1; ++i) {
			switch (a[i]) {
			case 0:
				sum += v[i + 1];
				break;
			case 1:
				sum -= v[i + 1];
				break;
			case 2:
				sum *= v[i + 1];
				break;
			case 3:
				if (sum > 0) sum /= v[i + 1];
				else {
					sum = -sum;
					sum /= v[i + 1];
					sum = -sum;
				}
			}
		}
		mx = max(mx, sum), mn = min(mn, sum);
	} while (next_permutation(a.begin(), a.end()));
	printf("%d\n%d", mx, mn);
	return 0;
}