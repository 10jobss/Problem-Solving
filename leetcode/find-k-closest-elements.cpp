class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = (int)arr.size();
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int> > pq;
        for(int i=0; i<n; i++){
            if(pq.size() < k)
                pq.push(arr[i]);
            else{
                int y = pq.top();
                if(abs(y-x) > abs(arr[i]-x)){
                    pq.pop();
                    pq.push(arr[i]);
                } else if(abs(y-x)==abs(arr[i]-x) && y>arr[i]){
                    pq.pop();
                    pq.push(arr[i]);
                }
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
