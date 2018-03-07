/*
Problem : https://www.acmicpc.net/problem/1753
Author: 10jobss
Time complexity: O(N^4) ???
solution :
	BFS depth�� ���� �ٽ� �ѹ� ���ݰԵ� ����
	<������ �����ߴ� ���>
	- �����Һ��� �׷��ȣ �����ϴµ� �װ����� ��� �ϳ��� q�� ���� �����Ѵ�(������ ������ŭ ���Ұ� �ִ�)
	- �׸��� BFS�� ���� ������ Ȯ���ϴ� ������ �õ�������
	10
	1 1 1 0 0 0 0 0 0 0
	1 0 1 0 0 0 0 0 0 0
	0 0 1 0 0 0 0 0 0 0
	0 0 1 0 0 0 0 0 0 0
	0 0 1 0 0 0 0 0 0 0
	0 0 1 0 0 0 0 1 0 0
	0 0 0 0 0 0 1 1 0 0
	0 0 0 0 1 0 1 0 0 0
	0 0 0 0 1 1 1 0 0 0
	0 0 0 0 0 0 0 0 0 0
	���� ���� �ݷʰ� �߻� (�� : 3, ��� : 4)
	- ������ ���� �Ʒ��� ������ ���� �������� ���� ������ Ȯ��Ǿ depth�� ������� ����ä Ȯ��Ǿ���

	<���� Ǯ��>
	������ �����ҿ� ���� BFS�� ����
	1. ���� �κ� 4������ �켱Ž��
	2. 4���� �� �ٴٰ� 1������ �����Ѵٸ� enqueue (0�ΰ��� ������ �� �ʿ䰡 ����)
	3. depth�� ����� Ž�� ����
	   ���� ������ �ٴ��� ��� enqueue
	   �ٴٰ� �ƴѵ� �׷� ��ȣ�� �ٸ��� ����

	O(N^2)�� �־��� ��� ���� ũ�� 1�̰� ü����ó�� ���� ��Ȳ����
	(N^2)/2���� �����Ұ� �����ϴϱ� O(N^4)�̶�� �����ߴµ� AC ��� O(N^3)??? ���� ����� ���ͼ�
	�𸣰���
*/
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;
typedef pair<int, int> pii;
int n, ans=INF, arr[100][100];
bool chk[100][100];
int dy[4] = { -1,0,1,0 }, dx[4] = { 0,1,0,-1 };
queue<pii> q;
bool bnd(int y, int x) {
	return y >= 0 && y < n && x >= 0 && x < n;
}
void color(int y, int x, int c) {
	chk[y][x] = true;
	arr[y][x] = c;
	q.push(make_pair(y, x));
	while (!q.empty()) {
		pii cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];
			if (!bnd(ny, nx)) continue;
			if (!arr[ny][nx]) continue;
			if (chk[ny][nx]) continue;
			chk[ny][nx] = true;
			arr[ny][nx] = c;
			q.push(make_pair(ny, nx));
		}
	}
}
int bfs(int g) {
	queue<pii> Q;
	int i, j, k;
	int ret = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (arr[i][j] != g) continue;
			int cnt = 0;
			for (k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (!bnd(ny, nx)) continue;
				if (!arr[ny][nx]) cnt++;
			}
			if (cnt > 0) {
				chk[i][j] = true;
				Q.push(make_pair(i, j));
			}
		}
	}
	while (!Q.empty()) {
		int q_size = Q.size();
		while (q_size--) {
			pii cur = Q.front();
			Q.pop();
			for (i = 0; i < 4; i++) {
				int ny = cur.first + dy[i];
				int nx = cur.second + dx[i];
				if (!bnd(ny, nx)) continue;
				if (chk[ny][nx]) continue;
				if (!arr[ny][nx]) {
					chk[ny][nx] = true;
					Q.push(make_pair(ny, nx));
				}
				else if (arr[ny][nx] != arr[cur.first][cur.second]) {
					return ret;
				}
			}
		}
		ret++;
	}
}
int main() {
	scanf("%d", &n);
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) scanf("%d", &arr[i][j]);
	}
	int cc = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (arr[i][j] == 1 && !chk[i][j]) {
				color(i, j, ++cc);
			}
		}
	}
	//print_arr();
	for (i = 1; i <= cc; i++) {
		memset(chk, false, sizeof(chk));
		ans = min(ans, bfs(i));
	}
	printf("%d", ans);
	return 0;
}