#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef vector<string> vs;
class InterestingParty {
public:
	int bestInvitation(vs first, vs second) {
		map<string, int> mp;
		int mx = 0, sz = first.size();
		for (int i = 0; i<sz; i++) {
			mp[first[i]]=0;
			mp[second[i]]=0;
		}
		for (int i = 0; i<sz; i++) {
			mp[first[i]]++;
			mp[second[i]]++;
		}
		for (auto it = mp.begin(); it != mp.end(); it++)
			mx = max(mx, it->second);
		return mx;
	}
};