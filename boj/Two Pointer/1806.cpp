/*
Problem : https://www.acmicpc.net/problem/1806
Author: 10jobss
Time complexity: O(N)
solution :
	Two Pointer를 이용한 알고리즘
	완전탐색의 경우 N^2이기에 불가능한 문제
	문제를 잘 읽어야 했음 부분합이 "S 이상"인 경우
	주의해야 할 점은 항상 포함배제 관계를 염두해두어야 한다는 것
	[left, right) 임을 명심! 그래서 길이는 right - left 이다 (+1 안해줘도 됨)

	- 시간결과 관련 질문
	Q) 투포인터를 이용해서 풀었고 O(N) (N=10^5) 이라고 판단했습니다
	근데 맞은 시간을 보니 12ms더군요
	10^8 = 1s, ms = 10^-3s니까 N=10^6정도?였다는 의미인데 N=10^5이니까 10ms미만으로 결과가 나와야 하는 것 아닌가요?

	A) 그 정도면 O(N)이 맞아요
	시간잡도라는 걸 그렇게 시간이랑 직결시킬 수는 없어요
	일단 여러 가지 고려해야 할 것들이 있는데
	10만개의 수가 최대 다섯 자리까지 입력을 받는다면
	중간에 공백까지 60만자 정도의 입력을 받아야 되죠
	그리고 그걸 정수로 컨버트하는 시간도 필요하고요
	거기서 시간이 제일 많이 걸릴 거예요
	그리고 N = 10만이지만 루프가 도는 과정을 보면
	left와 right가 모두 0부터 시작해서 끝까지 진행하는 모습이죠
	그러면 대략 2배 정도가 들어가죠
	중간에 이런저런 연산들도 있고요
	그런데 아마 이런 것들보다도 앞서 말한 입력받는 시간이 제일 길어요 아마
*/
#include <cstdio>
int a[100000];
int main() {
	int i;
	int n, s, sum = 0, left = 0, right = 0, ans = 100001;
	scanf("%d%d", &n, &s);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	while (1) {
		if (sum >= s) {
			ans = ans > right - left ? right - left : ans;
			sum -= a[left++];
		}
		else if (right == n) break;
		else {
			sum += a[right++];
		}
	}
	ans == 100001 ? printf("0") : printf("%d", ans);
	return 0;
}
