class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo, hi, mid;
        lo=0, hi=(int)nums.size()-1;
        while(lo<=hi){
            mid=(lo+hi)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>target)
                hi=mid-1;
            else
                lo=mid+1;
        }
        if(hi<0) return nums[lo]>target?lo:lo+1;
        if(lo>=nums.size()) return nums[hi]>taret?hi:lo;
        return nums[hi]>target?hi:hi+1;
    }
};
