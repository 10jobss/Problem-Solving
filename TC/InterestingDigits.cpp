#include <vector>
#include <string>
using namespace std;
typedef vector<int> vi;
class InterestingDigits {
public:
	vi digits(int base) {
		vi ret;
		for (int i = 2; i < base; i++) {
			bool flag = 0;
			for (int j = 1;; j++) {
				int val = i*j;
				vi a;
				while (val) {
					a.push_back(val%base);
					val /= base;
				}
				if (a.size() > 3) break;
				int num = 0, sz=a.size();
				for (int x : a)
					num += x;
				if (num%i) {
					flag = 0;
					break;
				}
				else
					flag = 1;
			}
			if (flag) ret.push_back(i);
		}
		return ret;
	}
};