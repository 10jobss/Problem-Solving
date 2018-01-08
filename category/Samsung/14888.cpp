/*
problem : https://www.acmicpc.net/problem/14888
solution :
	���ڴ� ����, �����ڸ� �Ϸķ� �����ϴ� ����� ����
	next_permutation�� ����ϴ� Ǯ�� ����
	sum�� �ʱⰪ�� v[0]�� �ؾ��� for���� �¾� ������
	1�� ���� WA�� ���� : min, max ���� �߸� ����, ���������� 987654321�� min, 0�� max ������ ��
	������ ���� ���굵�� -10�� ~ 10���� ����� ������ ���ٰ� �Ͽ� ����
	DFS�� Ȱ���� Ǯ�̵� �־ �ٽ� Ǯ���
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX (int)1e+9
using namespace std;
int main() {
	int n, i, x, idx = 0, mx = -MAX, mn = MAX;
	scanf("%d", &n);
	vector<int> v(n), a(n - 1);
	for (i = 0; i < n; ++i) scanf("%d", &v[i]);
	for (i = 0; i < 4; ++i) { // 0 ����, 1 ����, 2 ���� , 3 ������
		scanf("%d", &x);
		while (x--) a[idx++] = i;
	}
	do {
		int sum = v[0];
		for (i = 0; i < n - 1; ++i) {
			switch (a[i]) {
			case 0:
				sum += v[i + 1];
				break;
			case 1:
				sum -= v[i + 1];
				break;
			case 2:
				sum *= v[i + 1];
				break;
			case 3:
				if (sum > 0) sum /= v[i + 1];
				else {
					sum = -sum;
					sum /= v[i + 1];
					sum = -sum;
				}
			}
		}
		mx = max(mx, sum), mn = min(mn, sum);
	} while (next_permutation(a.begin(), a.end()));
	printf("%d\n%d", mx, mn);
	return 0;
}