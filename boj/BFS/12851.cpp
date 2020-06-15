/*
problem : https://www.acmicpc.net/problem/12851
solution :
	https://www.acmicpc.net/problem/1697 에서 살짝 변형된 문제
	1697번은 최단시간을 바로 찾으면 탐색 종료해도 되지만
	12851번 같은 경우 경우의 수도 따져야 하므로 탐색 종료할 수 없음

	1차 구현 - 시도했던 방법은 연산 종류, 위치를 node로 정의
	노드가 -1 연산결과 왔으면 다음 탐색 시 +1은 할 필요없고 (제자리로 돌아가니까 이런 경우는 최단 시간 X)
	+1이면 -1을 탐색할 필요가 없고 cur > k이면 cur*2 할 필요없고.... 끝도 없음
	if, else 문 너무 많아져서 cutting 많이 했지만 메모리 초과, TLE 반복..

	2차 구현 - 단순 visit을 이용하면 구현 못하므로 visit배열을 depth를 이용해서 생각
	해당 정점의 저장된 depth와 부모 depth + 1을 비교해서 depth가 낮거나 '같은'(이 경우를 조심!) enqueue
	depth를 INF로 초기화 하는 것이 중요했음 depth보다 큰 경우 더 이상 탐색할 필요가 없기 때문
	(k를 방문했든 안했든 상관없이)
	*2, +1 할 경우 MAX 범위를 check 해야지 RTE가 안남 (고려안해서 2번이나 RTE)
	MAX를 2*10^5한 이유는 k=10^5 일때 MAX를 넘어가면 k 보다 큰 쪽에서 오는 경우는 없기 때문
*/
#include <cstdio>
#include <queue>
#include <algorithm>
#define MAX (int)2e+5
#define INF 987654321
using namespace std;
int n, k, depth = INF, c, d[MAX + 1];
queue<int> q;
int main() {
	scanf("%d%d", &n, &k);
	if (n >= k) {
		printf("%d\n1", n - k);
		return 0;
	}
	fill(d, d + MAX, INF);
	q.push(n);
	d[n] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == k) {
			depth = d[cur];
			c++;
			continue;
		}
		if (d[cur] > depth) continue;
		if (cur - 1 >= 0 && d[cur - 1] >= d[cur] + 1) {
			d[cur - 1] = d[cur] + 1;
			q.push(cur - 1);
		}
		if (cur + 1 <= MAX && d[cur + 1] >= d[cur] + 1) {
			d[cur + 1] = d[cur] + 1;
			q.push(cur + 1);
		}
		if (2 * cur <= MAX && d[2 * cur] >= d[cur] + 1) {
			d[2 * cur] = d[cur] + 1;
			q.push(2 * cur);
		}
	}
	printf("%d\n%d", depth, c);
	return 0;
}
