class Solution {
public:
    int min(int x, int y) { return x>y?y:x; }
    int max(int x, int y) { return x>y?x:y; }
    int maxArea(vector<int>& height) {
        int lo = 0, hi = (int)height.size()-1;
        int ans = (hi-lo)*min(height[lo], height[hi]);
        while(lo<hi) {
            if(height[hi] > height[lo]) lo++;
            else hi--;
            ans = max(ans, (hi-lo)*min(height[lo], height[hi]));
        }
        return ans;
    }
};
