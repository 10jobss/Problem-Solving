/*
Problem : https://algospot.com/judge/problem/read/BOGGLE
Author: 10jobss
solution :
	1�� �õ� : ����Ž������ �õ� -> TLE
	2�� �õ� : d[y][x][pos]�� ���¸� ����(1), �Ұ���(0)���� �ΰ� ǰ -> TLE
	3�� �õ� : ���¸� �ʱ�(-1), ����(1), �Ұ���(0)���� �����ϰ� ǰ -> AC
	dp�� �̿��ؼ� Ǯ����
	f(y,x,k,pos) -> (y,x)��ġ�̰� k�� ���ڿ��� pos��° ���ڱ��� ������ �� k�� ���ڿ��� ���� �� �ִ°�?
	�Ұ����� ��쵵 �ٷ� ����ġ�⸦ ������� �ð� ���� Ǯ �� �־���
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