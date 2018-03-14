/*
Problem : https://www.acmicpc.net/problem/1753
Author: 10jobss
Time complexity: ??
solution :
	9*9���� Backtracking���� ���� �����ϰ� Ǯ����
	ä���� �ϴ� ĭ�� ��ǥ�� vector�� �����ϰ�
	(��, �� index�� 0~8�����̹Ƿ� row+col*10���� ��ǥ�� �����ߴ�)
	index�� �������� Ž���ߴ�
	��, ��, 3*3 �簢������ ����� ���ڸ� Ȯ���ϰ� ���� ���ڸ� �ϳ��� �־�鼭 ���ȣ��
	���ͽÿ��� 0���� �������־���
	�ε����� �Ǽ���������..
*/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int a[9][9], ans[9][9];
vector<int> vi;
void solve(int idx) {
	if (idx==vi.size()) {
		memcpy(ans, a, sizeof(a));
		return;
	}
	int cy = vi[idx] % 10, cx = vi[idx] / 10;
	bool chk[10] = { 0 };
	for (int i = 0; i < 9; i++) {
		if (a[i][cx]) chk[a[i][cx]] = 1;
		if (a[cy][i]) chk[a[cy][i]] = 1;
	}
	if (cy % 3 == 0 && cx % 3 == 0) {
		if (a[cy + 1][cx + 1]) chk[a[cy + 1][cx + 1]] = 1;
		if (a[cy + 1][cx + 2]) chk[a[cy + 1][cx + 2]] = 1;
		if (a[cy + 2][cx + 1]) chk[a[cy + 2][cx + 1]] = 1;
		if (a[cy + 2][cx + 2]) chk[a[cy + 2][cx + 2]] = 1;
	}
	if (cy % 3 == 0 && cx % 3 == 1) {
		if (a[cy + 1][cx - 1]) chk[a[cy + 1][cx - 1]] = 1;
		if (a[cy + 2][cx + -1]) chk[a[cy + 2][cx - 1]] = 1;
		if (a[cy + 1][cx + 1]) chk[a[cy + 1][cx + 1]] = 1;
		if (a[cy + 2][cx + 1]) chk[a[cy + 2][cx + 1]] = 1;
	}
	if (cy % 3 == 0 && cx % 3 == 2) {
		if (a[cy + 1][cx - 1]) chk[a[cy + 1][cx - 1]] = 1;
		if (a[cy + 2][cx - 1]) chk[a[cy + 2][cx - 1]] = 1;
		if (a[cy + 1][cx - 2]) chk[a[cy + 1][cx - 2]] = 1;
		if (a[cy + 2][cx - 2]) chk[a[cy + 2][cx - 2]] = 1;
	}
	if (cy % 3 == 1 && cx % 3 == 0) {
		if (a[cy - 1][cx + 1]) chk[a[cy - 1][cx + 1]] = 1;
		if (a[cy - 1][cx + 2]) chk[a[cy - 1][cx + 2]] = 1;
		if (a[cy + 1][cx + 1]) chk[a[cy + 1][cx + 1]] = 1;
		if (a[cy + 1][cx + 2]) chk[a[cy + 1][cx + 2]] = 1;
	}
	if (cy % 3 == 1 && cx % 3 == 1) {
		if (a[cy - 1][cx - 1]) chk[a[cy - 1][cx - 1]] = 1;
		if (a[cy - 1][cx + 1]) chk[a[cy - 1][cx + 1]] = 1;
		if (a[cy + 1][cx - 1]) chk[a[cy + 1][cx - 1]] = 1;
		if (a[cy + 1][cx + 1]) chk[a[cy + 1][cx + 1]] = 1;
	}
	if (cy % 3 == 1 && cx % 3 == 2) {
		if (a[cy - 1][cx - 2]) chk[a[cy - 1][cx - 2]] = 1;
		if (a[cy - 1][cx - 1]) chk[a[cy - 1][cx - 1]] = 1;
		if (a[cy + 1][cx - 2]) chk[a[cy + 1][cx - 2]] = 1;
		if (a[cy + 1][cx - 1]) chk[a[cy + 1][cx - 1]] = 1;
	}
	if (cy % 3 == 2 && cx % 3 == 0) {
		if (a[cy - 2][cx + 1]) chk[a[cy - 2][cx + 1]] = 1;
		if (a[cy - 2][cx + 2]) chk[a[cy - 2][cx + 2]] = 1;
		if (a[cy - 1][cx + 1]) chk[a[cy - 1][cx + 1]] = 1;
		if (a[cy - 1][cx + 2]) chk[a[cy - 1][cx + 2]] = 1;
	}
	if (cy % 3 == 2 && cx % 3 == 1) {
		if (a[cy - 2][cx - 1]) chk[a[cy - 2][cx - 1]] = 1;
		if (a[cy - 1][cx - 1]) chk[a[cy - 1][cx - 1]] = 1;
		if (a[cy - 2][cx + 1]) chk[a[cy - 2][cx + 1]] = 1;
		if (a[cy - 1][cx + 1]) chk[a[cy - 1][cx + 1]] = 1;
	}
	if (cy % 3 == 2 && cx % 3 == 2) {
		if (a[cy - 1][cx - 1]) chk[a[cy - 1][cx - 1]] = 1;
		if (a[cy - 1][cx - 2]) chk[a[cy - 1][cx - 2]] = 1;
		if (a[cy - 2][cx - 1]) chk[a[cy - 2][cx - 1]] = 1;
		if (a[cy - 2][cx - 2]) chk[a[cy - 2][cx - 2]] = 1;
	}
	for (int i = 1; i < 10; i++) {
		if (!chk[i]) {
			a[cy][cx] = i;
			solve(idx + 1);
			a[cy][cx] = 0;
		}
	}
}
int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &a[i][j]);
			if (!a[i][j]) vi.push_back(i + j * 10);
		}
	}
	solve(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) printf("%d ", ans[i][j]);
		puts("");
	}
	return 0;
}