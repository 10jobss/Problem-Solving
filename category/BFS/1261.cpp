/*
problem : https://www.acmicpc.net/problem/1261
solution :
	BFS Ž�� ����
	�ƹ����� ���� queue�� �̿��ؼ� BFS Ž������ Ǯ������ TLE (�ݵ�� ���ľ��� �κ�!!)
	�μ��� ���� ������ �ּ�ȭ�ؾ� �ϱ� ������ ���� ���� �켱���� ���� ����
	deque�� �̿��� ���� ��� push_front(), ���� ��� push_back()
	priority queue�� �̿��� Ǯ�̵� ����

	<���Ӱ� ������ ���>
	1. memset > for loop > std::fill (�ӵ� ���� ��)
	std:fill�� �ſ� �����ٴ� ����� ���޾Ҵ�.. (fill�� ��ӽ�µ� TLE, ������ fill�� �� �� ������ �׳� for loop)
	
	2. c�� c++�� struct ������
	https://www.geeksforgeeks.org/difference-c-structures-c-structures/

	������ Ǯ �� �� ����ȭ�� �������� �����غ��� ������ �����߰ڴ�
	(�켱������ �ο��ϰų� �ڷᱸ���� ���� ����ȭ Ž���� ��������)
	����Ž���� ���� ��¿ �� ������
	�����ϴٸ� Ž�� �� ���ʿ��� �κ��� ������ ����ȭ�ϴ� ������ ������ �ڴ�(������ Backtracking ����..)
	
	DP, Dijkstra�� �̿��� Ǯ�̵� �غ� ��
*/
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
int m, n, cnt[100][100];
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
bool a[100][100];
deque<pii> dq;
int main() {
	int i, j;
	scanf("%d%d", &m, &n);
	memset(cnt, -1, sizeof(cnt));
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) scanf("%1d", &a[i][j]);
	}
	cnt[0][0] = 0;
	dq.push_front({ 0,0 });
	while (!dq.empty() && cnt[n - 1][m - 1] == -1) {
		int cy = dq.front().first;
		int cx = dq.front().second;
		dq.pop_front();
		for (i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (cnt[ny][nx] == -1) {
				if (a[ny][nx]) {
					cnt[ny][nx] = cnt[cy][cx] + 1;
					dq.push_back({ ny,nx });
				}
				else {
					cnt[ny][nx] = cnt[cy][cx];
					dq.push_front({ ny,nx });
				}
			}
		}
	}
	printf("%d", cnt[n - 1][m - 1]);
	return 0;
}