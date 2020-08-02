#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    while(n) {
        int r = n%3;
        n /= 3;
        if(!r) {
            r = 4;
            n -= 1;
        }
        answer += (r + '0');
    }
    reverse(answer.begin(), answer.end());
    return answer;
}
