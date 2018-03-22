/*
Problem : https://www.acmicpc.net/problem/1062
Author: 10jobss
Time complexity: ??
solution :
	(다음번에 설명 다시하기 )
	k>=sz 예외를 처리하지 않아 계속 RTE
	문제를 처음에 잘못 이해해서 
	1. 문자열을 받는다
	2. chk에 사용해야할 문자를 확인
	3. vc에 a,c,i,n,t를 제외하고 써야할 문자 put
	4. 조합을 permutation 하면서 가능한 단어 수 확인
	a,c,i,n,t는 기본적으로 필요해서 제외
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