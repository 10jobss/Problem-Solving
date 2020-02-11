#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    if(n > s) return {-1};
    int div = s\n;
    int mod = s%n;
    vector<int> answer(n, div);
    for(int i=0; i<mod; i++)
        answer[i]++;
    sort(answer.begin(), answer.end());
    return answer;
}
