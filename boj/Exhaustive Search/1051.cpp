/*
problem : https://www.acmicpc.net/problem/1051
solution :
	완전탐색
	DP인가? 생각했지만 아니었음
	최대길이부터 시작해서 꼭지점 범위를 확인, 발견하면 바로 break
*/
#include <cstdio>
int a[50][50];
int main() {
	int n, m, l;
	scanf("%d%d", &n, &m);
	l = n > m ? m : n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) scanf("%1d", &a[i][j]);
	}
	bool flag = false;
	for (; l > 0; l--) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (i + l - 1 < n && j + l - 1 < m) {
					if (a[i][j] == a[i][j + l - 1] && a[i][j + 1 - 1] == a[i + l - 1][j] && a[i + l - 1][j] == a[i + l - 1][j + l - 1]) {
						flag = true;
						break;
					}
				}
			}
			if (flag) break;
		}
		if (flag) break;
	}
	printf("%d", l*l);
	return 0;
}