class Solution
public:
    vecotr<int> twoSum(vector<int> &nums, int target) {
        vector<int> vi;
        int len = (int)nums.size();
        vector<pair<int, int>> vpii;
        for(int i=0; i<len; i++) {
            vpii.push_back({nums[i], i});
        }
        bool trg = false;
        sort(vpii.begin(), vpii.end());
        for(int i=0; i<len; i++) {
            int lo = i+1, hi = len - 1, k, tmp = target - vpii[i].first;
            while(lo <= hi) {
                int mid = (lo + hi) / 2;
                if(vpii[mid].first == tmp) {
                    k = vpii[mid].second;
                    trg = true;
                    break;
                } else if(vpii[mid].first > tmp) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            if(trg) {
                vi.push_back(vpii[i].second);
                vi.push_back(k);
                break;
            }
        }
        return vi;
    }
};
