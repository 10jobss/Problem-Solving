// map을 사용하면 아래 풀이보다 더 효율적임
class Solution {
public:
    int findIndex(int x, vector<int>& vi){
        int k, n=(int)vi.size();
        for(int i=0; i<n; i++)
            if(v[i]==x){
                k=i;
                break;
            }
        return k;
    }
    int minSwapsCouples(vector<int>& row) {
        int cnt=0, n=(int)row.size(), target, k;
        for(int i=0; i<n; i+=2){
            target = row[i]&1 ? row[i]-1 : row[i]+1;
            if(target==row[i+1]) continue;
            k = findIndex(target, row);
            swap(row[i+1], row[k]);
            cnt++;
        }
        return cnt;
    }
};
