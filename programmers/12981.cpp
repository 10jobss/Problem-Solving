#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_map<string, int> mp;
    for(int i=0; i<(int)words.size(); i++) {
        if(mp[word[i]] >= 1 || i>0 && words[i-1][words[i-1].size()-1] != words[i][0]) {
            answer = { i%n, i/n + 1 };
            break;
        } else {
            mp[words[i]]++;
        }
    }
    if(!answer.size()) {
        answer = { 0, 0 };
    }
    return answer;
}
