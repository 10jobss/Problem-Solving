/*
Problem : https://www.acmicpc.net/problem/1753
Author: 10jobss
Time complexity: ??
solution :
	2048(Easy)문제랑 마찬가지로 처음에 BFS로 풀었다
	2048문제는 메모리 제한이 512MB이고 이 문제는 128MB 였다
	스도쿠 문제가 맵도 작고 더 간단하다고 생각했는데 MLE.. 
	9*9여서 Backtracking으로 가장 무식하게 풀었다
	채워야 하는 칸의 좌표를 vector에 저장하고
	(행, 열 index가 0~8까지이므로 row+col*10으로 좌표를 압축했다)
	index를 기준으로 탐색했다
	행, 열, 3*3 사각형에서 사용한 숫자를 확인하고 없는 숫자를 하나씩 넣어가면서 재귀호출
	복귀시에는 0으로 해제해주었다
	인덱스를 실수하지말자..
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
