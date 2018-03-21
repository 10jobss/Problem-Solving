/*
Problem : https://www.acmicpc.net/problem/1941
Author: 10jobss
Time complexity: O(2^25*5^2)
solution :
	���ѽð��� 2���ε� 1.9�ʰ� ���Դ�.. ���� ����Ǯ�̴� �ƴ����� ������� �־ ����� ����
	1. 25C7 ���� 2. ����ó�� 3. dfs�� ������ Ȯ��
	�ϴ� 25C7�� ���ϴ� ���� ��Ʈ����ũ�� �̿��ߴ�
	���̰� 7�� �ƴѰ��� �̴ټ� �׷��� ���� 4�̸��� ��츦 ����
	(�ٵ� 7�� �Ѿ�� ���� break�� ���� ������ TLE�� ���Դ�..)
	chk[i]==2�� ���� �׷��̰� �湮���� ����
	chk[i]==3�� ���� �׷��̰� �湮�� ����
	������ ���� �ƹ���ҳ� dfs �湮��
	chk[i]�� 3�� �ƴ� ���� ������ ĥ���ָ� �Ἲ�� �� ����
	�� ���� Ǯ�̴� http://baactree.tistory.com/5 ����

	����� std::next_permutation�� ��� ������ ũ�⸦ n�̶� �Ҷ�
	n���� ���Ұ� ��� �ٸ� ���� O(n!)������
	�ߺ� ���Ұ� �����ϸ� O(n!) �̸��̴�.
*/
#include <cstdio>
#include <cstring>
int ans;
char c[5][5];
int chk[25];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
void dfs(int y, int x) {
	chk[y * 5 + x] = 3;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && ny < 5 && nx >= 0 && nx < 5 && chk[ny * 5 + nx] == 2) {
			dfs(ny, nx);
		}
	}
}
int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) scanf(" %c", &c[i][j]);
	}
	for (int i = 0; i < (1 << 25); i++) {
		int len = 0, ss = 0;
		bool bb = true;
		for (int j = 0; j < 25; j++) {
			if (i&(1 << j)) {
				if (c[j / 5][j % 5] == 'S') ss++;
				len++;
			}
			if (len > 7) {
				bb = false;
				break;
			}
		}
		if (!bb) continue;
		if (len != 7 || ss < 4) continue;
		memset(chk, 0, sizeof(chk));
		int idx = 0, g[7] = { 0 };
		for (int j = 0; j < 25; j++) {
			if (i&(1 << j)) {
				g[idx++] = j;
				chk[j] = 2;
			}
		}
		dfs(g[0] / 5, g[0] % 5);
		bool flag = true;
		for (int j = 0; j < 7; j++) {
			if (chk[g[j]] != 3) {
				flag = false;
				break;
			}
		}
		if (!flag) continue;
		ans++;
	}
	printf("%d", ans);
	return 0;
}