/*
Problem : https://icpc.me/15486
Author: 10jobss
Time complexity: O(N)
solution :
  N�� ũ�� ������ 14501���� ���� N^2���� Ǯ �� ����
  ���������� dp������ ó������ ��ȭ���� ã���� �ϱ� ���ٴ�
  
  ������ ���� �帧���� �����ߴ�
  1) ���ʿ��� Ž���� ������
  2) ��� �������� ���ư� ���ΰ� (i ������ ����(i-1..) Ȥ�� ���� ������(i+1..))
  d[i] -> i�Ϻ��� ������ �� ���� �� �ִ� �ִ� ����
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAX 1500001
using namespace std;
int n, t[MAX], p[MAX], d[MAX];
int f(int k) {
	if (k>n) return 0;
	int &ret = d[k];
	if (ret != -1) return ret;
	ret = 0;
	if (k + t[k] <= n + 1) ret = p[k] + f(k + t[k]);
	ret = max(ret, f(k + 1));
	return ret;
}
int main() {
	memset(d, -1, sizeof(d));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", t + i, p + i);
	printf("%d", f(1));
	return 0;
}