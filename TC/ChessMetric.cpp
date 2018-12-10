#include <vector>
#include <cstring>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
ll d[100][100][51];
int dy[] = { 1,1,1,0,-1,-1,-1,0,2,1,-1,-2,-2,-1,1,2 };
int dx[] = { 1,0,-1,-1,-1,0,1,1,-1,-2,-2,-1,1,2,2,1 };
class ChessMetric {
	int cnt = 0;
public:
	ll f(int n, int y, int x, int k) {
		if (k > cnt) return 0LL;
		ll &ret = d[y][x][k];
		if (ret != -1) return ret;
		ret = 0LL;
		for (int i = 0; i < 16; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < n&&nx >= 0 && nx < n)
				ret += f(n, ny, nx, k + 1);
		}
		return ret;
	}
	ll howMany(int size, vi start, vi end, int numMoves) {
		memset(d, -1, sizeof(d));
		cnt = numMoves;
		d[start[0]][start[1]][numMoves] = 1LL;
		return f(size, end[0], end[1], 0);
	}
};