/*
Problem : https://www.acmicpc.net/problem/13460
Author: 10jobss
Time complexity: ?????
solution :
	BFS 탐색으로 모든 경우의 수를 확인한다
	코드만 길지 사실 어려운 문제는 아니다 구현이 조~금? 귀찮은 정도
	논리가 중요했던 문제인것 같다

	상,하,좌,우로 맵을 기울일 수 있는데 문제는
	빨간공을 먼저 이동하고 파란공을 이동한다고 생각했는데
	이동하려는 방향에 파란공이 먼저있는 경우 다시 빨간공을 고려해야 했다
	예를들어 왼쪽으로 이동하려 할때   ..B...R.. 같은 경우
	R을 고려하고 B를 고려하면   B..R.....가 되서 R을 한번더 이동시켜야 한다
	그래서 다시 이동할 때는 바뀐 위치가 초기 위치여야 하므로 이부분도 신경써야 했다

	이런 문제는 처음에 정확히 생각안하면 시간을 너무 잡아먹을 것 같다
	2시간 20분 정도 걸림 (그래서 코드가 더럽다)
	첫 제출에 ans>10이라고 해서 WA
	이걸 바로 찾아서 AC 받았다
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef vector<vector<char> > vvc;
int n, m, ans;
int ry, rx, by, bx; // 처음 입력 받을 때 공 위치
vvc a;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
bool flag;
bool chk[20][20][20][20];
void bfs() {
	queue<vvc > q;
	chk[ry][rx][by][bx] = 1;
	q.push(a);
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			vvc cur = q.front();
			q.pop();
			bool gr, gb; // 각 공이 나왔는지
			int ryy, rxx, byy, bxx; // 이 변수들로 좌표 움직임
			int RY, RX, BY, BX; // 해당 depth에서 맨 처음 공 위치
			int cry, crx, cby, cbx; // 만약 파란공이 앞서서 빨간공을 다시 고려할 경우 처음 위치
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (cur[i][j] == 'R') RY = i, RX = j;
					else if (cur[i][j] == 'B') BY = i, BX = j;
				}
			}
			vvc left = cur;
			gr = 0, gb = 0;
			ryy = RY, rxx = RX, byy = BY, bxx = BX;
			while (1) {
				ryy += dy[3], rxx += dx[3];
				if (left[ryy][rxx] == '.') continue;
				else if (left[ryy][rxx] == '#') break;
				else if (left[ryy][rxx] == 'B') break;
				else if (left[ryy][rxx] == 'O') { gr = 1; break; }
			}
			if (!gr) swap(left[RY][RX], left[ryy - dy[3]][rxx - dx[3]]);
			else left[RY][RX] = '.';
			while (1) {
				byy += dy[3], bxx += dx[3];
				if (left[byy][bxx] == '.') continue;
				else if (left[byy][bxx] == '#') break;
				else if (left[byy][bxx] == 'R') break;
				else if (left[byy][bxx] == 'O') { gb = 1; break; }
			}
			if (gr && !gb) { flag = true; break; }
			if (!gb) swap(left[BY][BX], left[byy - dy[3]][bxx - dx[3]]);
			if (!gr && !gb) {
				cry = ryy -= dy[3], crx = rxx -= dx[3];
				while (1) {
					ryy += dy[3], rxx += dx[3];
					if (left[ryy][rxx] == '.') continue;
					else if (left[ryy][rxx] == '#') break;
					else if (left[ryy][rxx] == 'B') break;
					else if (left[ryy][rxx] == 'O') { gr = 1; break; }
				}
				if (!gr) swap(left[cry][crx], left[ryy - dy[3]][rxx - dx[3]]);
				else { flag = true; break; }
			}
			if (!gr && !gb && !chk[ryy - dy[3]][rxx - dx[3]][byy - dy[3]][bxx - dx[3]]) {
				chk[ryy - dy[3]][rxx - dx[3]][byy - dy[3]][bxx - dx[3]] = 1;
				q.push(left);
			}
			vvc right = cur;
			gr = 0, gb = 0;
			ryy = RY, rxx = RX, byy = BY, bxx = BX;
			while (1) {
				ryy += dy[1], rxx += dx[1];
				if (right[ryy][rxx] == '.') continue;
				else if (right[ryy][rxx] == '#') break;
				else if (right[ryy][rxx] == 'B') break;
				else if (right[ryy][rxx] == 'O') { gr = 1; break; }
			}
			if (!gr) swap(right[RY][RX], right[ryy - dy[1]][rxx - dx[1]]);
			else right[RY][RX] = '.';
			while (1) {
				byy += dy[1], bxx += dx[1];
				if (right[byy][bxx] == '.') continue;
				else if (right[byy][bxx] == '#') break;
				else if (right[byy][bxx] == 'R') break;
				else if (right[byy][bxx] == 'O') { gb = 1; break; }
			}
			if (gr && !gb) { flag = true; break; }
			if (!gb) swap(right[BY][BX], right[byy - dy[1]][bxx - dx[1]]);
			if (!gr && !gb) {
				cry = ryy -= dy[1], crx = rxx -= dx[1];
				while (1) {
					ryy += dy[1], rxx += dx[1];
					if (right[ryy][rxx] == '.') continue;
					else if (right[ryy][rxx] == '#') break;
					else if (right[ryy][rxx] == 'B') break;
					else if (right[ryy][rxx] == 'O') { gr = 1; break; }
				}
				if (!gr) swap(right[cry][crx], right[ryy - dy[1]][rxx - dx[1]]);
				else { flag = true; break; }
			}
			if (!gr && !gb && !chk[ryy - dy[1]][rxx - dx[1]][byy - dy[1]][bxx - dx[1]]) {
				chk[ryy - dy[1]][rxx - dx[1]][byy - dy[1]][bxx - dx[1]] = 1;
				q.push(right);
			}
			vvc up = cur;
			gr = 0, gb = 0;
			ryy = RY, rxx = RX, byy = BY, bxx = BX;
			while (1) {
				ryy += dy[0], rxx += dx[0];
				if (up[ryy][rxx] == '.') continue;
				else if (up[ryy][rxx] == '#') break;
				else if (up[ryy][rxx] == 'B') break;
				else if (up[ryy][rxx] == 'O') { gr = 1; break; }
			}
			if (!gr) swap(up[RY][RX], up[ryy - dy[0]][rxx - dx[0]]);
			else up[RY][RX] = '.';
			while (1) {
				byy += dy[0], bxx += dx[0];
				if (up[byy][bxx] == '.') continue;
				else if (up[byy][bxx] == '#') break;
				else if (up[byy][bxx] == 'R') break;
				else if (up[byy][bxx] == 'O') { gb = 1; break; }
			}
			if (gr && !gb) { flag = true; break; }
			if (!gb) swap(up[BY][BX], up[byy - dy[0]][bxx - dx[0]]);
			if (!gr && !gb) {
				cry = ryy -= dy[0], crx = rxx -= dx[0];
				while (1) {
					ryy += dy[0], rxx += dx[0];
					if (up[ryy][rxx] == '.') continue;
					else if (up[ryy][rxx] == '#') break;
					else if (up[ryy][rxx] == 'B') break;
					else if (up[ryy][rxx] == 'O') { gr = 1; break; }
				}
				if (!gr) swap(up[cry][crx], up[ryy - dy[0]][rxx - dx[0]]);
				else { flag = true; break; }
			}
			if (!gr && !gb && !chk[ryy - dy[0]][rxx - dx[0]][byy - dy[0]][bxx - dx[0]]) {
				chk[ryy - dy[0]][rxx - dx[0]][byy - dy[0]][bxx - dx[0]] = 1;
				q.push(up);
			}
			vvc down = cur;
			gr = 0, gb = 0;
			ryy = RY, rxx = RX, byy = BY, bxx = BX;
			while (1) {
				ryy += dy[2], rxx += dx[2];
				if (down[ryy][rxx] == '.') continue;
				else if (down[ryy][rxx] == '#') break;
				else if (down[ryy][rxx] == 'B') break;
				else if (down[ryy][rxx] == 'O') { gr = 1; break; }
			}
			if (!gr) swap(down[RY][RX], down[ryy - dy[2]][rxx - dx[2]]);
			else down[RY][RX] = '.';
			while (1) {
				byy += dy[2], bxx += dx[2];
				if (down[byy][bxx] == '.') continue;
				else if (down[byy][bxx] == '#') break;
				else if (down[byy][bxx] == 'R') break;
				else if (down[byy][bxx] == 'O') { gb = 1; break; }
			}
			if (gr && !gb) { flag = true; break; }
			if (!gb) swap(down[BY][BX], down[byy - dy[2]][bxx - dx[2]]);
			if (!gr && !gb) {
				cry = ryy -= dy[2], crx = rxx -= dx[2];
				while (1) {
					ryy += dy[2], rxx += dx[2];
					if (down[ryy][rxx] == '.') continue;
					else if (down[ryy][rxx] == '#') break;
					else if (down[ryy][rxx] == 'B') break;
					else if (down[ryy][rxx] == 'O') { gr = 1; break; }
				}
				if (!gr) swap(down[cry][crx], down[ryy - dy[2]][rxx - dx[2]]);
				else { flag = true; break; }
			}
			if (!gr && !gb && !chk[ryy - dy[2]][rxx - dx[2]][byy - dy[2]][bxx - dx[2]]) {
				chk[ryy - dy[2]][rxx - dx[2]][byy - dy[2]][bxx - dx[2]] = 1;
				q.push(down);
			}
		}
		ans++;
		if (flag) break;
		if (ans >= 10) { flag = false; break; }
	}
}
int main() {
	scanf("%d%d", &n, &m);
	a.resize(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &a[i][j]);
			if (a[i][j] == 'R') ry = i, rx = j;
			else if (a[i][j] == 'B') by = i, bx = j;
		}
	}
	bfs();
	printf("%d", flag ? ans : -1);
	return 0;
}