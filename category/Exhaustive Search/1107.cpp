/*
problem : https://www.acmicpc.net/problem/1107
solution :
	고장난 버튼이 입력으로 주어져서 마땅한 방법이 떠오르지 않았음
	각 자리수를 확인하는 것은 예외가 너무 많고 로직이 맞지 않음
	숫자버튼을 1차례 (숫자를 이용해 해당 채널로 가면 또 다시 숫자를 누를 일이 없음) + 증감버튼 = 목표채널
	결론 : 모든 채널에 대해서 완전 탐색
	ans를 +, - 만으로 갔을 때 횟수로 초기화
	1. i 채널로 이동하고
	2. 그 번호에서 n까지 +, - 버튼으로 간다
	3. 숫자로 i 채널을 갈 수 있을 때 자릿수와 +, -로 i까지 갈 때 최소값을 tmp
	4. i 채널에서 n채널 까지 +, - 버튼을 갈 때의 횟수를 tmp에 더함
	1차 - WA, 갈 수 있는 번호 탐색을 500000까지 했기 때문
		  n == 500000일 때 고장난 번호에 따라 500000보다 더 큰 쪽에서 n으로 올 수 있기 때문
	최악의 경우 n == 500000 이고 4만 사용할 수 있을 때 4444444 --> 500000 이므로 MAX는 4444444
*/
#include <cstdio>
#include <algorithm>
#define MAX 4444444
using namespace std;
bool chk[10]; // false - normal, true - broken
int main() {
	int i, j, n, m, x;
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d", &x);
		chk[x] = true;
	}
	int ans = abs(n - 100);
	for (i = 0; i <= MAX; ++i) {
		if (!i) {
			if (!chk[i]) ans = min(ans, abs(i - n) + 1);
		}
		else {
			j = i;
			bool flag = true;
			int cnt = 0;
			for (; j > 0; cnt++, j /= 10) {
				if (chk[j % 10]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				int tmp = abs(i - 100) > cnt ? cnt : abs(i - 100);
				tmp += abs(i - n);
				ans = min(ans, tmp);
			}
		}
	}
	printf("%d", ans);
	return 0;
}
