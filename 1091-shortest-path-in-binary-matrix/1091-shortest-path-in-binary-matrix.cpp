class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        vector<vector<int>> distanceGrid(n , vector<int>(n , INT_MAX));
        distanceGrid[0][0] = 1;

        priority_queue< vector<int> , vector<vector<int>> , greater<vector<int>>> pq;
        pq.push({1 , 0 , 0});

        vector<vector<int>> distances = {
            {0,1} , {1,0} , {0,-1} , {-1,0}, 
            {1,1} , {-1,-1} , {1,-1} , {-1,1}
        };

        while(!pq.empty()) {
            auto it = pq.top();
            int dist = it[0];
            int row = it[1];
            int col = it[2];
            pq.pop();

            for(int i=0; i<8; i++) {
                int nRow = row + distances[i][0];
                int nCol = col + distances[i][1];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && grid[nRow][nCol] == 0) {
                    if(dist + 1 < distanceGrid[nRow][nCol]) {
                        distanceGrid[nRow][nCol] = dist + 1;
                        pq.push({distanceGrid[nRow][nCol] , nRow , nCol});
                    }
                }
            }
        }
        if(distanceGrid[n-1][n-1] == INT_MAX) return -1;
        return distanceGrid[n-1][n-1];    
    }
};