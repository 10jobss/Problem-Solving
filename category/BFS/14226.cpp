/*
problem : https://www.acmicpc.net/problem/14226
solution :
	(많은 TLE, RTE, 메모리초과..) 쉬운 문제인데 왜 이유는 모르겠음
	화면 이모티콘 수 : x, 클립보드 이모티콘 수 : y
	x, y의 상태를 check해서 중복된 상태가 enqueue 되지 않도록 처리
	{x,y} --> {x-1, y}, {x, x}, {x+y, y} 로 이동할 수 있음
	각 경우에서 이동할 필요가 없는 경우 1) x==y일 때 {x, x} 2) y==0일 때 {x+y, y}
	{x-1, y}의 경우 처리를 x-1>s일 때 WA, x-1>2 AC... 감으로 풀었음
	맞아도 논리적으로 설명을 못하겠음 (다시 풀어볼 것)
*/
#include <cstdio>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int s, q_size, depth;
bool flag, chk[1001][1001];
queue<pii> q;
int main() {
	scanf("%d", &s);
	chk[1][0] = true;
	q.push({ 1,0 });
	while (!q.empty()) {
		q_size = q.size();
		while (q_size--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (x == s) {
				flag = true;
				break;
			}
			if (x != y && !chk[x][x]) {
				chk[x][x] = true;
				q.push({ x,x });
			}
			if (y && x + y <= s && !chk[x + y][y]) {
				chk[x + y][y] = true;
				q.push({ x + y,y });
			}
			if (x - 1 > 2 && !chk[x - 1][y]) {
				chk[x - 1][y] = true;
				q.push({ x - 1,y });
			}
		}
		if (flag) break;
		depth++;
	}
	printf("%d", depth);
	return 0;
}