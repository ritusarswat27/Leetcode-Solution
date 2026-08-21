class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int> (n , INT_MAX));
        dist[0][0] = grid[0][0];

        priority_queue< vector<int> , vector<vector<int>> , greater<vector<int>>> pq;
        pq.push({grid[0][0] , 0 , 0});

        int rows[] = {-1 , 0 , 1 , 0};
        int cols[] = {0 , -1 , 0 , 1};

        while(!pq.empty()) {
            auto it = pq.top();
            int time = it[0];
            int row = it[1];
            int col = it[2];
            pq.pop();

            if(row == n - 1 && col == n - 1) return time;

            for(int i=0; i<4; i++) {
                int nRow = row + rows[i];
                int nCol = col + cols[i];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < n) {
                    int newTime = max(time , grid[nRow][nCol]);

                    if(newTime < dist[nRow][nCol]) {
                        dist[nRow][nCol] = newTime;
                        pq.push({newTime , nRow , nCol});
                    }
                }
            }
        }  
        return -1; 
    }
};