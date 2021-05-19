class Solution {
public:
  bool f(vector<int>& vi, vector<int>& chk, int n, int k){
    if(k==n-1) return 1;
    if(chk[k]) return chk[k]>0;
    for(int i=vi[k]; i>0; --i){
      if(k+i>=n) continue;
      if(chk[k+i]) continue;
      if(f(vi, chk, n, k+i)){
        chk[k] = 1;
        return 1;
      }
    }
    chk[k] = -1;
    return 0;
  }
  bool canJump(vector<int>& nums) {
    int n = (int)nums.size();
    vector<int> chk(n, 0);
    return f(nums, chk, n, 0);
  }
};
