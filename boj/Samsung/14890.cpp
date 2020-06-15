/*
problem : https://www.acmicpc.net/problem/14890
solution :
	완전탐색. 결국 다 해보는 수밖에 없음
	처음에 경사로가 놓인 곳의 높이를 1증가시키는 방법을 생각했으나 잘못됨 (L 마지막은 그대로)
	chk 배열을 통해 경사로가 놓여있는지 아닌지 판단 (-1 곱하는 건 다시 확인할때 바꿔주기 귀찮아서)
	경사로를 뒤로 설치할 때, 앞으로 설치할 때 구분
	예외처리 까다로웠음 L==1일 때
	오래걸림
*/
#include <cstdio>
#include <cstring>
int n, l, cnt, adj[100][100];
bool chk[100][100];
int main() {
	scanf("%d%d", &n, &l);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) scanf("%d", &adj[i][j]);
	}
	for (int i = 0; i < n; ++i) {
		bool flag = true;
		for (int j = 0; j < n - 1; ) {
			if (adj[i][j] == adj[i][j + 1]) { j++; continue; }
			if (adj[i][j] - adj[i][j + 1] > 1 || adj[i][j + 1] - adj[i][j] > 1) { flag = false; break; }
			if (adj[i][j] - adj[i][j + 1] == 1) {
				if (j + l >= n) { flag = false; break; }
				for (int k = j + 1; k <= j + l; ++k) {
					if (k == j + l) break;
					if (adj[i][k] != adj[i][k + 1]) { flag = false; break; }
					if (chk[i][k] || chk[i][k + 1]) { flag = false; break; }
				}
				if (!flag) break;
				for (int k = j + 1; k <= j + l; ++k) {
					chk[i][k] = true;
				}
				j += l;
			}
			else if (adj[i][j + 1] - adj[i][j] == 1) {
				if (j - l + 1 < 0) { flag = false; break; }
				for (int k = j; k >= j - l + 1; --k) {
					if (k == j - l + 1) break;
					if (adj[i][k] != adj[i][k - 1]) { flag = false; break; }
					if (chk[i][k] || chk[i][k - 1]) { flag = false; break; }
				}
				if (l == 1) {
					if (chk[i][j]) { flag = false; break; }
				}
				if (!flag) break;
				for (int k = j; k >= j - l + 1; --k) {
					chk[i][k] = true;
				}
				j++;
			}
		}
		if (flag) cnt++;
	}
	memset(chk, 0, sizeof(chk));
	for (int j = 0; j < n; ++j) {
		bool flag = true;
		for (int i = 0; i < n - 1; ) {
			if (adj[i][j] == adj[i + 1][j]) { i++; continue; }
			if (adj[i][j] - adj[i + 1][j] > 1 || adj[i + 1][j] - adj[i][j] > 1) { flag = false; break; }
			if (adj[i][j] - adj[i + 1][j] == 1) {
				if (i + l >= n) { flag = false; break; }
				for (int k = i + 1; k <= i + l; ++k) {
					if (k == i + l) break;
					if (adj[k][j] != adj[k + 1][j]) { flag = false; break; }
					if (chk[k][j] || chk[k + 1][j]) { flag = false; break; }
				}
				if (!flag) break;
				for (int k = i + 1; k <= i + l; ++k) {
					chk[k][j] = true;
				}
				i += l;
			}
			else if (adj[i + 1][j] - adj[i][j] == 1) {
				if (i - l + 1 < 0) { flag = false; break; }
				for (int k = i; k >= i - l + 1; --k) {
					if (k == i - l + 1) break;
					if (adj[k][j] != adj[k - 1][j]) { flag = false; break; }
					if (chk[k][j] || chk[k - 1][j]) { flag = false; break; }
				}
				if (l == 1) {
					if (chk[i][j]) { flag = false; break; }
				}
				if (!flag) break;
				for (int k = i; k >= i - l + 1; --k) {
					chk[k][j] = true;
				}
				i++;
			}
		}
		if (flag) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}