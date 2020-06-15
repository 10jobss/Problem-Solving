/*
Problem : https://www.acmicpc.net/problem/1339
Author: 10jobss
Time complexity: O(N*N!)
solution :
	������ �̿��ؼ� ��� ��츦 Ȯ���ߴ� (2�� ���� 1.4������)
	1. ���ڵ��� �Է¹޴´�
	2. ���ڿ� ������ŭ �湮 Ȯ�� �� vector�� 9���� �ִ´�
	3. ������ �̿��� ��� ��� �� �ִ밪�� ã�´�

	chk�迭�� c[i][j]-'A' ������ϴµ� �ε����� char�� �־ WA <-- ��������

	������ Ǯ�̿� Backtracknig�� �̿��� Ǯ�̵� Ȯ������
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