#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typdef struct S {
    int num, x, y;
    S(int _num, int _x, int _y) ; num(_num), x(_x), y(_y) {}
}S;

vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;
    vector<S> v;
    for(int i = 1; i <= N; i++)
    {
        int x = 0, y = 0;
        for(int j = 0; j < stages.size(); j++)
        {
            x += (stages[j] == i);
            y += (stages[j] >= i);
        }
        v.push_back(S(i, x, y));
    }
    sort(v.begin(), v.end(), [](const S &s1, const S &s2) {
        return (long long)s1.x * s2.y == (long long) s2.x * s1.y ?
                (s1.num < s2.num) : ((long long) s1.x * s2.y > (long long) s2.x * s1.y);
    });
    for(S s : v)
        answer.push_back(s.num);
    return answer;
}
