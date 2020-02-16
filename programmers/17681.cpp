#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;
    for(int i = 0; i < n; i++)
    {
        string s = "";
        int k = arr[i] | arr2[i];
        int x = n - 1;
        while(x >= 0)
        {
            s += ((1<<x)&k) ? '#' : ' ';
            x--;
        }
        answer.push_back(s);
    }
    return answer;
}
