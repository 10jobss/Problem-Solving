/*
 * 문제: 동일한 문자가 연속 3번 이상 반복되는 그룹의 시작과 끝 index 구하기
 * 해결방법:
 *   1) i번째 문자와 i-1번째 문자가 동일한 경우 끝index 증가
 *   2) 1)이 아니고 길이가 3 이상인 경우 vector push 및 시작index 및 갯수 초기화
 *   3) loop 종료 후 길이가 3이상인 경우 vector push
 * 참고:
 *   1) 시작, 끝 index 차를 이용해 길이를 구할 수 있으므로 cnt변수 불필요
 *   2) 조건이 더 깔끔한 풀이
 *   https://leetcode.com/problems/positions-of-large-groups/discuss/1099309/C%2B%2B-or-O(n)-or-Easy-or-Straight-Forward
 */
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int lo=0, hi, cnt=1;
        for(int i=1; i<(int)s.size(); i++){
            if(s[i-1] == s[i]) {
                hi = i;
                cnt++;
            } else if(cnt>=3) {
                ans.push_back({lo, hi});
                lo=i;
                cnt=1;
            } else {
                lo=i;
                cnt=1;
            }
        }
        if(cnt>=3)
            ans.push_back({lo, hi});
        return ans;
    }
};
