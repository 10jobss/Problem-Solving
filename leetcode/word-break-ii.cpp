class Solution {
public:
  int f(vector<string>& wordDict, string& str){
    for(string w : wordDict)
      if(w == str) return 1;
    return 0;
  }
  void solve(string &s, vector<string>& wordDict, vector<string>& seg, vector<string>& ans, int idx){
    if(idx == s.size()){
      string str = "";
      for(string w : seg)
        str += (w + " ");
      str = str.substr(0, str.size()-1);
      ans.push_back(str);
      return;
    }
    for(int i=1; idx+1<=s.size(); ++i){
      string tmp = s.substr(idx, i);
      if(f(wordDict, tmp)){
        seg.push_back(tmp);
        solve(s, wordDict, seg, ans, idx+i);
        seg.pop_back();
      }
    }
  }
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    vector<string> ans, seg;
    solve(s, wordDict, seg, ans, 0);
    return ans;
  }
};
