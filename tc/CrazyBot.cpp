int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
double prob[4] = {};
double ans = 0.0;
bool chk[29][29] = {};
class CrazyBot {
public:
	void dfs(int y, int x, int n, double p) {
		if (!n) {
			ans += p;
			return;
		}
		chk[y][x] = 1;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!chk[ny][nx] && n)
				dfs(ny, nx, n - 1, p*prob[i]);
		}
		chk[y][x] = 0;
	}
	double getProbability(int n, int east, int west, int south, int north) {
		prob[0] = east / 100.0;
		prob[1] = west / 100.0;
		prob[2] = south / 100.0;
		prob[3] = north / 100.0;
		dfs(15, 15, n, 1.0);
		return ans;
	}
};