#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll f[100], r[100];
int main(){
    int n, i, rr, ff;
    ll k;
    scanf("%d", &n);
    vector<ll> vi(n);
    for(int i=0; i<n; i++) scanf("%lld", &vi[i]);
    sort(vi.begin(), vi.end());
    k=vi[n-1];
    for(i=0; i<n; i++){
        if(!(k%3LL) && find(vi.begin(), vi.end(), k/3LL) != vi.end()){
            r[i]=k/3LL;
            k/=3LL;
        }else if(find(vi.begin(), vi.end(), k*2LL) != vi.end()){
            r[i]=k*2LL;
            k*=2LL;
        }
    }
    rr=i;
    k=vi[n-1];
    for(i=0; i<n; i++){
        if(!(k%2LL) && find(vi.begin(), vi.end(), k/2LL) != vi.end()){
            f[i]=k/2LL;
            k/=2LL;
        }else if(find(vi.begin(), vi.end(), k*3LL) != vi.end()){
            f[i]=k*3LL;
            k*=3LL;
        }
    }
    ff=i;
    reverse(f, f+ff);
    for(i=0; i<ff; i++) if(f[i]) printf("%lld ", f[i]);
    printf("%lld ", vi[n-1]);
    for(i=0; i<rr; i++) if(r[i]) printf("%lld ", r[i]);
    return 0;
}
