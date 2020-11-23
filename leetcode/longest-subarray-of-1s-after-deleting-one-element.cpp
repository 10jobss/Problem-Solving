class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = 0, tmp = 0, n = (int)nums.size();
        vector<int> d(n, 0);
        vector<int> r(n, 0);
        d[0] = nums[0];
        for(int i=1; i<n; i++) {
            if(nums[i]) d[i] = d[i-1] + 1;
            else d[i] = 0;
        }
        for(int i=0; i<n; i++)
            mx = mx < d[i] ? d[i] : mx;
        mx = mx > 0 ? mx - 1 : 0;
        reverse(nums.begin(), nums.end());
        r[0] = nums[0];
        for(int i=1; i<n; i++) {
            if(nums[i]) r[i] = r[i-1] + 1;
            else r[i] = 0;
        }
        reverse(r.begin(), r.end());
        reverse(nums.begin(), nums.end());
        for(int i=0; i<n; i++) {
            if(nums[i]) continue;
            int sum = 0;
            if(i-1>=0) sum += d[i-1];
            if(i+1<n) sum += r[i+1];
            tmp = tmp < sum ? sum : tmp;
        }
        return tmp > mx ? tmp : mx;
    }
};
