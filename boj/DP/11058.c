/*
Problem : https://icpc.me/11058
Author: 10jobss
Time complexity: O(N^2)
solution :
	DP
	한 달전에는 화면, 버퍼, 캐시 상태를 노드로 풀었는데 MLE가 났다
	대략 상태가 3가지이고 깊이가 100인 트리 형태이기 때문에 큐가 터진 것 같다

	d[i] = i번 버튼 누를 때 화면에 출력된 A의 최대 갯수
	버퍼가 비어있는 경우 ctrl V는 ctrl C, ctrl A와 함께 사용해야한다
	
	따라서 d[i] = max(d[i-1]+1, (k-1)*d[i-k]) (단, k는 2<k<i)
	
	답의 범위가 int를 벗어나기 때문에 주의!
*/
#include <stdio.h>
typedef long long ll;
ll d[101];
ll f(int k) {
	if (k<4) {
		d[k] = k;
		return d[k];
	}
	if (d[k]) return d[k];
	d[k] = f(k - 1) + 1;
	ll ret = 0LL;
	for (int i = 3; i<k; i++) {
		ll tmp = (i - 1)*f(k - i);
		ret = ret<tmp ? tmp : ret;
	}
	d[k] = d[k]<ret ? ret : d[k];
	return d[k];
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%lld", f(n));
	return 0;
}