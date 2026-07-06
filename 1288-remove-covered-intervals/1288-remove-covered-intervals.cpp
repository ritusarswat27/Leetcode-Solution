class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int cnt = n;
        sort(intervals.begin() , intervals.end());

        // for(int i=1; i<n; i++) {
        //     if((intervals[i-1][0] <= intervals[i][0] && intervals[i][1] <= intervals[i-1][1]) || (intervals[i][0] <= intervals[i-1][0] && intervals[i-1][1] <= intervals[i][1]) ) cnt--;
        // }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i != j && intervals[j][0] <= intervals[i][0] && intervals[j][1] >= intervals[i][1]) {
                    cnt--;
                    break;
                }
            }
        }
        return cnt;
    }
};