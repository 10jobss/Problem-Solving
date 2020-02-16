#include <string>

using namespace std;

int solution(string dartResult)
{
    int answer = 0;
    int cnt = 0;
    int a[3] = {0, };
    int k = -1;
    for(int i = 0; i < darResult.size(); i++)
    {
        char c = dartResult[i];
        if('0' <= c && c <= '9')
        {
            int x = (c - '0');
            if('0' <= dartResult[i+1] && dartResult[i+1] <= '9')
            {
                x = x*10 + (dartResult[i+1] - '0');
                i++;
            }
            a[++k] = x;
        }

        if(c == 'D')
            a[k] *= a[k];
        else if(c == 'T')
            a[k] = a[k] * a[k] *  a[k];
        
        if(c == '*')
        {
            a[k] *= 2;
            if(k) a[k-1] *= 2;
        }
        else if(c == '#')
            a[k] = -a[k];
    }
    for(int i = 0; i < 3; i++)
        answer += a[i];
    return answer;
}
