/*
Problem : https://www.acmicpc.net/problem/1208
Author: 10jobss
Time complexity: ???
solution :
	N=20인 https://www.acmicpc.net/problem/1182 문제 같은 경우는
	Bitmask나 재귀 호출로 모든 경우를 다해보면 가능하지만
	이 문제는 N=40이기 때문에 2^40 이므로 시간내에 풀 수 없었다

	기본적인 아이디어는 입력 배열을 2부분으로 나누어서
	각각의 부분집합을 생성 후 조합해 보는 것이었다
	
	처음에는 두 부분으로 나눈 부분집합을 다시 이중 for문으로 해서 틀렸다
	(기껏 나눈걸 2^20 * 2^20 으로 다시 합친 꼴)
	이걸 2^20으로 줄일 수 있는 건 한 부분집합에서 합이 x인 경우
	나머지에서 S-x인 값만 찾아주면 되었다
	이론상으론 포인터 두개로 이분탐색하면 되지만
	STL에 upper_bound와 lower_bound가 있어서 이를 활용했다
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
	int n, s;
	scanf("%d%d", &n, &s);
	vector<int> a(n / 2), b(n - n / 2);
	for (int i = 0; i < n / 2; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n - n / 2; i++) scanf("%d", &b[i]);
	vector<int> aa, bb;
	for (int i = 0; i < (1 << (n / 2)); i++) {
		int sum = 0;
		for (int j = 0; j < n / 2; j++) if (i&(1 << j)) sum += a[j];
		aa.push_back(sum);
	}
	for (int i = 0; i < (1 << (n - n / 2)); i++) {
		int sum = 0;
		for (int j = 0; j < n - n / 2; j++) if (i&(1 << j)) sum += b[j];
		bb.push_back(sum);
	}
	sort(bb.begin(), bb.end());
	ll ans = 0LL;
	for (int i = 0; i < aa.size(); i++) {
		vector<int>::iterator hi = upper_bound(bb.begin(), bb.end(), s - aa[i]);
		vector<int>::iterator lo = lower_bound(bb.begin(), bb.end(), s - aa[i]);
		ans += hi - lo;
	}
	if (!s) ans--;
	printf("%lld", ans);
	return 0;
}