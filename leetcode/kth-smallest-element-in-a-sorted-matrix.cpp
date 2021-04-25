/*
 * 문제: n*n 배열 원소에서 k번째 원소 구하기
 * 해결방법: 원소를 vector에 넣고 정렬 
 * 참고: max heap 사용한 풀이
 */
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        vector<int> vi;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                vi.push_back(matrix[i][j]);
        sort(vi.begin(), vi.end());
        return vi[k-1];
    }
};
