#include <vector>
using namespace std;
typedef vector<int> vi;
class KiwiJuiceEasy {
public:
	vi thePouring(vi capacities, vi bottles, vi fromId, vi toId) {
		int sz = fromId.size();
		for (int i = 0; i < sz; i++) {
			int diff = capacities[toId[i]] - bottles[toId[i]];
			if (diff >= bottles[fromId[i]]) {
				bottles[toId[i]] += bottles[fromId[i]];
				bottles[fromId[i]] = 0;
			}
			else {
				bottles[fromId[i]] -= diff;
				bottles[toId[i]] = capacities[toId[i]];
			}
		}
		return bottles;
	}
};