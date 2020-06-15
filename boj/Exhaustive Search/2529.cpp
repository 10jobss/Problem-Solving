/*
Problem : https://www.acmicpc.net/problem/2529
Author: 10jobss
Time complexity: O(k*N!)
solution :
	순열을 이용한 완전탐색
	10!이 대략 3백만 정도라서 가능하다고 판단
	틀렸었던 이유는
	1차 - c++98에서는 initialize list로 벡터 초기화 불가능
	2차 - 10자리는 int 범위를 넘어가는데 고려 안함, atoi --> atoll
	숫자, 문자열간 캐스팅 시 항상 조심(실수가 많음 여기서)
	memcpy도 확인해 볼 수 있었던 문제
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