/*
Problem : https://www.acmicpc.net/problem/1339
Author: 10jobss
Time complexity: O(N*N!)
solution :
	순열을 이용해서 모든 경우를 확인했다 (2초 제한 1.4초정도)
	1. 문자들을 입력받는다
	2. 문자열 종류만큼 방문 확인 후 vector에 9부터 넣는다
	3. 순열을 이용해 모든 경우 중 최대값을 찾는다

	chk배열시 c[i][j]-'A' 해줘야하는데 인덱스에 char를 넣어서 WA <-- 조심하자

	수학적 풀이와 Backtracknig을 이용한 풀이도 확인하자
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, ans;
char c[10][9];
bool chk[26];
vector<char> vc;
vector<int> vi;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", c[i]);
	}
	int x = 9;
	for (int i = 0; i < n; i++) {
		for (int j = 0; c[i][j]; j++) {
			if (!chk[c[i][j]-'A']) {
				chk[c[i][j] - 'A'] = 1;
				vc.push_back(c[i][j]);
				vi.push_back(x--);
			}
		}
	}
	sort(vi.begin(), vi.end());
	int sz = vc.size();
	do {
		int sum = 0;
		for (int i = 0; i< n; i++) {
			int tmp = 0;
			for (int j = 0; c[i][j]; j++) {
				for (int k = 0; k < sz; k++) {
					if (c[i][j] == vc[k]) {
						tmp = tmp * 10 + vi[k];
						break;
					}
				}
			}
			sum += tmp;
		}
		ans = max(ans, sum);
	} while (next_permutation(vi.begin(), vi.end()));
	printf("%d", ans);
	return 0;
}