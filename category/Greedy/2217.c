/*
Problem : https://icpc.me/2217
Author: 10jobss
Time complexity: O(N*logN)
solution :
	a1,a2,...,ak의 k개 로프를 사용했을 때 min(a1,a2,..,ak) * k 만큼의 중량을 견딜 수 있다
	로프를 되도록 강한 로프로 구성하는 것이 유리하므로 그리디하게 해결 가능하다
*/
#include <stdio.h>
#define MAX 100000
int n, ans;
int a[MAX], b[MAX];
void merge(int lo, int mid, int hi) {
	int i = lo, j = mid + 1, k = 0;
	while (i <= mid && j <= hi) {
		if (a[i] >= a[j]) b[k++] = a[i++];
		else b[k++] = a[j++];
	}
	while (i <= mid) b[k++] = a[i++];
	while (j <= hi) b[k++] = a[j++];
	for (i = lo; i <= hi; i++)
		a[i] = b[i - lo];
}
void mergeSort(int lo, int hi) {
	if (lo >= hi) return;
	int mid = (lo + hi) / 2;
	mergeSort(lo, mid);
	mergeSort(mid + 1, hi);
	merge(lo, mid, hi);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i<n; i++)
		scanf("%d", a + i);
	mergeSort(0, n - 1);
	ans = a[0];
	for (int i = 1; i<n; i++) {
		ans = ans<(i + 1)*a[i] ? (i + 1)*a[i] : ans;
	}
	printf("%d", ans);
	return 0;
}
