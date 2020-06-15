/*
Problem : https://icpc.me/2240
Author: 10jobss
Time complexity: O(T*W)
solution :
	d[t][w][i]
	-> t초에 w번 이동했을 때 i+1번째 (단 i=0,1) 나무에 위치했을 때
	   얻을 수 있는 최대 자두의 갯수
	연산자 우선순위를 주의하자
	캐싱할 때 max( )..+a[i]==1 경우 +연산자가 ==연산자보다 우선순위가 높기 때문에
	캐싱할 때 0또는 1 값 밖에 저장이 안된다
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000 + 1];
int d[1000 + 1][30 + 1][2];
int main() {
	int t, w;
	int ans = 0;
	scanf("%d%d", &t, &w);
	for (int i = 1; i <= t; i++)
		scanf("%d", a + i);
	d[1][0][0] = (a[1] == 1);
	d[1][1][1] = (a[1] == 2);
	for (int i = 2; i <= t; i++) {
		for (int j = 0; j <= w && j <= i; j++) {
			if (j) {
				d[i][j][0] = max(d[i - 1][j][0], d[i - 1][j - 1][1]) + (a[i] == 1);
				d[i][j][1] = max(d[i - 1][j][1], d[i - 1][j - 1][0]) + (a[i] == 2);
			}
			else {
				d[i][j][0] = d[i - 1][j][0] + (a[i] == 1);
				d[i][j][1] = d[i - 1][j][1] + (a[i] == 2);
			}
		}
	}
	for (int j = 0; j <= w; j++)
		ans = max(ans, max(d[t][j][0], d[t][j][1]));
	printf("%d", ans);
	return 0;
}