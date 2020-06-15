/*
problem : https://www.acmicpc.net/problem/14499
time : 45�� 
solution :
	�ùķ��̼� ������ ����
	������ �Ĳ��� �о�����ϱ� ������ �ڵ� �� ���� �ľ�
	�ֻ����� ���� ���� �迭�ε� ���������� �򰥷��� struct�� ����
	�Լ� �� �ʵ忡�� struct ����鿡 ������ �Ұ�?? --> ã�ƺ���
	roll �� ������ ��ġ���� swap�� ����ϴµ� ������ ������ �����ʾƼ� queue�� Ȱ��
*/
#include <cstdio>
#include <queue>
using namespace std;
int n, m, cy, cx, k, cmd, a[20][20];
int dy[4] = { 0,0,-1,1 }, dx[4] = { 1,-1,0,0 };
queue<int> q;
typedef struct dice {
	int top, bottom, left, right, front, back;
};
dice d;
void roll(int c) {
	switch (c) {
	case 0:
		q.push(d.top), q.push(d.right), q.push(d.bottom), q.push(d.left);
		q.push(q.front()); q.pop();
		d.top = q.front(); q.pop();
		d.right = q.front(); q.pop();
		d.bottom = q.front(); q.pop();
		d.left = q.front(); q.pop();
		break;
	case 1:
		q.push(d.top), q.push(d.left), q.push(d.bottom), q.push(d.right);
		q.push(q.front()); q.pop();
		d.top = q.front(); q.pop();
		d.left = q.front(); q.pop();
		d.bottom = q.front(); q.pop();
		d.right = q.front(); q.pop();
		break;
	case 2:
		q.push(d.top), q.push(d.back), q.push(d.bottom), q.push(d.front);
		q.push(q.front()); q.pop();
		d.top = q.front(); q.pop();
		d.back = q.front(); q.pop();
		d.bottom = q.front(); q.pop();
		d.front = q.front(); q.pop();
		break;
	case 3:
		q.push(d.top), q.push(d.front), q.push(d.bottom), q.push(d.back);
		q.push(q.front()); q.pop();
		d.top = q.front(); q.pop();
		d.front = q.front(); q.pop();
		d.bottom = q.front(); q.pop();
		d.back = q.front(); q.pop();
	}
}
void search(int y, int x, int c) {
	roll(c);
	y += dy[c], x += dx[c];
	if (!a[y][x]) a[y][x] = d.bottom;
	else {
		d.bottom = a[y][x];
		a[y][x] = 0;
	}
}
int main() {
	scanf("%d%d%d%d%d", &n, &m, &cy, &cx, &k);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) scanf("%d", &a[i][j]);
	}
	while (k--) {
		scanf("%d", &cmd);
		cmd--;
		if (cy + dy[cmd] < 0 || cy + dy[cmd] >= n || cx + dx[cmd] < 0 || cx + dx[cmd] >= m) continue;
		search(cy, cx, cmd);
		printf("%d\n", d.top);
		cy += dy[cmd], cx += dx[cmd];
	}
	return 0;
}