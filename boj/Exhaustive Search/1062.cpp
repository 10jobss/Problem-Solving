/*
Problem : https://www.acmicpc.net/problem/1062
Author: 10jobss
Time complexity: ??
solution :
	(�������� ���� �ٽ��ϱ� )
	k>=sz ���ܸ� ó������ �ʾ� ��� RTE
	������ ó���� �߸� �����ؼ� 
	1. ���ڿ��� �޴´�
	2. chk�� ����ؾ��� ���ڸ� Ȯ��
	3. vc�� a,c,i,n,t�� �����ϰ� ����� ���� put
	4. ������ permutation �ϸ鼭 ������ �ܾ� �� Ȯ��
	a,c,i,n,t�� �⺻������ �ʿ��ؼ� ����
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n, k, ans;
char s[50][16];
bool chk[26];
vector<char> vc;
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	if (k < 5) {
		puts("0");
		return 0;
	}
	k -= 5;
	chk['a'-'a'] = chk['c'-'a'] = chk['i'-'a'] = chk['n'-'a'] = chk['t'-'a'] = 1;
	for (int i = 0; i < n; i++) {
		int len = strlen(s[i]);
		for (int j = 4; j < len - 4; j++) {
			if (!chk[s[i][j] - 'a']) {
				chk[s[i][j] - 'a'] = 1;
				vc.push_back(s[i][j]);
			}
		}
	}
	int sz = vc.size();
	if (k >= sz) {
		printf("%d", n);
		return 0;
	}
	vector<int> vi(sz, 0);
	for (int i = sz - 1; i >= sz - k; i--) vi[i] = 1;
	do {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int len = strlen(s[i]);
			bool flag = true;
			for (int j = 4; j < len - 4; j++) {
				if (s[i][j] == 'a' || s[i][j] == 'c' || s[i][j] == 'i' || s[i][j] == 'n' || s[i][j] == 't')
					continue;
				bool bb = false;
				for (int jj = 0; jj < sz; jj++) {
					if (s[i][j] == vc[jj] && vi[jj]) {
						bb = true;
						break;
					}
				}
				if (!bb) {
					flag = false;
					break;
				}
			}
			if (flag) cnt++;
		}
		ans = max(ans, cnt);
	} while (next_permutation(vi.begin(), vi.end()));
	printf("%d", ans);
	return 0;
}