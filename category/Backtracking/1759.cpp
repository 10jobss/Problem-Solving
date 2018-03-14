/*
Problem : https://www.acmicpc.net/problem/1759
Author: 10jobss
Time complexity: ?? c개중 l개 선택이니까.. O(cCl) 아닐까??
solution :
	Backtracking을 이용한 풀이
	solve(현재 보고있는 idx, 정답 문자열의 길이, 모음 수, 자음 수)
	항상 Backtracking 문제는 답을 어디에 적어두는지가 헷갈림
	-1부터 호출 시 반복문을 애초에 +1부터 돌리든가
	0부터 호출 시 반복문은 자기 자신, 재귀 호출 시 +1 하든가
	
	반복문안에 ans의 포인터 정보는 len이 가지고 있으니 헷갈리지 말 것
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int l, c;
char s[16], ans[16];
void solve(int idx, int len, int yy, int xx) {
	if (len == l) {
		if (yy >= 1 && xx >= 2) puts(ans);
		return;
	}
	for (int i = idx; i < c; i++) {
		ans[len] = s[i];
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			solve(i+1, len + 1, yy + 1, xx);
		else
			solve(i+1, len + 1, yy, xx + 1);
	}
}
int main() {
	scanf("%d%d", &l, &c);
	for (int i = 0; i < c; i++) scanf(" %c", &s[i]);
	sort(s, s + c);
	solve(0, 0, 0, 0);
	return 0;
}