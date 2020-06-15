#include <string>
using namespace std;
int a[4][8] = { {1,2,3,4,5,6,7,8},
			   {1,2,3,4,9,10,11,12},
			   {1,2,5,6,9,10,13,14},
			   {1,3,5,7,9,11,13,15} };
int chk[17];
class NumberMagicEasy {
public:
	int theNumber(string answer) {
		int ret = 0, tmp = -1;
		for (int i = 0; i < 4; i++) {
			if (answer[i] == 'Y')
				for (int j = 0; j < 8; j++)
					chk[a[i][j]] += (chk[a[i][j]] == -1) ? 0 : 1;
			else 
				for (int j = 0; j < 8; j++)
					chk[a[i][j]] = -1;
		}
		for (int i = 1; i <= 16; i++) {
			if (chk[i] != -1 && tmp < chk[i])
				ret = i, tmp = chk[i];
		}
		return ret;
	}
};