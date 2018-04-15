#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int ans;
int n, m, r, c, l;
int a[50][50];
bool chk[50][50];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };
void _init() {
	ans = 1;
	memset(a, 0, sizeof(a));
	memset(chk, 0, sizeof(chk));
}
void input() {
	scanf("%d%d%d%d%d", &n, &m, &r, &c, &l);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
	}
}
void solve() {
	l--;
	queue<pii > q;
	chk[r][c] = 1;
	q.push(make_pair(r, c));
	while (l > 0) {
		l--;
		int qs = q.size();
		while (qs--) {
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop();
			switch (a[cy][cx]) {
			case 1:
				for (int i = 0; i < 4; i++) {
					int ny = cy + dy[i];
					int nx = cx + dx[i];
					if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
					if (!a[ny][nx] || chk[ny][nx]) continue;
					if (i == 0) {
						if (a[ny][nx] == 1 || a[ny][nx] == 2 || a[ny][nx] == 5 || a[ny][nx] == 6) {
							chk[ny][nx] = 1;
							q.push(make_pair(ny, nx));
							ans++;
						}
					}
					else if (i == 1) {
						if (a[ny][nx] == 1 || a[ny][nx] == 2 || a[ny][nx] == 4 || a[ny][nx] == 7) {
							chk[ny][nx] = 1;
							q.push(make_pair(ny, nx));
							ans++;
						}
					}
					else if (i == 2) {
						if (a[ny][nx] == 1 || a[ny][nx] == 3 || a[ny][nx] == 6 || a[ny][nx] == 7) {
							chk[ny][nx] = 1;
							q.push(make_pair(ny, nx));
							ans++;
						}
					}
					else if (i == 3) {
						if (a[ny][nx] == 1 || a[ny][nx] == 3 || a[ny][nx] == 4 || a[ny][nx] == 5) {
							chk[ny][nx] = 1;
							q.push(make_pair(ny, nx));
							ans++;
						}
					}
				}
				break;
			case 2:
				for (int i = 0; i < 4; i++) {
					int ny = cy + dy[i];
					int nx = cx + dx[i];
					if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
					if (!a[ny][nx] || chk[ny][nx]) continue;
					if (i == 0) {
						if (a[ny][nx] == 1 || a[ny][nx] == 2 || a[ny][nx] == 5 || a[ny][nx] == 6) {
							chk[ny][nx] = 1;
							q.push(make_pair(ny, nx));
							ans++;
						}
					}
					else if (i == 1) {
						if (a[ny][nx] == 1 || a[ny][nx] == 2 || a[ny][nx] == 4 || a[ny][nx] == 7) {
							chk[ny][nx] = 1;
							q.push(make_pair(ny, nx));
							ans++;
						}
					}
				}
				break;
			case 3:
				for (int i = 0; i < 4; i++) {
					int ny = cy + dy[i];
					int nx = cx + dx[i];
					if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
					if (!a[ny][nx] || chk[ny][nx]) continue;
					if (i == 2) {
						if (a[ny][nx] == 1 || a[ny][nx] == 3 || a[ny][nx] == 6 || a[ny][nx] == 7) {
							chk[ny][nx] = 1;
							q.push(make_pair(ny, nx));
							ans++;
						}
					}
					else if (i == 3) {
						if (a[ny][nx] == 1 || a[ny][nx] == 3 || a[ny][nx] == 4 || a[ny][nx] == 5) {
							chk[ny][nx] = 1;
							q.push(make_pair(ny, nx));
							ans++;
						}
					}
				}
				break;
			case 4:
				for (int i = 0; i < 4; i++) {
					int ny = cy + dy[i];
					int nx = cx + dx[i];
					if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
					if (!a[ny][nx] || chk[ny][nx]) continue;
					if (i == 0) {
						if (a[ny][nx] == 1 || a[ny][nx] == 2 || a[ny][nx] == 5 || a[ny][nx] == 6) {
							chk[ny][nx] = 1;
							q.push(make_pair(ny, nx));
							ans++;
						}
					}
					else if (i == 2) {
						if (a[ny][nx] == 1 || a[ny][nx] == 3 || a[ny][nx] == 6 || a[ny][nx] == 7) {
							chk[ny][nx] = 1;
							q.push(make_pair(ny, nx));
							ans++;
						}
					}
				}
				break;
			case 5:
				for (int i = 0; i < 4; i++) {
					int ny = cy + dy[i];
					int nx = cx + dx[i];
					if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
					if (!a[ny][nx] || chk[ny][nx]) continue;
					if (i == 1) {
						if (a[ny][nx] == 1 || a[ny][nx] == 2 || a[ny][nx] == 4 || a[ny][nx] == 7) {
							chk[ny][nx] = 1;
							q.push(make_pair(ny, nx));
							ans++;
						}
					}
					else if (i == 2) {
						if (a[ny][nx] == 1 || a[ny][nx] == 3 || a[ny][nx] == 6 || a[ny][nx] == 7) {
							chk[ny][nx] = 1;
							q.push(make_pair(ny, nx));
							ans++;
						}
					}
				}
				break;
			case 6:
				for (int i = 0; i < 4; i++) {
					int ny = cy + dy[i];
					int nx = cx + dx[i];
					if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
					if (!a[ny][nx] || chk[ny][nx]) continue;
					if (i == 1) {
						if (a[ny][nx] == 1 || a[ny][nx] == 2 || a[ny][nx] == 4 || a[ny][nx] == 7) {
							chk[ny][nx] = 1;
							q.push(make_pair(ny, nx));
							ans++;
						}
					}
					else if (i == 3) {
						if (a[ny][nx] == 1 || a[ny][nx] == 3 || a[ny][nx] == 4 || a[ny][nx] == 5) {
							chk[ny][nx] = 1;
							q.push(make_pair(ny, nx));
							ans++;
						}
					}
				}
				break;
			case 7:
				for (int i = 0; i < 4; i++) {
					int ny = cy + dy[i];
					int nx = cx + dx[i];
					if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
					if (!a[ny][nx] || chk[ny][nx]) continue;
					if (i == 0) {
						if (a[ny][nx] == 1 || a[ny][nx] == 2 || a[ny][nx] == 5 || a[ny][nx] == 6) {
							chk[ny][nx] = 1;
							q.push(make_pair(ny, nx));
							ans++;
						}
					}
					else if (i == 3) {
						if (a[ny][nx] == 1 || a[ny][nx] == 3 || a[ny][nx] == 4 || a[ny][nx] == 5) {
							chk[ny][nx] = 1;
							q.push(make_pair(ny, nx));
							ans++;
						}
					}
				}
			}
		}
	}
}
int main() {
	//setbuf(stdin, NULL);
	//freopen("input.txt", "r", stdin);
	int tc;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		_init();
		input();
		solve();
		printf("#%d %d\n", t, ans);
	}
	return 0;
}