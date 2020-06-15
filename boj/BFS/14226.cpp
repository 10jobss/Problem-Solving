/*
problem : https://www.acmicpc.net/problem/14226
solution :
	(���� TLE, RTE, �޸��ʰ�..) ���� �����ε� �� ������ �𸣰���
	ȭ�� �̸�Ƽ�� �� : x, Ŭ������ �̸�Ƽ�� �� : y
	x, y�� ���¸� check�ؼ� �ߺ��� ���°� enqueue ���� �ʵ��� ó��
	{x,y} --> {x-1, y}, {x, x}, {x+y, y} �� �̵��� �� ����
	�� ��쿡�� �̵��� �ʿ䰡 ���� ��� 1) x==y�� �� {x, x} 2) y==0�� �� {x+y, y}
	{x-1, y}�� ��� ó���� x-1>s�� �� WA, x-1>2 AC... ������ Ǯ����
	�¾Ƶ� �������� ������ ���ϰ��� (�ٽ� Ǯ� ��)
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