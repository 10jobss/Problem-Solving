#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int w, h;
int dy[4]={0,0,-1,1}, dx[4]={1,-1,0,0};
bool chk[100][100];
int bfs(int y, int x, vector<vector<int> &pic) {
    queue<pii> q;
    chk[y][x] = true;
    q.push({y,x});
    int ret = 1;
    while(!q.empty()) {
        pii cur = q.front();
        q.pop();
        for(int i=0; i<4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if(ny < 0 || ny >= h || nx <0 || nx >= w) continue;
            if(!pic[ny][nx] || (pic[ny][nx]!=pic[y][x]) || chk[ny][nx]) continue;
            chk[ny][nx] = true;
            q.push({ny, nx});
            ret++;
        }
    }
    return ret;
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    w = n, h = m;
    memset(chk, 0, sizeof(chk));
    vector<int> answer(2);
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(picture[i][j] && !chk[i][j]) {
                number_of_area++;
                int x = bfs(i, j, picture);
                max_size_of_one_area = max_size_of_one_area < x ?
                    x : max_size_of_one_area;
            }
        }
    }
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
