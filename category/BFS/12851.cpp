/*
problem : https://www.acmicpc.net/problem/12851
solution :
	https://www.acmicpc.net/problem/1697 ���� ��¦ ������ ����
	������ ��ٷο���
	1697���� �ִܽð��� �ٷ� ã���� Ž�� �����ص� ������
	12851�� ���� ��� ����� ���� ������ �ϹǷ� Ž�� ������ �� ����

	1�� ���� - �õ��ߴ� ����� ���� ������ ��ġ�� pair�� node�� �����
	��尡 -1 ������ ������ ���� Ž�� �� +1�� �� �ʿ���� (���ڸ��� ���ư��ϱ� �̷� ���� �ִ� �ð� X)
	if, else �� �ʹ� �������� cutting ���� ������ �޸� �ʰ�, TLE �ݺ�..
	 
	2�� ���� - �ܼ� visit�� �̿��ϸ� ���� ���ϹǷ� visit�迭�� depth�� �̿��ؼ� ����
	�ش� ������ �̹� �湮�� ����� depth�� ���ؼ� depth�� ���ų� '����'(�� ��츦 ����!) enqueue
	depth�� INF�� �ʱ�ȭ �ϴ� ���� �߿����� depth���� ū ��� �� �̻� Ž���� �ʿ䰡 ���� ���� 
	(k�� �湮�ߵ� ���ߵ� �������)
	*2, +1 �� ��� MAX ������ check �ؾ��� RTE�� �ȳ� (������ؼ� 2���̳� RTE)
	MAX�� 2*10^5�� ������ k=10^5 �϶� MAX�� �Ѿ�� k ���� ū �ʿ��� ���� ���� ���� ����
*/
#include <cstdio>
#include <queue>
#include <algorithm>
#define MAX (int)2e+5
#define INF 987654321
using namespace std;
int n, k, depth = INF, c, d[MAX + 1];
queue<int> q;
int main() {
	scanf("%d%d", &n, &k);
	if (n >= k) {
		printf("%d\n1", n - k);
		return 0;
	}
	fill(d, d + MAX, INF);
	q.push(n);
	d[n] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == k) {
			depth = d[cur];
			c++;
			continue;
		}
		if (d[cur] > depth) continue;
		if (cur - 1 >= 0) {
			if (d[cur - 1] == INF) {
				d[cur - 1] = d[cur] + 1;
				q.push(cur - 1);
			}
			else {
				if (d[cur - 1] >= d[cur] + 1) {
					d[cur - 1] = d[cur] + 1;
					q.push(cur - 1);
				}
			}
		}
		if (cur + 1 <= MAX && d[cur + 1] == INF) {
			d[cur + 1] = d[cur] + 1;
			q.push(cur + 1);
		}
		else {
			if (cur + 1 <= MAX && d[cur + 1] >= d[cur] + 1) {
				d[cur + 1] = d[cur] + 1;
				q.push(cur + 1);
			}
		}
		if (2 * cur <= MAX && d[2 * cur] == INF) {
			d[2 * cur] = d[cur] + 1;
			q.push(2 * cur);
		}
		else {
			if (2 * cur <= MAX && d[2 * cur] >= d[cur] + 1) {
				d[2 * cur] = d[cur] + 1;
				q.push(2 * cur);
			}
		}
	}
	printf("%d\n%d", depth, c);
	return 0;
}