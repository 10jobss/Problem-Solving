/*
problem : https://www.acmicpc.net/problem/9019
solution :
	BFS를 이용한 완전탐색 문제
	숫자를 node로 생각하고 D,S,L,R 수행 후 새로운 숫자를 자식으로 생각
	append 사용 아님 주의
	L, R을 더 간단히 계산할 수 있었음, 조건 조심할 것
	string 연산 너무 속도가 느림, 거꾸로 추적해서 답에 도달할 수도 있음
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
