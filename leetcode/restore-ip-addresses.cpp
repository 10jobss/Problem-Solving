class Solution {
public:
  void f(string &s, vector<string>& ans, vector<string>& tmp, int k, int idx){
    if(k==4 && idx==s.size()) {
      ans.push_back(tmp[0]+"."+tmp[1]+"."+tmp[2]+"."+tmp[3]);
      return;
    }
    if(k==4 || idx==s.size())
      return;
    for(int i=1; i<=3 && idx+i<=s.size(); ++i) {
      string p = s.substr(idx, i);
      int x = stoi(p);
      if(x>255 || i>=2 && p[0]=='0') break;
      tmp[k] = p;
      f(s, ans, tmp, k+1, idx+i);
      tmp[k] = "";
    }
  }
  vector<string> restoreIpAddresses(string s) {
    vector<string> ans, tmp(4);
    f(s, ans, tmp, 0, 0);
    return ans;
  }
};
