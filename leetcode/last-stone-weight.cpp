class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int s : stones)
            pq.push(s);
        while(!pq.empty()) {
            int y = pq.top();
            pq.pop();
            if(pq.empty()) return y;
            int x = pq.top();
            pq.push(y-x);
        }
        return 0;
    }
};
