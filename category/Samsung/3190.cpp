/*
Problem : https://www.acmicpc.net/problem/3190
Author: 10jobss
Time complexity: O(N*L)
solution :
	���� ���� (�򰥸��� ����)
	ó���� ������ DFS�� ���ö���
	�׷��� ������ ���°� ���ϴ� ���� ���� �Ӹ��� ������
	�� ���¸� deque�� �̿��ؼ� Ǫ�� ���� ���ٰ� ������

	��, ��, ��, �� ������ ������ �Ұ��
	���� �ٶ󺸴� ���� dir�̶� �ϸ�
	�ð���� 90 ȸ���� (dir+1)%4, �ݽð���� 90 ȸ���� (dir+3)%4�� ǥ�� ����

	���� ��ġ�� ���� true�� ǥ��
	���� ĭ�� ����� ������ pop_back() �� �ʿ���� �� ��ǥ�� push_front(), ��� �����ְ�
	����� ���ٸ� pop_back()�ϰ� ������ ���� �ڸ��� false�� �ٲ��ְ� �� ��ǥ push_front()

	�ð����⵵�� while���� �����ϴµ�
	<djm03178���� �亯>
	10jobss [10:33 PM]
	deque�� �̿��ؼ� Ǯ���� ���� �Ǵ��ϱ�δ�
	deque�� push&pop ������ O(1)�̴ϱ�
	�־��� ��� (���� ������Ƴ��´ٰ� �Ҷ�)
	��� ���⺯ȯ���� ��Ƴ���
	X�� ���Ŀ� ���� N�� ������ �ε����ٰ� �� ��
	O(1) * (X+N) = O(X+N) �̶�� �����ߴµ� �ùٸ� ��������
	�ñ��մϴ�.

	djm03178 [10:35 PM]
	X��� ���� ������ ���� ��ȯ�� �Ͼ �ð��� �����Ͻô� �ǰ���?

	10jobss [10:36 PM]
	�� �½��ϴ�

	djm03178 [10:36 PM]
	���� �и����ڸ� �׷��� �̾߱��� �� �ְڳ׿�
	�׷��� ��� ������ ����
	���� ���� ��Ƴ��� ��쿡
	���� ��ȯ�� �Ͼ�� �ð� ������
	O(N)�ʰ� �ǰ���
	�׷��� ���� ��ȯ�� L�� �Ѵٸ�
	�� ������ �ɸ��� �ð��� O(NL) �ð��� �Ű�
	���⿡ ������ +N�� �Ѵٰ� �ص�
	������ ���� �� ���׿�

	����� ������ �ƴϳ� ���߾��ϸ� �Ǽ��ϱ� �� ���� ����
	t, cmd �迭 �Է� ���� �� ����
	(������ +1�� �ߴµ� ������� ���ؼ� �˰Ե�.. �ð� ��ƸԾ���
	while �� �ȿ� ans++ �ϴ� ��ġ�� ����)
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