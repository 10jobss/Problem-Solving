#include <cstdio>
using namespace std;
typedef long long ll;
ll a[51];
int main(){
    ll n, x, p, ans=0LL;
    scanf("%lld%lld", &n, &x);
    a[0] = 1LL;
    for(int i=1; i<=50; i++)
        a[i] = 2LL*a[i-1] + 1LL;
    p = a[n];
    while(n>=0){
        if(x==p) {
            ans+=a[n-1]+1;
            break;
        }
        if(n==1){
            if(x==p-1) ans++;
            else if(x>=p+1) ans+=3;
            break;
        }
        if(x<p) {
            n--;
            p -= a[n];
        } else {
            n--;
            ans += a[n] + 1;
            p += a[n];
        }
    }
    printf("%lld", ans);
    return 0;
}
