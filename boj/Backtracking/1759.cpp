/*
Problem : https://www.acmicpc.net/problem/1759
Author: 10jobss
Time complexity: ?? c���� l�� �����̴ϱ�.. O(cCl) �ƴұ�??
solution :
	Backtracking�� �̿��� Ǯ��
	solve(���� �����ִ� idx, ���� ���ڿ��� ����, ���� ��, ���� ��)
	�׻� Backtracking ������ ���� ��� ����δ����� �򰥸�
	-1���� ȣ�� �� �ݺ����� ���ʿ� +1���� �����簡
	0���� ȣ�� �� �ݺ����� �ڱ� �ڽ�, ��� ȣ�� �� +1 �ϵ簡
	
	�ݺ����ȿ� ans�� ������ ������ len�� ������ ������ �򰥸��� �� ��
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int l, c;
char s[16], ans[16];
void solve(int idx, int len, int yy, int xx) {
	if (len == l) {
		if (yy >= 1 && xx >= 2) puts(ans);
		return;
	}
	for (int i = idx; i < c; i++) {
		ans[len] = s[i];
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			solve(i+1, len + 1, yy + 1, xx);
		else
			solve(i+1, len + 1, yy, xx + 1);
	}
}
int main() {
	scanf("%d%d", &l, &c);
	for (int i = 0; i < c; i++) scanf(" %c", &s[i]);
	sort(s, s + c);
	solve(0, 0, 0, 0);
	return 0;
}