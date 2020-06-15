/*
problem : https://www.acmicpc.net/problem/14889
solution :
	���� ������ ��� ��츦 �غ� �� �ۿ� ���ٰ� ����
	��ü���� Ʋ�� ���� ������ ��� ����� ���� ���ϰ� �ɷ�ġ�� ���� �����ϴ� �������
	����Ž���ؾ��ϴµ� bitmask�� �̿��Ϸ� ������ �� �������� ����, ���� ���������� ������ ���� ����
	�� �������� �ٸ� ���������� ������ ��� �����ϴ� �׷������ ����
	������ �� ���� ������ ���Ͽ� dfs ������ ������ �� ������ �� �� ����
	���� ���� �� �ִ� ����� �� : (N C N/2)/2
	dfs Ž���� ���� �湮�� ������ ���� N/2���� �� ���ߴ� ���
	l==N/2�� �� �湮�� ����(start��) �湮���� �ʴ� ����(link��)�� ���� ���ϴ� gap() �Լ� ����
	
	** '�ĺ��ڸ� ã�� �� �����ϴ�.' gap �Լ��� dfs �Լ����� ���߿� �����ؼ� �߻�
	���ø� ���� ���Ҳ��� ���������� ������ �°� ������ ��
*/
#include <cstdio>
#include <algorithm>
#define INF 987654321
using namespace std;
int n, ans = INF, s[20][20];
bool chk[20];
int gap() {
	int start = 0, link = 0;
	for (int i = 0; i < n; ++i) {
		if (chk[i]) {
			for (int j = 0; j < n; ++j) {
				if (chk[j]) start += s[i][j];
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (!chk[i]) {
			for (int j = 0; j < n; ++j) {
				if (!chk[j]) link += s[i][j];
			}
		}
	}
	return abs(start - link);
}
void dfs(int v, int l) {
	chk[v] = true;
	if (l == n / 2) {
		ans = min(ans, gap());
		chk[v] = false;
		return;
	}
	for (int i = v + 1; i < n; ++i) {
		if (!chk[i]) dfs(i, l + 1);
	}
	chk[v] = false;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) scanf("%d", &s[i][j]);
	}
	dfs(0, 1);
	printf("%d", ans);
	return 0;
}