/*
Problem : https://www.acmicpc.net/problem/1759
Author: 10jobss
Time complexity: O(C*2^C)
solution :
	C<=15이므로 완전탐색으로 충분히 가능한 문제
	Bitmask를 이용해서 모든 경우를 확인했다 길이가 l과 같지 않으면 확인할 필요가 없다
	Backtracking으로도 풀이 가능하다

	애초에 정렬을 했기 때문에 알파벳 순에 역행하는 문자는 나올 수가 없다
	index 조심!! (배열 왼쪽부터 0인데 bitmask할땐 오른쪽부터 0번 bit인데 어차피 상관없는 것 괜히 헷갈렸음)
	그리고 출력시 scanf는 string을 출력할 수 없다 string은 객체이기 때문에
	하지만 scanf는 주소값을 인자로 받는다
	문자열을 너무 안풀다 보니.. 잊고 있었다
	https://www.acmicpc.net/board/view/21873 여기 답변을 참고
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