#include <string>
#include <vector>
#include <cstring>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int i, a[26];
    memset(a, -1, sizeof(a));
    for(i=0; i<skill.size(); i++)
        a[skill[i]-'A'] = i;
    for(string s : skill_trees) {
        string tmp = "";
        for(char c : s)
            if(a[c-'A'] >= 0) tmp += c;
        for(i=0; i<tmp.size(); i++)
            if(skill[i] != tmp[i]) break;
        answer += (i == tmp.size());
    }
    return answer;
}
