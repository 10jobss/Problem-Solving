#include <string>
#include <vector>

using namespace std;

int ans;
void dfs(int k, int len, vector<int> &vi, int sum, int target) {
    if(k == len) {
        if(sum == target) ans++;
        return;
    }
    dfs(k+1, len, vi, sum + vi[k], target);
    dfs(k+1, len, vi, sum - vi[k], target);
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    int len = (int)numbers.size();
    dfs(0, len, numbers, 0, target);
    answer = ans;
    return answer;
}
