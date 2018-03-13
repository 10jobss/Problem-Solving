/*
Problem : https://www.acmicpc.net/problem/1920
Author: 10jobss
Time complexity: O((N+M)logN)
solution :
	�⺻ Binary Search ����
	N���� ���Ҹ� std::sort �� �ð����⵵ NlogN
	N���� ���� �� M�� ���Ҹ� �̺�Ž���ϴ´� �ð����⵵ MlogN
	���� O((N+M)logN)

	algorithm ����� binary_search(begin, end, val) ���� �����Ǿ��ִ�.
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