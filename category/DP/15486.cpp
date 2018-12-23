/*
Problem : https://icpc.me/15486
Author: 10jobss
Time complexity: O(N)
solution :
  N이 크기 때문에 14501번과 같이 N^2으로 풀 수 없음
  개인적으로 dp문제는 처음부터 점화식을 찾으려 하기 보다는
  
  다음과 같은 흐름으로 생각했다
  1) 불필요한 탐색을 줄이자
  2) 어느 방향으로 나아갈 것인가 (i 이전의 문제(i-1..) 혹은 다음 문제들(i+1..))
  d[i] -> i일부터 일했을 때 얻을 수 있는 최대 이익
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAX 1500001
using namespace std;
int n, t[MAX], p[MAX], d[MAX];
int f(int k) {
	if (k>n) return 0;
	int &ret = d[k];
	if (ret != -1) return ret;
	ret = 0;
	if (k + t[k] <= n + 1) ret = p[k] + f(k + t[k]);
	ret = max(ret, f(k + 1));
	return ret;
}
int main() {
	memset(d, -1, sizeof(d));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", t + i, p + i);
	printf("%d", f(1));
	return 0;
}