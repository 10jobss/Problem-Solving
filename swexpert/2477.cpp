#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef struct p {
	int num, rcn, rpn, ft;
	p() {}
	p(int nn, int cc, int pp, int ff) : num(nn), rcn(cc), rpn(pp), ft(ff) {}
}P;
int ans;
int n, m, k, A, B;
int a[9], b[9], t[1000];
P arr[1000];
void _init() {
	ans = 0;
	memset(arr, 0, sizeof(arr));
}
void input() {
	scanf("%d%d%d%d%d", &n, &m, &k, &A, &B);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) scanf("%d", &b[i]);
	for (int i = 0; i < k; i++) {
		arr[i].num = i + 1;
		scanf("%d", &t[i]);
	}
}
bool cmp(const P &p1, const P &p2) {
	if (p1.ft == p2.ft) {
		return p1.rcn < p2.rcn;
	}
	else {
		return p1.ft < p2.ft;
	}
}
void solve() {
	int af[9] = { 0 };
	int bf[9] = { 0 };
	for (int i = 0; i < k; i++) {
		bool flag = 0;
		for (int j = 0; j < n; j++) {
			if (af[j] <= t[i]) {
				flag = 1;
				arr[i].rcn = j + 1;
				af[j] = arr[i].ft = t[i] + a[j];
				break;
			}
		}
		if (!flag) {
			int mn = 987654321;
			for (int j = 0; j < n; j++) {
				mn = min(mn, af[j]);
			}
			for (int j = 0; j < n; j++) {
				if (af[j] == mn) {
					arr[i].rcn = j + 1;
					af[j] = arr[i].ft = af[j] + a[j];
					break;
				}
			}
		}
	}
	sort(arr, arr + k, cmp);
	for (int i = 0; i < k; i++) {
		bool flag = 0;
		for (int j = 0; j < m; j++) {
			if (bf[j] <= arr[i].ft) {
				flag = 1;
				arr[i].rpn = j + 1;
				bf[j] = arr[i].ft + b[j];
				break;
			}
		}
		if (!flag) {
			int mn = 987654321;
			for (int j = 0; j < m; j++) {
				mn = min(mn, bf[j]);
			}
			for (int j = 0; j < m; j++) {
				if (bf[j] == mn) {
					arr[i].rpn = j + 1;
					bf[j] = bf[j] + b[j];
					break;
				}
			}
		}
	}
	for (int i = 0; i < k; i++) {
		if (arr[i].rcn == A&&arr[i].rpn == B) ans += arr[i].num;
	}
}
int main() {
	//setbuf(stdin, NULL);
	//freopen("sample_input.txt", "r", stdin);
	int tc;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		_init();
		input();
		solve();
		printf("#%d %d\n", t, ans ? ans : -1);
	}
	return 0;
}