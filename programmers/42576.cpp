#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    int i;
    int p_len = (int)participant.size();
    int c_len = (int)completion.size();
    for(i=0; i<p_len; i++) {
        if(i>=c_len || participant[i] != completion[i]) {
            answer = participant[i];
            break;
        }
    }
    return answer;
}
