/*
problem : https://www.acmicpc.net/problem/9466
solution :
	Cycle ã�� ����. ��Ÿ�� �� �ϴ� DFS
	Cycle�� �������� ��ġ�� �߿����� ����. 1,2,3,4 ��尡 Cycle Component(CC)�� �� ��� ������ �����ϵ� ����
	bcylce�� �� ������ ���·�
	0 : �ʱ� ����, 1 : �湮������ CC������ ��
	2 : �湮�� �ϰ� CC 3 : �湮�ϰ� CC �ƴ�
	���� ������ �ʱ� ���°� �ƴϰ� 1 ���¶�� f ȣ��(CC check) �� return
	���ڰ� ���� �������� ������ ȣ���ϱ� ������ '�߸� ������ �κ�'�� v>=a[v] ��� �ؼ� WA
*/
#include <cstdio>
#include <cstring>
#define MAX (int)1e+5
int tc, n, ans, a[MAX], bcycle[MAX];
void f(int v) {
	bcycle[v] = 2;
	if (bcycle[a[v]] != 2) f(a[v]);
}
void dfs(int v) {
	bcycle[v] = 1;
	if (!bcycle[a[v]]) dfs(a[v]); // �߸� ������ �κ�
	else if (bcycle[a[v]] == 1) {
		f(a[v]);
		return;
	}
	if (bcycle[v] != 2) bcycle[v] = 3;
}
int main() {
	scanf("%d", &tc);
	while (tc--) {
		ans = 0;
		memset(bcycle, false, sizeof(bcycle));
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			a[i]--;
		}
		for (int i = 0; i < n; ++i) {
			if (!bcycle[i]) dfs(i);
		}
		for (int i = 0; i < n; ++i) {
			if (bcycle[i] != 2) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}