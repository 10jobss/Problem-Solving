/*
	problem : https://www.acmicpc.net/problem/9019
	solution :
	BFS�� �̿��� ����Ž�� ����
	���ڸ� node�� �����ϰ� D,S,L,R ���� �� ���ο� ���ڸ� �ڽ����� ����
	append ��� �ƴ� ����
	L, R�� �� ������ ����� �� �־���, ���� ������ ��
*/
#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#define MOD 10000
using namespace std;
typedef pair<int, string> pis;
bool chk[10000];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tc, a, b;
	cin >> tc;
	while (tc--) {
		memset(chk, 0, sizeof(chk));
		cin >> a >> b;
		string ans = "";
		queue<pis> q;
		q.push({ a,"" });
		chk[a] = true;
		while (1) {
			int cur = q.front().first;
			string cmd = q.front().second;
			q.pop();
			if (cur == b) {
				ans = cmd;
				break;
			}
			if (!chk[(2 * cur)%MOD]) {
				chk[(2 * cur)%MOD] = true;
				q.push({ (2 * cur) % MOD, cmd + "D" });
			}
			if (!cur && !chk[9999]) {
				chk[9999] = true;
				q.push({ 9999, cmd + "S" });
			}
			else if (cur && !chk[cur - 1]) {
				chk[cur - 1] = true;
				q.push({ cur - 1,cmd + "S" });
			}
			if ((cur - (cur / 1000) * 1000) * 10 + cur / 1000 < 10000 && !chk[(cur - (cur / 1000) * 1000) * 10 + cur / 1000]) {
				chk[(cur - (cur / 1000) * 1000) * 10 + cur / 1000] = true;
				q.push({ (cur - (cur / 1000) * 1000) * 10 + cur / 1000, cmd + "L" });
			}
			if ((cur - (cur % 10)) / 10 + (cur % 10) * 1000 < 10000 && !chk[(cur - (cur % 10)) / 10 + (cur % 10) * 1000]) {
				chk[(cur - (cur % 10)) / 10 + (cur % 10) * 1000] = true;
				q.push({ (cur - (cur % 10)) / 10 + (cur % 10) * 1000 ,cmd + "R" });
			}
		}
		cout << ans << '\n';
	}
	return 0;
}