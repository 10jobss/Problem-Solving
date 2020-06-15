#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
class Cryptography {
public:
	ll encrypt(vi numbers) {
		ll ret = 1LL;
		sort(numbers.begin(),numbers.end());
		numbers[0]++;
		for (int x : numbers)
			ret *= x;
		return ret;
	}
};