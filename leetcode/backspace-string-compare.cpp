class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s, t;
        string ss = "", tt = "";
        for(char c : S) {
            if(c != '#') s.push(c);
            else if(!s.empty()) s.pop();
        }
        for(char c : T) {
            if(c != '#') t.push(c);
            else if(!t.empty()) t.pop();
        }
        while(!s.empty()) {
            ss += s.top();
            s.pop();
        }
        while(!t.empty()) {
            tt += t.top();
            t.pop();
        }
        return ss == tt;
    }
}
