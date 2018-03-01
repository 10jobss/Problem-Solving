/*
Problem : https://www.acmicpc.net/problem/11066
Author: 10jobss
Time complexity: O(N^3)
solution :
	d[i][j] = i번째 파일부터 j번째 파일을 합쳤을 때 최소 비용
	합친 비용이 계속 누적되는 방식이라서 문제를 제대로 읽어야 했음
	state cost - 누적 비용, now - 합쳐진 파일의 최종 상태 
	ex) 10 20 30 파일이 있을 때 0,1,2 순으로 차례대로 파일을 합친다고하면
	(cost, now) 변화는
	(0,10) --> (30,30) --> (90,60)
	가장 안쪽 for문에서 (i+k, j)의 경우 고려할 필요없음
*/
#include <cstdio>
#include <algorithm>
#define MAX 500
#define INF 987654321
using namespace std;
typedef struct state {
	int cost, now;
}STATE;
int a[MAX];
STATE d[MAX][MAX];
void _init(int nn) {
	int i, j;
	for (i = 0; i < nn; i++) {
		for (j = 0; j < nn; j++) {
			d[i][j].cost = INF;
			d[i][j].now = 0;
		}
	}
}
int main() {
	int tc, n, i, j, k;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		_init(n);
		for (i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			d[i][i].cost = 0, d[i][i].now = a[i];
		}
		for (i = 0; i < n - 1; i++) {
			d[i][i + 1].cost = d[i][i + 1].now = a[i] + a[i + 1];
		}
		for (j = 2; j < n; j++) {
			for (i = j - 1; i >= 0; i--) {
				for (k = 1; k <= j; k++) {
					if (d[i][j].cost > d[i][j - k].cost + d[j - k + 1][j].cost + d[i][j - k].now + d[j - k + 1][j].now) {
						d[i][j].cost = d[i][j - k].cost + d[j - k + 1][j].cost + d[i][j - k].now + d[j - k + 1][j].now;
						d[i][j].now = d[i][j - k].now + d[j - k + 1][j].now;
					}
				}
			}
		}
		printf("%d\n", d[0][n - 1].cost);
	}
	return 0;
}