#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int lo = 0, hi = people.size() - 1;
    while(lo<=hi) {
        if(people[hi] + people[lo] <= limit)
            lo++;
        hi--;
        answer++;
    }
    return answer;
}
