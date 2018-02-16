/*
Problem : https://www.acmicpc.net/problem/1753
Author: 10jobss
Time complexity: O(N*M)
solution :
	��� ��츦 �� �غ� �� �ۿ� ���� ����
	�»���� ��ǥ�� (i,j)�� �ϴ� 8*8 ü���ǿ� ���� ������ �ּҸ� ���Ѵ�
	(i,j) ---- (i,j+7)
	  |
	  |
	(i+7,j)
	cmp �Լ����� a �迭�� index �򰥸� �� ������ ����
	���� ü������ ũ�Ⱑ 8*8�� �ƴ� x*y�̸� �ð����⵵�� O(N*M*X*Y)
	https://www.acmicpc.net/board/view/22401
*/

#include <cstdio>
#include <algorithm>
#define INF 987654321
using namespace std;
int n, m, ans = INF;
char a[50][50];
char p1[8][8] = { {'W','B','W','B','W','B','W','B'},
				  {'B','W','B','W','B','W','B','W' },
				  { 'W','B','W','B','W','B','W','B' },
				  { 'B','W','B','W','B','W','B','W' },
				  { 'W','B','W','B','W','B','W','B' },
				  { 'B','W','B','W','B','W','B','W' },
				  { 'W','B','W','B','W','B','W','B' },
				  { 'B','W','B','W','B','W','B','W' } };

char p2[8][8] = { { 'B','W','B','W','B','W','B','W' },
				  { 'W','B','W','B','W','B','W','B' },
				  { 'B','W','B','W','B','W','B','W' },
				  { 'W','B','W','B','W','B','W','B' },
				  { 'B','W','B','W','B','W','B','W' },
				  { 'W','B','W','B','W','B','W','B' },
				  { 'B','W','B','W','B','W','B','W' },
				  { 'W','B','W','B','W','B','W','B' } };
bool chk(int y, int x) {
	if (y + 7 >= n || x + 7 >= m) return false;
	return true;
}
int cmp(int y, int x) {
	int i, j, ret1 = 0, ret2 = 0;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (a[i + y][j + x] != p1[i][j]) ret1++;
			if (a[i + y][j + x] != p2[i][j]) ret2++;
		}
	}
	return min(ret1, ret2);
}
int main() {
	scanf("%d%d", &n, &m);
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) scanf(" %c", &a[i][j]);
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (chk(i, j)) {
				ans = min(ans, cmp(i, j));
			}
		}
	}
	printf("%d", ans);
	return 0;
}