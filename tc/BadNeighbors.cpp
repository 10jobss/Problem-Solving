#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef vector<int> vi;
int d[50];
class BadNeighbors {
public:
	int maxDonations(vi donations) {
		int n = (int)donations.size();
		d[0] = donations[0];
		d[1] = max(donations[0], donations[1]);
		for (int i = 2; i<n - 1; i++)
			d[i] = max(d[i - 1], d[i - 2] + donations[i]);
		int ans1 = d[n - 2];
		memset(d, 0, sizeof(d));
		d[1] = donations[1];
		for (int i = 2; i<n; i++)
			d[i] = max(d[i - 1], d[i - 2] + donations[i]);
		return max(ans1, d[n - 1]);
	}
};