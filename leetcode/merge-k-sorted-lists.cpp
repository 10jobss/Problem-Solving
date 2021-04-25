class Solution {
public:
    struct cmp{
        bool operator() (ListNode*l, ListNode* r){
            return l->val > r->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists){
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        ListNode* ans;
        ListNode* cur;
        for(ListNode* x : lists){
            cur = x;
            while(cur){
                pq.push(cur);
                cur = cur->next;
            }
        }
        if(pq.empty()) return NULL;
        ans = pq.top();
        cur = ans;
        pq.pop();
        while(!pq.empty()){
            cur->next = pq.top();
            pq.pop();
            cur = cur->next;
        }
        cur->next = nullptr;
        return ans;
    }
};
