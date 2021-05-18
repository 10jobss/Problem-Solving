class Solution {
public:
  int findJudge(int n, vector<vector<int>>& trust) {
    int a[1001]={0,}, ans=0;
    for(int i=0; i<(int)trust.size(); ++i)
      a[trust[i][1]]++;
    for(int i=1; i<=n; ++i)
      if(a[i]==n-1) ans=i;
    if(!ans) return -1;
    for(int i=0; i<(int)trust.size(); ++i)
      if(trust[i][0]==ans) return -1;
    return ans;
  }
};
