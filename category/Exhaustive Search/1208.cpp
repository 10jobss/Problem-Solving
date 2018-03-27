/*
Problem : https://www.acmicpc.net/problem/1208
Author: 10jobss
Time complexity: ???
solution :
	N=20�� https://www.acmicpc.net/problem/1182 ���� ���� ����
	Bitmask�� ��� ȣ��� ��� ��츦 ���غ��� ����������
	�� ������ N=40�̱� ������ 2^40 �̹Ƿ� �ð����� Ǯ �� ������

	�⺻���� ���̵��� �Է� �迭�� 2�κ����� �����
	������ �κ������� ���� �� ������ ���� ���̾���
	
	ó������ �� �κ����� ���� �κ������� �ٽ� ���� for������ �ؼ� Ʋ�ȴ�
	(�ⲯ ������ 2^20 * 2^20 ���� �ٽ� ��ģ ��)
	�̰� 2^20���� ���� �� �ִ� �� �� �κ����տ��� ���� x�� ���
	���������� S-x�� ���� ã���ָ� �Ǿ���
	�̷л����� ������ �ΰ��� �̺�Ž���ϸ� ������
	STL�� upper_bound�� lower_bound�� �־ �̸� Ȱ���ߴ�
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
	int n, s;
	scanf("%d%d", &n, &s);
	vector<int> a(n / 2), b(n - n / 2);
	for (int i = 0; i < n / 2; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n - n / 2; i++) scanf("%d", &b[i]);
	vector<int> aa, bb;
	for (int i = 0; i < (1 << (n / 2)); i++) {
		int sum = 0;
		for (int j = 0; j < n / 2; j++) if (i&(1 << j)) sum += a[j];
		aa.push_back(sum);
	}
	for (int i = 0; i < (1 << (n - n / 2)); i++) {
		int sum = 0;
		for (int j = 0; j < n - n / 2; j++) if (i&(1 << j)) sum += b[j];
		bb.push_back(sum);
	}
	sort(bb.begin(), bb.end());
	ll ans = 0LL;
	for (int i = 0; i < aa.size(); i++) {
		vector<int>::iterator hi = upper_bound(bb.begin(), bb.end(), s - aa[i]);
		vector<int>::iterator lo = lower_bound(bb.begin(), bb.end(), s - aa[i]);
		ans += hi - lo;
	}
	if (!s) ans--;
	printf("%lld", ans);
	return 0;
}