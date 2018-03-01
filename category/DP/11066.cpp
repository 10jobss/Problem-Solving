/*
Problem : https://www.acmicpc.net/problem/11066
Author: 10jobss
Time complexity: O(N^3)
solution :
	d[i][j] = i��° ���Ϻ��� j��° ������ ������ �� �ּ� ���
	��ģ ����� ��� �����Ǵ� ����̶� ������ ����� �о�� ����
	state cost - ���� ���, now - ������ ������ ���� ���� 
	ex) 10 20 30 ������ ���� �� 0,1,2 ������ ���ʴ�� ������ ��ģ�ٰ��ϸ�
	(cost, now) ��ȭ��
	(0,10) --> (30,30) --> (90,60)
	���� ���� for������ (i+k, j)�� ��� ����� �ʿ����
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