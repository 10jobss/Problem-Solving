/*
Problem : https://www.acmicpc.net/problem/3967
Author: 10jobss
Time complexity: ??????
solution :
	Backtracking
	input만 2차원 배열로 받고 12개 칸을 1차원 배열로 관리했다
	reset해주는 위치랑 해당 조건을 만족했을 때 탈출시키는 위치를 조심해야 겠다
*/
#include <cstdio>
char in[5][9];
int a[12];
bool chk[12];
bool flag = 0;
bool ss() {
	int aa = a[1] + a[2] + a[3] + a[4];
	int bb = a[7] + a[8] + a[9] + a[10];
	int cc = a[1] + a[5] + a[8] + a[11];
	int dd = a[4] + a[6] + a[9] + a[11];
	int ee = a[0] + a[2] + a[5] + a[7];
	int ff = a[0] + a[3] + a[6] + a[10];
	return aa == 26 && bb == 26 && cc == 26 && dd == 26 && ff == 26;
}
void solve(int k) {
	if (k == 12) {
		flag = ss();
		return;
	}
	if (a[k]) solve(k + 1);
	else {
		for (int i = 0; i < 12; i++) {
			if (!chk[i]) {
				chk[i] = 1;
				a[k] = i + 1;
				solve(k + 1);
				if (flag) return;
				chk[i] = a[k] = 0;
			}
		}
	}
}
int main() {
	int idx = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			scanf(" %c", &in[i][j]);
			if (in[i][j] == '.') continue;
			if (in[i][j] != 'x') {
				chk[in[i][j] - 'A'] = 1;
				a[idx] = in[i][j] - 'A' + 1;
			}
			idx++;
		}
	}
	solve(0);
	idx = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			if (in[i][j] == '.') continue;
			if (in[i][j] == 'x') {
				in[i][j] = a[idx] - 1 + 'A';
			}
			idx++;
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) printf("%c", in[i][j]);
		puts("");
	}
	return 0;
}