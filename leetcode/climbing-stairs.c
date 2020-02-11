int climbStairs(int n) {
    int prev = 1, cur = 2, ret;
    for(int i=3; i<=n; i++) {
        ret = cur + prev;
        prev = cur;
        cur = ret;
    }
    ret = n==1 ? 1 : n==2 ? 2 : ret;
    return ret;
}
