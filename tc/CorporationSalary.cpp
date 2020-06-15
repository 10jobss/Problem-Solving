#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<string> vs;
ll ans;
ll d[50];
int n;
class CorporationSalary {
public:
	ll totalSalary(vs relations) {
		n = (int)relations.size();
		for (int i = 0; i < n; i++) { 
			ans += f(i, relations);
		}
		return ans;
	}
	ll f(int k, vs &rel) {
		if (d[k]) return d[k];
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (rel[k][i] == 'Y') {
				d[k] += f(i, rel);
				cnt++;
			}
		}
		if (!cnt) return 1LL;
		return d[k];
	}
};
