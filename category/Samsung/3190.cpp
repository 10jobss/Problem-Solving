/*
Problem : https://www.acmicpc.net/problem/3190
Author: 10jobss
Time complexity: O(N*L)
solution :
	구현 문제 (헷갈리니 조심)
	처음에 생각은 DFS가 떠올랐음
	그런데 어차피 상태가 변하는 것은 뱀의 머리와 꼬리라서
	그 상태를 deque을 이용해서 푸는 것이 낫다고 생각함

	북, 동, 남, 서 순으로 방향을 할경우
	현재 바라보는 쪽을 dir이라 하면
	시계방향 90 회전은 (dir+1)%4, 반시계방향 90 회전은 (dir+3)%4로 표현 가능

	뱀이 위치한 곳은 true로 표시
	다음 칸에 사과가 있으면 pop_back() 할 필요없이 새 좌표를 push_front(), 사과 없애주고
	사과가 없다면 pop_back()하고 기존에 꼬리 자리를 false로 바꿔주고 새 좌표 push_front()

	시간복잡도는 while문이 결정하는데
	<djm03178님의 답변>
	10jobss [10:33 PM]
	deque을 이용해서 풀었고 제가 판단하기로는
	deque의 push&pop 연산이 O(1)이니까
	최악의 경우 (가장 오래살아남는다고 할때)
	모든 방향변환에서 살아남고
	X초 이후에 길이 N을 지나서 부딪힌다고 할 때
	O(1) * (X+N) = O(X+N) 이라고 생각했는데 올바른 생각인지
	궁금합니다.

	djm03178 [10:35 PM]
	X라는 것은 마지막 방향 변환이 일어난 시간을 말씀하시는 건가요?

	10jobss [10:36 PM]
	네 맞습니다

	djm03178 [10:36 PM]
	둘을 분리하자면 그렇게 이야기할 수 있겠네요
	그런데 사실 생각해 보면
	가장 오래 살아남는 경우에
	방향 전환이 일어나는 시간 간격은
	O(N)초가 되겠죠
	그러면 방향 변환을 L번 한다면
	이 때까지 걸리는 시간이 O(NL) 시간일 거고
	여기에 마지막 +N을 한다고 해도
	영향은 없을 것 같네요

	어려운 문제는 아니나 집중안하면 실수하기 딱 좋은 문제
	t, cmd 배열 입력 받을 때 조심
	(북쪽을 +1로 했는데 디버깅을 통해서 알게됨.. 시간 잡아먹었음
	while 문 안에 ans++ 하는 위치도 조심)
*/
#include <cstdio>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int n, a[101][101], t[100];
char cmd[100];
bool chk[101][101];
int dy[4] = { -1,0,1,0 }, dx[4] = { 0,1,0,-1 };
deque<pii> dq;
bool bound(int y, int x) {
	if (y<1 || y>n || x<1 || x>n) return false;
	return true;
}
int main() {
	int i, k, row, col, l, dir = 1, ans = 0;
	scanf("%d%d", &n, &k);
	while (k--) {
		scanf("%d%d", &row, &col);
		a[row][col] = 1;
	}
	scanf("%d", &l);
	for (i = 0; i < l; i++) {
		scanf("%d %c", &t[i], &cmd[i]);
	}
	chk[1][1] = true;
	dq.push_front({ 1,1 });
	i = 0;
	while (!dq.empty()) {
		ans++;
		int ty = dq.back().first;
		int tx = dq.back().second;
		int ny = dq.front().first + dy[dir];
		int nx = dq.front().second + dx[dir];
		if (!bound(ny, nx) || chk[ny][nx]) break;
		if (a[ny][nx] == 1) {
			a[ny][nx] = 0;
			chk[ny][nx] = true;
			dq.push_front({ ny,nx });
		}
		else {
			chk[ty][tx] = false;
			dq.pop_back();
			chk[ny][nx] = true;
			dq.push_front({ ny,nx });
		}
		if (ans == t[i]) {
			if (cmd[i] == 'L') dir = (dir + 3) % 4;
			else dir = (dir + 1) % 4;
			i++;
		}
	}
	printf("%d", ans);
	return 0;
}