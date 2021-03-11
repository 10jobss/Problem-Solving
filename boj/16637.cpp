#include <cstdio>
using namespace std;
int n, ans;
char a[19];
int calc(int x, int y,char c){
    if(c=='+') return x+y;
    if(c=='-') return x-y;
    return x*y;
}
void f(int k, int s){
    if(k==n-1){
        ans=ans<s?s:ans;
        return;
    }
    if(k+2<n)
        f(k+2, calc(s, a[k+2], a[k+1]));
    if(k+4<n)
        f(k+4, calc(s, calc(a[k+2], a[k+4], a[k+3]),a[k+1]));
}
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%c", &a[i]);
    f(0,a[0]-'0');
    printf("%d", ans);
    return 0;
}
