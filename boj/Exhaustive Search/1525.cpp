/*
problem : https://www.acmicpc.net/problem/1525
solution :
	BFS�� �̿��� ����Ž�� ����
	�޸� ������ 16MB���� ��ٷο���
	���¸� �������� �����ϴ��İ� ����
	string ���� �޸��ʰ�... 0-->9�� �ٲٰ� int������ �����ϴ� ������� ����
	s_i �Լ����� ����ó�� ���ϰ� �������� ret/10�� return�ߴµ� integer overflow �߻�
	i==8�϶� ����ó����
	map�� �̿��� Ǯ�̷� �ٽ� Ǯ���, kks227�� �ڵ� Ȯ��
*/
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
int ans, g = 123456789;
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
queue<pii> q;
set<int> chk;
int search(string &s) {
	int ret = 0;
	for (int i = 0; i < 9; ++i) {
		if (s[i] == '9') {
			ret = i;
			break;
		}
	}
	return ret;
}
void swap(char &a, char &b) {
	char tmp = a;
	a = b;
	b = tmp;
}
int s_i(string &s) {
	int ret = 0;
	for (int i = 0; i < 9; ++i) {
		ret += (s[i] - '0');
		if (i == 8) break;
		ret *= 10;
	}
	return ret;
}
string i_s(int &n) {
	string ret = "";
	while (n > 0) {
		int tmp = n % 10;
		ret += (tmp + '0');
		n /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string tmp = "", x;
	for (int i = 0; i < 9; ++i) {
		cin >> x;
		x = x == "0" ? "9" : x;
		tmp += x;
	}
	int start = s_i(tmp);
	q.push({ start,0 });
	chk.insert(start);
	bool flag = false;
	while (!q.empty()) {
		int cur = q.front().first;
		int l = q.front().second;
		if (cur == g) {
			flag = true;
			ans = l;
			break;
		}
		q.pop();
		string cur_s = i_s(cur);
		int idx = search(cur_s);
		for (int i = 0; i < 4; ++i) {
			int ny = idx / 3 + dy[i];
			int nx = idx % 3 + dx[i];
			if (0 <= ny && ny < 3 && 0 <= nx && nx < 3) {
				swap(cur_s[idx], cur_s[ny * 3 + nx]);
				int next = s_i(cur_s);
				if (!chk.count(next)) {
					chk.insert(next);
					q.push({ next, l + 1 });
				}
				swap(cur_s[idx], cur_s[ny * 3 + nx]);
			}
		}
	}
	if (flag) cout << ans;
	else cout << "-1";
	return 0;
}