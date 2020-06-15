typedef long long ll;
ll d[51];
class HandsShaking {
public:
	ll countPerfect(int n) {
		if (!n || n == 2) return 1LL;
		ll &ret = d[n];
		if (ret) return ret;
		for (int i = 0; i <= n - 2; i += 2)
			ret += countPerfect(i)*countPerfect(n - i - 2);
		return ret;
	}
};