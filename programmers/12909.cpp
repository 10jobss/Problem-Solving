#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s) {
    bool answer = true;
    stack<char> st;
    for(char c : s) {
        if(c == '(') st.push(c);
        else {
            if(st.empty()) return false;
            st.pop();
        }
    }
    answer = st.empty() ? true : false;
    return answer;
}
