class Solution {
public:
    int n, chk[200];
    vector<vector<int>> vvi;
    void dfs(int v){
        if(chk[v]) return;
        chk[v] = 1;
        for(int i=0; i<n; i++)
            if(i!=v && vvi[v][i] && !chk[i]){
                dfs(i);
            }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vvi = isConnected;
        int cnt = 0;
        n = (int)isConnected.size();
        memset(chk, 0, sizeof(chk));
        for(int i=0; i<n; i++){
            if(!chk[i]){
                cnt++;
                dfs(i);
            }
        }
        return cnt;
    }
};
