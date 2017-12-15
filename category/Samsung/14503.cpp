#include <cstdio>
int N, M, sy, sx, dir, ans;
int adj[50][50];
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
void dfs(int y, int x, int d) {
	if (!adj[y][x]) adj[y][x] = 2, ans++;
	printf("%d %d (%d)\n", y, x, d);
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[(d + 3 - i) % 4];
		int nx = x + dx[(d + 3 - i) % 4];
		if (!adj[ny][nx]) {
			dfs(ny, nx, (d + 3 - i) % 4);
			return;
		}
	}
	int by = y + dy[(d + 2) % 4];
	int bx = x + dx[(d + 2) % 4];
	if (adj[by][bx] == 1) return;
	else dfs(by, bx, d);
}
int main() {
	scanf("%d%d%d%d%d", &N, &M, &sy, &sx, &dir);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) scanf("%d", &adj[i][j]);
	}
	dfs(sy, sx, dir);
	printf("%d", ans);
	return 0;
}
/*
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
const int _next[] = {3, 0, 1, 2};
const int _back[] = {2, 3, 0, 1};

int main() {
int N, M;
scanf("%d%d", &N, &M);

int R, C, D;
scanf("%d%d%d", &R, &C, &D);

int a[51][51];
for(int i=0; i < N; i++)
for(int j=0; j < M; j++)
scanf("%d", &a[i][j]);

int y = R;
int x = C;
int ans = 0;
while(true)
{
if(a[y][x] == 0)
{
ans++;
a[y][x] = 2;
}

bool find = false;
for(int i=0; i < 4; i++, D = _next[D])
{
int ny = y + dy[_next[D]];
int nx = x + dx[_next[D]];
if(a[ny][nx] == 0)
{
D = _next[D];
y = ny;
x = nx;
find = true;
break;
}
}

if(find)
continue;

int by = y + dy[_back[D]];
int bx = x + dx[_back[D]];

if(a[by][bx] == 2)
{
y = by;
x = bx;
}
else
break;


}

printf("%d", ans);
}
*/