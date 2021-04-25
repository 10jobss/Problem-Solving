#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 500
#define INF 987654321
using namespace std;
typedef pair<int, int> pii;
vector<pii > vpii[MAX];
vector<int> vvi[MAX];
int n, m, s, d;
int dist[MAX], adj[MAX][MAX];
void dijk(){
    for(int i=0; i<n; i++)
        dist[i] = INF;
    dist[s] = 0;
    priority_queue<pii > pq;
    pq.push({dist[s], s});
    while(!pq.empty()){
        int cur = pq.top().second;
        int cw = -pq.top().first;
        pq.pop();
        for(int i=0; i<vpii[cur].size(); i++){
            int next = vpii[cur][i].second;
            int nw = vpii[cur][i].first;
            if(adj[cur][next]<0) continue;
            if(dist[next] > cw + nw){
                dist[next] = cw + nw;
                pq.push({-dist[next], next});
                vvi[next].clear();
                vvi[next].push_back(cur);
            } else if(dist[next] == cw + nw){
                vvi[next].push_back(cur);
            }
        }
    }
}
void bfs(){
    int chk[MAX];
    memset(chk, 0, sizeof(chk));
    queue<int> q;
    chk[d] = 1;
    q.push(d);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0; i<vvi[cur].size(); i++){
            int next = vvi[cur][i];
            adj[next][cur] = -1;
            if(chk[next]) continue;
            chk[next] = 1;
            q.push(next);
        }
    }
}
int main(){
    while(scanf("%d%d", &n, &m) && (n||m)){
        for(int i=0; i<n; i++){
            vpii[i].clear();
            vvi[i].clear();
        }
        memset(adj, 0, sizeof(adj));
        scanf("%d%d", &s, &d);
        int u, v, p;
        while(m--){
            scanf("%d%d%d", &u, &v, &p);
            vpii[u].push_back({p, v});
        }
        dijk();
        bfs();
        dijk();
        dist[d] == INF ? puts("-1") : printf("%d\n", dist[d]);
    }
    return 0;
}
