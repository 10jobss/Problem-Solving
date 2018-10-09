/*
Problem : https://icpc.me/2240
Author: 10jobss
Time complexity: O(T*W)
solution :
	d[t][w][i]
	-> t�ʿ� w�� �̵����� �� i+1��° (�� i=0,1) ������ ��ġ���� ��
	   ���� �� �ִ� �ִ� �ڵ��� ����
	������ �켱������ ��������
	ĳ���� �� max( )..+a[i]==1 ��� +�����ڰ� ==�����ں��� �켱������ ���� ������
	ĳ���� �� 0�Ǵ� 1 �� �ۿ� ������ �ȵȴ�
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