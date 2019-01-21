/*
Problem : https://algospot.com/judge/problem/read/BOGGLE
Author: 10jobss
solution :
	1차 시도 : 완전탐색으로 시도 -> TLE
	2차 시도 : d[y][x][pos]의 상태를 가능(1), 불가능(0)으로 두고 품 -> TLE
	3차 시도 : 상태를 초기(-1), 가능(1), 불가능(0)으로 설정하고 품 -> AC
	dp를 이용해서 풀었다
	f(y,x,k,pos) -> (y,x)위치이고 k번 문자열의 pos번째 문자까지 동일할 때 k번 문자열을 만들 수 있는가?
	불가능한 경우도 바로 가지치기를 해줘야지 시간 내에 풀 수 있었다
*/
#include <cstdio>
#include <cstring>
char c[5][6];
char w[10][11];
int dy[8] = { 1,-1,0,0,-1,-1,1,1 };
int dx[8] = { 0,0,-1,1,-1,1,-1,1 };
int d[5][5][11];
int f(int y, int x, int k, int pos) {
	if (pos == strlen(w[k]) - 1) return 1;
	int &ret = d[y][x][pos];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i<8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && ny<5 && nx >= 0 && nx<5 && c[ny][nx] == w[k][pos + 1])
			ret = f(ny, nx, k, pos + 1);
		if (ret == 1) break;
	}
	return ret;
}
int main() {
	int tc, n;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		for (int i = 0; i<5; i++) scanf("%s", c[i]);
		scanf("%d", &n);
		for (int i = 0; i<n; i++) scanf("%s", w[i]);
		for (int k = 0; k<n; k++) {
			int flag = 0;
			memset(d, -1, sizeof(d));
			for (int i = 0; i<5; i++) {
				for (int j = 0; j<5; j++) {
					if (c[i][j] == w[k][0]) {
						flag = f(i, j, k, 0);
					}
					if (flag == 1) break;
				}
				if (flag == 1) break;
			}
			printf("%s %s\n", w[k], flag ? "YES" : "NO");
		}
	}
	return 0;
}