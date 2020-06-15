#include <string>
using namespace std;
class ThePalindrome {
public:
	int find(string s) {
		int len = s.length();
		int ans = 0;
		for (int i = len;; i++) {
			bool flag = 1;
			for (int j = 0;j<=i/2; j++) {
				if (i - j - 1 < len && s[j] != s[i - j - 1]) {
					flag = 0;
					break;
				}
			}
			if (flag) {
				ans = i;
				break;
			}
		}
		return ans;
	}
};
