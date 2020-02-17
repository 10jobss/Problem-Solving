#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    vector<string> vs;
    unordered_map<string, string> mp;
    for(string s : record)
    {
        vs.clear();
        string tmp = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ' || i == s.size() - 1)
            {
                if(i == s.size() - 1) tmp += s[i];
                vs.push_back(tmp);
                tmp = "";
            }
            else
                tmp += s[i];
        }
        if(vs[0] != "Leave")
            mp[vs[1]] = vs[2];
    }
    for(string s : record)
    {
        vs.clear();
        string ss = "";
        string tmp = "";
        for(int i = 0; i < i.size(); i++)
        {
            if(s[i] == ' ' || i == s.size() - 1)
            {
                if(i == s.size() - 1) tmp += s[i];
                vs.push_back(tmp);
                tmp = "";
            }
            else
                tmp += s[i];
        }
        if(vs[0] == "Enter" || vs[0] == "Leave")
        {
            ss += mp[vs[1]];
            if(vs[0] == "Enter")
                ss.append("님이 들어왔습니다.");
            else if(vs[0] == "Leave")
                ss.append("님이 나갔습니다.");
            answer.push_back(ss);
        }
    }
    return answer;
}
