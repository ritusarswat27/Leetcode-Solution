class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> absDiff(m , vector<int> (n , INT_MAX));
        absDiff[0][0] = 0;

        priority_queue< vector<int> , vector<vector<int>> , greater<vector<int>>> pq;
        pq.push({0 , 0});

        int rows[] = {-1 , 0 , 1 , 0};
        int cols[] = {0 , -1 , 0 , 1};

        while(!pq.empty()) {
            auto it = pq.top();
            int row = it[0];
            int col = it[1];
            pq.pop();
            if(row == m - 1 && col == n - 1) return absDiff[row][col];

            for(int i=0; i<4; i++) {
                int nRow = row + rows[i];
                int nCol = col + cols[i];

                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n) {
                    int newEffort = max(abs(heights[row][col] - heights[nRow][nCol]) , absDiff[row][col]);

                    if(newEffort < absDiff[nRow][nCol]) {
                        absDiff[nRow][nCol] = newEffort;
                        pq.push({nRow , nCol});
                    }
                }
            }
        }  
        return 0;  
    }
};