/*
Problem : https://www.acmicpc.net/problem/1759
Author: 10jobss
Time complexity: O(C*2^C)
solution :
	C<=15�̹Ƿ� ����Ž������ ����� ������ ����
	Bitmask�� �̿��ؼ� ��� ��츦 Ȯ���ߴ� ���̰� l�� ���� ������ Ȯ���� �ʿ䰡 ����
	Backtracking���ε� Ǯ�� �����ϴ�

	���ʿ� ������ �߱� ������ ���ĺ� ���� �����ϴ� ���ڴ� ���� ���� ����
	index ����!! (�迭 ���ʺ��� 0�ε� bitmask�Ҷ� �����ʺ��� 0�� bit�ε� ������ ������� �� ���� �򰥷���)
	�׸��� ��½� scanf�� string�� ����� �� ���� string�� ��ü�̱� ������
	������ scanf�� �ּҰ��� ���ڷ� �޴´�
	���ڿ��� �ʹ� ��Ǯ�� ����.. �ذ� �־���
	https://www.acmicpc.net/board/view/21873 ���� �亯�� ����
*/
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
char s[16];
vector<string> vs;
int main() {
	int l, c;
	scanf("%d%d", &l, &c);
	for (int i = 0; i < c; i++) scanf(" %c", &s[i]);
	sort(s, s + c);
	for (int i = 1; i < (1 << c); i++) {
		int len = 0;
		for (int j = 0; j < c; j++) {
			if (i&(1 << j)) len++;
		}
		if (len != l) continue;
		char tmp[16] = { 0 };
		int idx = 0, xx = 0, yy = 0;
		for (int j = 0; j < c; j++) {
			if (i&(1 << j)) {
				tmp[idx++] = s[j];
				if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') xx++;
				else yy++;
			}
		}
		tmp[idx] = 0;
		if (xx < 1 || yy < 2) continue;
		string str(tmp);
		vs.push_back(str);
	}
	sort(vs.begin(), vs.end());
	for (int i = 0; i < vs.size(); i++) {
		cout << vs[i] << '\n';
	}
	return 0;
}