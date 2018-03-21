/*
Problem : https://www.acmicpc.net/problem/1941
Author: 10jobss
Time complexity: O(2^25*5^2)
solution :
	제한시간이 2초인데 1.9초가 나왔다.. 좋은 문제풀이는 아니지만 배운점이 있어서 기록을 남김
	1. 25C7 구현 2. 예외처리 3. dfs로 연결요소 확인
	일단 25C7을 구하는 것을 비트마스크를 이용했다
	길이가 7이 아닌경우와 이다솜 그룹의 수가 4미만인 경우를 제외
	(근데 7을 넘어가는 순간 break를 하지 않으면 TLE가 나왔다..)
	chk[i]==2는 같은 그룹이고 방문안한 상태
	chk[i]==3은 같은 그룹이고 방문한 상태
	연결요소 내부 아무요소나 dfs 방문후
	chk[i]가 3이 아닌 것이 있으면 칠공주를 결성할 수 없음
	더 나은 풀이는 http://baactree.tistory.com/5 참고

	참고로 std::next_permutation의 경우 집합의 크기를 n이라 할때
	n개의 원소가 모두 다른 경우는 O(n!)이지만
	중복 원소가 존재하면 O(n!) 미만이다.
*/
#include <cstdio>
#include <cstring>
int ans;
char c[5][5];
int chk[25];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
void dfs(int y, int x) {
	chk[y * 5 + x] = 3;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && ny < 5 && nx >= 0 && nx < 5 && chk[ny * 5 + nx] == 2) {
			dfs(ny, nx);
		}
	}
}
int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) scanf(" %c", &c[i][j]);
	}
	for (int i = 0; i < (1 << 25); i++) {
		int len = 0, ss = 0;
		bool bb = true;
		for (int j = 0; j < 25; j++) {
			if (i&(1 << j)) {
				if (c[j / 5][j % 5] == 'S') ss++;
				len++;
			}
			if (len > 7) {
				bb = false;
				break;
			}
		}
		if (!bb) continue;
		if (len != 7 || ss < 4) continue;
		memset(chk, 0, sizeof(chk));
		int idx = 0, g[7] = { 0 };
		for (int j = 0; j < 25; j++) {
			if (i&(1 << j)) {
				g[idx++] = j;
				chk[j] = 2;
			}
		}
		dfs(g[0] / 5, g[0] % 5);
		bool flag = true;
		for (int j = 0; j < 7; j++) {
			if (chk[g[j]] != 3) {
				flag = false;
				break;
			}
		}
		if (!flag) continue;
		ans++;
	}
	printf("%d", ans);
	return 0;
}