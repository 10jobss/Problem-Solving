/*
problem : https://www.acmicpc.net/problem/1525
solution :
	BFS를 이용한 완전탐색 문제
	메모리 제한이 16MB여서 까다로웠음
	상태를 무엇으로 저장하느냐가 관건
	string 사용시 메모리초과... 0-->9로 바꾸고 int형으로 저장하는 방법으로 생각
	s_i 함수에서 예외처리 안하고 마지막에 ret/10을 return했는데 integer overflow 발생
	i==8일때 예외처리함
	map을 이용한 풀이로 다시 풀어보기, kks227님 코드 확인
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