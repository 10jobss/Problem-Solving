/*
Problem : https://www.acmicpc.net/problem/13460
Author: 10jobss
Time complexity: ?????
solution :
	BFS Ž������ ��� ����� ���� Ȯ���Ѵ�
	�ڵ常 ���� ��� ����� ������ �ƴϴ� ������ ��~��? ������ ����
	���� �߿��ߴ� �����ΰ� ����

	��,��,��,��� ���� ����� �� �ִµ� ������
	�������� ���� �̵��ϰ� �Ķ����� �̵��Ѵٰ� �����ߴµ�
	�̵��Ϸ��� ���⿡ �Ķ����� �����ִ� ��� �ٽ� �������� ����ؾ� �ߴ�
	������� �������� �̵��Ϸ� �Ҷ�   ..B...R.. ���� ���
	R�� ����ϰ� B�� ����ϸ�   B..R.....�� �Ǽ� R�� �ѹ��� �̵����Ѿ� �Ѵ�
	�׷��� �ٽ� �̵��� ���� �ٲ� ��ġ�� �ʱ� ��ġ���� �ϹǷ� �̺κе� �Ű��� �ߴ�

	�̷� ������ ó���� ��Ȯ�� �������ϸ� �ð��� �ʹ� ��Ƹ��� �� ����
	2�ð� 20�� ���� �ɸ� (�׷��� �ڵ尡 ������)
	ù ���⿡ ans>10�̶�� �ؼ� WA
	�̰� �ٷ� ã�Ƽ� AC �޾Ҵ�
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef vector<vector<char> > vvc;
int n, m, ans;
int ry, rx, by, bx; // ó�� �Է� ���� �� �� ��ġ
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
			bool gr, gb; // �� ���� ���Դ���
			int ryy, rxx, byy, bxx; // �� ������� ��ǥ ������
			int RY, RX, BY, BX; // �ش� depth���� �� ó�� �� ��ġ
			int cry, crx, cby, cbx; // ���� �Ķ����� �ռ��� �������� �ٽ� ����� ��� ó�� ��ġ
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