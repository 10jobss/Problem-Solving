#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
int n, m;
vector<pii > vpii[2000 + 1];
int cache[4000 + 1], chk[2000 +1];
int main() {
    int tc;
    scanf("%d", &tc);
    for(int t=1; t<=tc; t++) {
        scanf("%d%d", &n, &m);
        memset(cache, 0, sizeof(cache));
        memset(chk, 0, sizeof(chk));
        for(int i=0; i<n; i++)
            vpii[i].clear();
        for(int i=0; i<m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            vpii[u].push_back({ v,w });
            vpii[v].push_back({ u,w });
            cache[i] = w;
        }
        sort(cache, cache+m);
        int ans = 10001;
        for(int i=0; i<m; i++) {
            int lo = cache[i], hi = 1000, mid;
            while(lo <= hi) {
                mid = (hi + lo)/2;
                memset(chk, 0, sizeof(chk));
                queue<int> q;
                q.push(0);
                chk[0] = 1;
                while(!q.empty()) {
                    int cur = q.front();
                    q.pop();
                    if(cur == n-1) break;
                    for(int j=0; j<(int)vpii[cur].size(); j++) {
                        int next = vpii[cur][j].first;
                        int nw = vpii[cur][j].second;
                        if(chk[next]) continue;
                        if(nw<cache[i] || nw>mid) continue;
                        chk[next] = 1;
                        q.push(next);
                    }
                }
                if(chk[n-1]) {
                    ans = min(ans, mid-cache[i]);
                    hi=mid-1;
                }
                else
                    lo=mid+1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
