class Solution {
public:
    int f(vector<int>& nums, int lo, int hi) {
        vector<int> d(nums.size(), 0);
        d[lo] = nums[lo];
        d[lo+1] = std::max(nums[lo], nums[lo+1]);
        for(int i=lo+2; i<hi; i++) {
            d[i] = std::max(d[i-2] + nums[i], d[i-1]);
        }
        return d[hi-1];
    }
    int rob(vector<int>& nums) {
        int n = (int)nums.size();
        if(!n) return 0;
        if(n==1) return nums[0];
        if(n==2) return std::max(nums[0], nums[1]);
        return std::max(f(nums, 0, n-1), f(nums, 1, n));
    }
};
