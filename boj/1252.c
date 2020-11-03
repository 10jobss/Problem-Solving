#include <stdio.h>
#include <string.h>
char a[81], b[81], c[82];
char aa[81], bb[81];
void reverse(char* s) {
    int len = strlen(s);
    for(int i=0; i<len/2; i++) {
        char tmp = s[i];
        s[i] = s[len-1-i];
        s[len-1-i] = tmp;
    }
}
void remove_zero(char* dst, char* src) {
    int idx = 0, flg = 0, len = strlen(src);
    for(int i=0; i<len; i++) {
        if(!flg && src[i]=='0') continue;
        flg=1;
        dst[idx++] = src[i];
    }
    if(flg)
        dst[++idx] = '\0';
    else {
        dst[0] = '0';
        dst[1] = '\0';
    }
}
int main(void) {
    int i, len_aa, len_bb, mx, mn, cr=0;
    scanf("%s%s",a,b);
    remove_zero(aa, a);
    remove_zero(bb, b);
    if(!strcmp(aa,"0") && !strcmp(bb, "0")) {
        puts("0");
        return 0;
    }
    len_aa = strlen(aa);
    len_bb = strlen(bb);
    mx = len_aa < len_bb ? len_bb : len_aa;
    mn = len_aa < len_bb ? len_aa : len_bb;
    reverse(aa);
    reverse(bb);
    for(i=0; i<mn; i++) {
        int x = aa[i] - '0';
        int y = bb[i] - '0';
        char bit = '0';
        if((x+y+cr)&1)
            bit = '1';
        c[i] = bit;
        if((x+y+cr)>1)
            cr = 1;
        else
            cr = 0;
    }
    for(;i<mx; i++) {
        if(aa[i]) {
            int x = aa[i] - '0';
            int z = x + cr;
            char cc;
            if(z==2) {
                cr = 1;
            } else {
                cr = 0;
            }
            if(!z || z==2)
                cc = '0';
            else
                cc = '1';
            c[i] = cc;
        }
        else {
            int x = bb[i] - '0';
            int z = x + cr;
            char cc;
            if(z==2) {
                cr = 1;
            } else {
                cr = 0;
            }
            if(!z || z==2)
                cc = '0';
            else
                cc = '1';
            c[i] = cc;
        }
    }
    if(cr) c[i] = '1';
    reverse(c);
    printf("%s", c);
    return 0;
}
