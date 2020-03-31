#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int n = board.size();
    stack<int> st;
    for(int k=0; k<moves.size(); k++) {
        int x = -1, c = moves[k] - 1;
        for(int i=0; i<n; i++) {
            if(board[i][c]) {
                x = board[i][c];
                board[i][c] = 0;
                break;
            }
        }
        if(x > 0) {
            if(st.empty() || st.pop != x)
                st.push(x);
            else {
                answer += 2;
                st.pop();
            }
        }
    }
    return answer;
}
