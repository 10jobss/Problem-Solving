#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    const long long MOD = 1234567;
    long long x = 0LL, y = 1LL, tmp;
    for(int i=0; i<n; i++) {
        answer = ((x%MOD) + (y%MOD))%MOD;
        tmp = y;
        y = answer;
        x = tmp;
    }
    return answer;
}
