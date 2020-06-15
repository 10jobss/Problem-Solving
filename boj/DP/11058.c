/*
Problem : https://icpc.me/11058
Author: 10jobss
Time complexity: O(N^2)
solution :
	DP
	�� �������� ȭ��, ����, ĳ�� ���¸� ���� Ǯ���µ� MLE�� ����
	�뷫 ���°� 3�����̰� ���̰� 100�� Ʈ�� �����̱� ������ ť�� ���� �� ����

	d[i] = i�� ��ư ���� �� ȭ�鿡 ��µ� A�� �ִ� ����
	���۰� ����ִ� ��� ctrl V�� ctrl C, ctrl A�� �Բ� ����ؾ��Ѵ�
	
	���� d[i] = max(d[i-1]+1, (k-1)*d[i-k]) (��, k�� 2<k<i)
	
	���� ������ int�� ����� ������ ����!
*/
#include <stdio.h>
typedef long long ll;
ll d[101];
ll f(int k) {
	if (k<4) {
		d[k] = k;
		return d[k];
	}
	if (d[k]) return d[k];
	d[k] = f(k - 1) + 1;
	ll ret = 0LL;
	for (int i = 3; i<k; i++) {
		ll tmp = (i - 1)*f(k - i);
		ret = ret<tmp ? tmp : ret;
	}
	d[k] = d[k]<ret ? ret : d[k];
	return d[k];
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%lld", f(n));
	return 0;
}