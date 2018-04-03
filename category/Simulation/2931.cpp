/*
Problem : https://www.acmicpc.net/problem/2931
Author: 10jobss
Time complexity: O(R^2 * C^2) ???
solution :
	�־��� ���Ǵ�� �����ؾ� �ϴ� ����
	������ ������ �־ �򰥷ȴ�
	<�����Խñ� �亯>
	"Block '+' is special in that gas must flow in two directions (one vertical, one horizontal)"

	'.'�� ���� 7���� ���� �־�鼭 ���� ���̽����� Ȯ���ߴ�
	������ ���� ��� ���� ���Ǿ�� �Ѵٴ� ��.

	��� Ʋ���ٰ� '+'���� �� �ڷ� �ٲٴϱ� AC �޾Ҵ�
	R*C ��ǥ�� ���ؼ� DFS Ȯ���ϴ� O(R^2 * C^2)�̶�� ����?�ߴ�

	Ž���ϴ� �߰��� ����� ��� Ȯ���ϴ� �������� �ٽ� Ǯ� ��
*/
#include <cstdio>
#include <cstring>
int r, c;
int Y, X;
int sy, sx;
char ans;
char p[7] = { '|','-','1','2','3','4','+' };
char a[25][25];
bool chk[25][25]; // ��� ���� �� ������?
int dy[4] = { -1,0,1,0 }; // �� �� �� ��
int dx[4] = { 0,1,0,-1 };
inline bool bnd(int &y, int &x) {
	return y >= 0 && y < r&&x >= 0 && x < c;
}
bool pp() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if ((a[i][j] >= '1'&&a[i][j] <= '4') ||
				a[i][j] == '|' || a[i][j] == '-' || a[i][j] == '+')
				if (!chk[i][j]) return 0;
		}
	}
	return 1;
}
bool dfs(int y, int x, int dir) { // (y,x)�� dir �������� ������ ���
	//printf("y = %d  x = %d  dir = %d\n", y, x, dir);
	if (a[y][x] == 'Z') {
		if (pp()) return 1;
		else return 0;
	}
	bool ret = 0;
	if (a[y][x] == 'M') { // 4������ ��� ����ؾ� ��
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!bnd(ny, nx)) continue;
			if (a[ny][nx] == '.') continue;
			if (i == 0) { // ��
				if (a[ny][nx] == 'Z' || a[ny][nx] == '|' || a[ny][nx] == '+' || 
					a[ny][nx] == '1' || a[ny][nx] == '4') {
					ret = dfs(ny, nx, i);
				}
			}
			else if (i == 1) { // ��
				if (a[ny][nx] == 'Z' || a[ny][nx] == '-' || a[ny][nx] == '+' ||
					a[ny][nx] == '3' || a[ny][nx] == '4') {
					ret = dfs(ny, nx, i);
				}
			}
			else if (i == 2) { // ��
				if (a[ny][nx] == 'Z' || a[ny][nx] == '|' || a[ny][nx] == '+' ||
					a[ny][nx] == '2' || a[ny][nx] == '3') {
					ret = dfs(ny, nx, i);
				}
			}
			else if (i == 3) { // ��
				if (a[ny][nx] == 'Z' || a[ny][nx] == '-' || a[ny][nx] == '+' ||
					a[ny][nx] == '1' || a[ny][nx] == '2') {
					ret = dfs(ny, nx, i);
				}
			}
		}
	}
	// ���� ���� �״�� ������ ���
	else if (a[y][x] == '|') {
		chk[y][x] = 1;
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (!bnd(ny, nx)) return 0;
		if (a[ny][nx] == '.') return 0;
		if (dir == 0) {
			if (a[ny][nx] == '-' || a[ny][nx] == '2' || a[ny][nx] == '3') return 0;
			ret = dfs(ny, nx, dir);
		}
		else if (dir == 2) {
			if (a[ny][nx] == '-' || a[ny][nx] == '1' || a[ny][nx] == '4') return 0;
			ret = dfs(ny, nx, dir);
		}
	}
	else if (a[y][x] == '-') {
		chk[y][x] = 1;
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (!bnd(ny, nx)) return 0;
		if (a[ny][nx] == '.') return 0;
		if (dir == 1) {
			if (a[ny][nx] == '|' || a[ny][nx] == '1' || a[ny][nx] == '2') return 0;
			ret = dfs(ny, nx, dir);
		}
		else if (dir == 3) {
			if (a[ny][nx] == '|' || a[ny][nx] == '3' || a[ny][nx] == '4') return 0;
			ret = dfs(ny, nx, dir);
		}
	}
	else if (a[y][x] == '+') {
		chk[y][x] = 1;
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (!bnd(ny, nx)) return 0;
		if (a[ny][nx] == '.') return 0;
		if (dir == 0) {
			if (a[ny][nx] == '-' || a[ny][nx] == '2' || a[ny][nx] == '3') return 0;
			ret = dfs(ny, nx, dir);
		} 
		else if (dir == 1) {
			if (a[ny][nx] == '|' || a[ny][nx] == '1' || a[ny][nx] == '2') return 0;
			ret = dfs(ny, nx, dir);
		}
		else if (dir == 2) {
			if (a[ny][nx] == '-' || a[ny][nx] == '1' || a[ny][nx] == '4') return 0;
			ret = dfs(ny, nx, dir);
		}
		else if (dir == 3) {
			if (a[ny][nx] == '|' || a[ny][nx] == '3' || a[ny][nx] == '4') return 0;
			ret = dfs(ny, nx, dir);
		}
	}
	// ������ ��찡 ������ �������� ���
	else if (a[y][x] == '1') {
		chk[y][x] = 1;
		int ndir = dir == 0 ? 1 : 2;
		int ny = y + dy[ndir];
		int nx = x + dx[ndir];
		if (!bnd(ny, nx)) return 0;
		if (a[ny][nx] == '.') return 0;
		if (ndir == 1) {
			if (a[ny][nx] == '|' || a[ny][nx] == '1' || a[ny][nx] == '2') return 0;
			ret = dfs(ny, nx, ndir);
		}
		else if (ndir == 2) {
			if (a[ny][nx] == '-' || a[ny][nx] == '1' || a[ny][nx] == '4') return 0;
			ret = dfs(ny, nx, ndir);
		}
	}
	else if (a[y][x] == '2') {
		chk[y][x] = 1;
		int ndir = dir == 2 ? 1 : 0;
		int ny = y + dy[ndir];
		int nx = x + dx[ndir];
		if (!bnd(ny, nx)) return 0;
		if (a[ny][nx] == '.') return 0;
		if (ndir == 1) {
			if (a[ny][nx] == '|' || a[ny][nx] == '1' || a[ny][nx] == '2') return 0;
			ret = dfs(ny, nx, ndir);
		}
		else if (ndir == 0) {
			if (a[ny][nx] == '-' || a[ny][nx] == '2' || a[ny][nx] == '3') return 0;
			ret = dfs(ny, nx, ndir);
		}
	}
	else if (a[y][x] == '3') {
		chk[y][x] = 1;
		int ndir = dir == 2 ? 3 : 0;
		int ny = y + dy[ndir];
		int nx = x + dx[ndir];
		if (!bnd(ny, nx)) return 0;
		if (a[ny][nx] == '.') return 0;
		if (ndir == 3) {
			if (a[ny][nx] == '|' || a[ny][nx] == '3' || a[ny][nx] == '4') return 0;
			ret = dfs(ny, nx, ndir);
		}
		else if (ndir == 0) {
			if (a[ny][nx] == '-' || a[ny][nx] == '2' || a[ny][nx] == '3') return 0;
			ret = dfs(ny, nx, ndir);
		}
	}
	else if (a[y][x] == '4') {
		chk[y][x] = 1;
		int ndir = dir == 1 ? 2 : 3;
		int ny = y + dy[ndir];
		int nx = x + dx[ndir];
		if (!bnd(ny, nx)) return 0;
		if (a[ny][nx] == '.') return 0;
		if (ndir == 2) {
			if (a[ny][nx] == '-' || a[ny][nx] == '1' || a[ny][nx] == '4') return 0;
			ret = dfs(ny, nx, ndir);
		}
		else if (ndir == 3) {
			if (a[ny][nx] == '|' || a[ny][nx] == '3' || a[ny][nx] == '4') return 0;
			ret = dfs(ny, nx, ndir);
		}
	}
	return ret;
}
void solve() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (a[i][j] == '.') {
				//printf("%d, %d block\n", i, j);
				for (int k = 0; k < 7; k++) {
					memset(chk, 0, sizeof(chk));
					a[i][j] = p[k];
					if (dfs(sy, sx, -1)) {
						Y = i;
						X = j;
						ans = p[k];
						return;
					}
				}
				a[i][j] = '.';
			}
		}
	}
}
int main() {
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf(" %c", &a[i][j]);
			if (a[i][j] == 'M') {
				sy = i, sx = j;
			}
		}
	}
	solve();
	printf("%d %d %c", Y + 1, X + 1, ans);
	return 0;
}