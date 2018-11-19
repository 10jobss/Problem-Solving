#include <string>
using namespace std;
class ThePalindrome {
public:
	int find(string s) {
		int len = s.length();
		int lo = 0, hi = len - 1;
		while (lo <= hi) {
			s[lo] == s[hi] ? hi-- : len++;
			lo++;
		}
		return len;
	}
};