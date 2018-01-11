/*
problem : https://www.acmicpc.net/problem/1107
solution :
	���峭 ��ư�� �Է����� �־����� ������ ����� �������� �ʾ���
	�� �ڸ����� Ȯ���ϴ� ���� ���ܰ� �ʹ� ���� ������ ���� ����
	���ڹ�ư�� 1���� (���ڸ� �̿��� �ش� ä�η� ���� �� �ٽ� ���ڸ� ���� ���� ����) + ������ư = ��ǥä��
	��� : ��� ä�ο� ���ؼ� ���� Ž��
	ans�� +, - ������ ���� �� Ƚ���� �ʱ�ȭ
	1. i ä�η� �̵��ϰ�
	2. �� ��ȣ���� n���� +, - ��ư���� ����
	3. ���ڷ� i ä���� �� �� ���� �� �ڸ����� +, -�� i���� �� �� �ּҰ��� tmp
	4. i ä�ο��� nä�� ���� +, - ��ư�� �� ���� Ƚ���� tmp�� ����
	1�� - WA, �� �� �ִ� ��ȣ Ž���� 500000���� �߱� ����
		  n == 500000�� �� ���峭 ��ȣ�� ���� 500000���� �� ū �ʿ��� n���� �� �� �ֱ� ����
	�־��� ��� n == 500000 �̰� 4�� ����� �� ���� �� 4444444 --> 500000 �̹Ƿ� MAX�� 4444444
*/
#include <cstdio>
#include <algorithm>
#define MAX 4444444
using namespace std;
bool chk[10]; // fale - normal, true - broken
int main() {
	int i, j, n, m, x;
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d", &x);
		chk[x] = true;
	}
	int ans = abs(n - 100);
	for (i = 0; i <= MAX; ++i) {
		if (!i) {
			if (!chk[i]) ans = min(ans, abs(i - n) + 1);
		}
		else {
			j = i;
			bool flag = true;
			int cnt = 0;
			for (; j > 0; cnt++, j /= 10) {
				if (chk[j % 10]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				int tmp = abs(i - 100) > cnt ? cnt : abs(i - 100);
				tmp += abs(i - n);
				ans = min(ans, tmp);
			}
		}
	}
	printf("%d", ans);
	return 0;
}