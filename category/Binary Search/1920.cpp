/*
Problem : https://www.acmicpc.net/problem/1920
Author: 10jobss
Time complexity: O((N+M)logN)
solution :
	기본 Binary Search 문제
	N개의 원소를 std::sort 시 시간복잡도 NlogN
	N개의 원소 중 M개 원소를 이분탐색하는는 시간복잡도 MlogN
	따라서 O((N+M)logN)

	algorithm 헤더에 binary_search(begin, end, val) 값이 구현되어있다.
*/
#include <cstdio>
#include <algorithm>
#define MAX 100000
using namespace std;
int a[MAX], n, m;
bool bsearch(int k) {
	int left = 0, right = n - 1;
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (a[mid] == k) {
			return true;
		}
		if (a[mid] < k) left = mid + 1;
		else right = mid - 1;
	}
	return false;
}
int main() {
	int i, x;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%d", &x);
		printf("%d\n", bsearch(x));
	}
	return 0;
}