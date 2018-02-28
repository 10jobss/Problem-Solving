/*
Problem : https://www.acmicpc.net/problem/2529
Author: 10jobss
Time complexity: O(k*N!)
solution :
	������ �̿��� ����Ž��
	10!�� �뷫 3�鸸 ������ �����ϴٰ� �Ǵ�
	Ʋ�Ⱦ��� ������
	1�� - c++98������ initialize list�� ���� �ʱ�ȭ �Ұ���
	2�� - 10�ڸ��� int ������ �Ѿ�µ� ��� ����, atoi --> atoll
	����, ���ڿ��� ĳ���� �� �׻� ����(�Ǽ��� ���� ���⼭)
	memcpy�� Ȯ���� �� �� �־��� ����
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
char c[10];
char mx[11], mn[11];
int main() {
	int i, k;
	ll max = 0LL, min = 9876543210;
	vector<int> a;
	for (i = 9; i >= 0; i--) a.push_back(i);
	scanf("%d", &k);
	for (i = 0; i < k; i++) {
		scanf(" %c", &c[i]);
	}
	do {
		bool flag = true;
		for (i = 0; i < k; i++) {
			if (c[i] == '<') {
				if (a[i] >= a[i + 1]) {
					flag = false;
					break;
				}
			}
			else {
				if (a[i] <= a[i + 1]) {
					flag = false;
					break;
				}
			}
		}
		if (flag) {
			char tmp[11] = { 0 };
			for (i = 0; i < k + 1; i++) {
				tmp[i] = (char)(a[i] + '0');
			}
			ll ntmp = atoll(tmp);
			if (max < ntmp) {
				max = ntmp;
				memcpy(mx, tmp, sizeof(tmp));
			}
			if (min > ntmp) {
				min = ntmp;
				memcpy(mn, tmp, sizeof(tmp));
			}
		}
	} while (prev_permutation(a.begin(), a.end()));
	printf("%s\n%s", mx, mn);
	return 0;
}