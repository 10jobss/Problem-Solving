#include <vector>
#include <queue>
#include <utility>
#include <string>
using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
class MazeMaker {
public:
	int longestPath(vs maze, int startRow, int startCol, vi moveRow, vi moveCol) {
		queue<pii > q;
		bool chk[50][50] = {0,};
		int d = -1, n=(int)maze.size(),m=(int)maze[0].length();
		int k = (int)moveRow.size();
		chk[startRow][startCol] = 1;
		q.push({ startRow,startCol });
		while (!q.empty()) {
			++d;
			int qs = (int)q.size();
			while (qs--) {
				int cy = q.front().first;
				int cx = q.front().second;
				q.pop();
				for (int i = 0; i < k; i++) {
					int ny = cy + moveRow[i];
					int nx = cx + moveCol[i];
					if (ny >= 0 && ny < n&&nx >= 0 && nx < m&&maze[ny][nx] == '.' && !chk[ny][nx]) {
						chk[ny][nx] = 1;
						q.push({ ny,nx });
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (maze[i][j] == '.' && !chk[i][j])
					return -1;
		return d;
	}
};