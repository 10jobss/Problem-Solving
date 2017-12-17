/*
problem : https://www.acmicpc.net/problem/14502
solution :
�� 3���� ����� ���� ����
���̷����� ��ü�� ���� �� ���ٸ� ���������� �ִ밡 �ǵ��� ��������
�ƹ��� �����ص� ����Ž������ �� 3���� ������ ����� ��� �ۿ� ���� (64C3�� ���� ��)
8*8�̶� ������ �� ����, 6�� for��? �𸣰���
R*10 + C�� ���� key�� 3�� for������ ������ �ٲ�
0�� ���� ���� �������ϱ� ������ ���� ������ Ȯ����
*/
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
int N, M, ans;
int adj[8][8], tmp[8][8], key[64];
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
queue<pii> q;
void put() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (tmp[i][j] == 2) q.push(make_pair(i, j));
		}
	}
}
void cpy() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) tmp[i][j] = adj[i][j];
	}
}
void bfs(int y, int x) {
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (tmp[ny][nx] == 1 || tmp[ny][nx] == 2) continue;
			tmp[ny][nx] = 2;
			q.push(make_pair(ny, nx));
		}
	}
}
int safe() {
	int ret = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (tmp[i][j] == 0) ret++;
		}
	}
	return ret;
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf("%d", &adj[i][j]);
		}
	}
	int key_size = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) key[key_size++] = i * 10 + j;
	}
	for (int i = 0; i < key_size; ++i) {
		if (adj[key[i] / 10][key[i] % 10]) continue;
		for (int j = i + 1; j < key_size; ++j) {
			if (adj[key[j] / 10][key[j] % 10]) continue;
			for (int k = j + 1; k < key_size; ++k) {
				if (adj[key[k] / 10][key[k] % 10]) continue;
				cpy();
				tmp[key[i] / 10][key[i] % 10] = tmp[key[j] / 10][key[j] % 10] = tmp[key[k] / 10][key[k] % 10] = 1;
				put();
				if (!q.empty()) bfs(q.front().first, q.front().second);
				int ret = safe();
				ans = max(ans, ret);
			}
		}
	}
	printf("%d", ans);
	return 0;
}