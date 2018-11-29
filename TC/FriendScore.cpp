#include <string>
#include <vector>
using namespace std;
class FriendScore {
public:
	int highestScore(vector<string> friends) {
		int ans = 0;
		int n = friends[0].length();
		for (int i = 0; i < n; i++) {
			bool chk[51] = {};
			int tmp = 0;
			for (int j = 0; j < n; j++) {
				if (friends[i][j] == 'Y' && !chk[j]) {
					chk[j] = 1;
					tmp++;
				}
			}
			for (int j = 0; j < n; j++) {
				if (friends[i][j] == 'Y') {
					for (int k = 0; k < n; k++) {
						if (k!=i&&friends[j][k] == 'Y' && !chk[k]) {
							chk[k] = 1;
							tmp++;
						}
					}
				}
			}
			ans = ans < tmp ? tmp : ans;
		}
		return ans;
	}
};