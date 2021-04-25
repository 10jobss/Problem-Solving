class Solution {
public:
   char mp[10][4] = { {0, }, {0, }, {'a','b','c',0}, {'d','e','f',0},
                      {'g','h','i',0}, {'j','k','l',0}, {'m','n','o',0},
                      {'p','q','r','s'}, {'t','u','v',0}, {'w','x','y','z'} };
   vector<string> ans;
   void f(int k, string res, string& s){
       if(k==s.size()){
           if(k>0) ans.push_back(res);
           return;
       }
       int x = s[k] - '0';
       for(int i=0; i<4; i++)
           if(mp[x][i])
               f(k+1, res+mp[x][i], s);
   }
   vector<string> letterCombinations(string digits) {
       f(0, "", digits);
       return ans;
   }
};
