/*
Problem : https://www.acmicpc.net/problem/2931
Author: 10jobss
Time complexity: O(R^2 * C^2) ???
solution :
	주어진 조건대로 구현해야 하는 문제
	문제에 오역이 있어서 헷갈렸다
	<질문게시글 답변>
	"Block '+' is special in that gas must flow in two directions (one vertical, one horizontal)"

	'.'인 곳에 7가지 블럭을 넣어보면서 성공 케이스인지 확인했다
	주의할 점은 모든 블럭이 사용되어야 한다는 점.

	계속 틀리다가 '+'블럭을 맨 뒤로 바꾸니까 AC 받았다
	R*C 좌표에 대해서 DFS 확인하니 O(R^2 * C^2)이라고 추측?했다

	탐색하다 중간에 끊기는 경우 확인하는 로직으로 다시 풀어볼 것
*/
#include <cstdio>
#include <cstring>
int r, c;
int Y, X;
int sy, sx;
char ans;
char p[7] = { '|','-','1','2','3','4','+' };
char a[25][25];
bool chk[25][25]; // 모든 관이 다 쓰였나?
int dy[4] = { -1,0,1,0 }; // 북 동 남 서
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
bool dfs(int y, int x, int dir) { // (y,x)에 dir 방향으로 진입한 경우
	//printf("y = %d  x = %d  dir = %d\n", y, x, dir);
	if (a[y][x] == 'Z') {
		if (pp()) return 1;
		else return 0;
	}
	bool ret = 0;
	if (a[y][x] == 'M') { // 4방향을 모두 고려해야 함
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!bnd(ny, nx)) continue;
			if (a[ny][nx] == '.') continue;
			if (i == 0) { // 북
				if (a[ny][nx] == 'Z' || a[ny][nx] == '|' || a[ny][nx] == '+' || 
					a[ny][nx] == '1' || a[ny][nx] == '4') {
					ret = dfs(ny, nx, i);
				}
			}
			else if (i == 1) { // 동
				if (a[ny][nx] == 'Z' || a[ny][nx] == '-' || a[ny][nx] == '+' ||
					a[ny][nx] == '3' || a[ny][nx] == '4') {
					ret = dfs(ny, nx, i);
				}
			}
			else if (i == 2) { // 남
				if (a[ny][nx] == 'Z' || a[ny][nx] == '|' || a[ny][nx] == '+' ||
					a[ny][nx] == '2' || a[ny][nx] == '3') {
					ret = dfs(ny, nx, i);
				}
			}
			else if (i == 3) { // 서
				if (a[ny][nx] == 'Z' || a[ny][nx] == '-' || a[ny][nx] == '+' ||
					a[ny][nx] == '1' || a[ny][nx] == '2') {
					ret = dfs(ny, nx, i);
				}
			}
		}
	}
	// 진입 방향 그대로 나가는 경우
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
	// 나가는 경우가 무조건 정해지는 경우
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