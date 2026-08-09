class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int enclave = 0;

        queue<pair<int , int>> q;

        for(int j=0; j<n; j++) {
            if(grid[0][j] == 1) {
                q.push({0 , j});
                grid[0][j] = 0;
            }
            if(grid[m - 1][j] == 1) {
                q.push({m - 1 , j});
                grid[m-1][j] = 0;
            }
        }

        for(int i=0; i<m; i++) {
            if(grid[i][0] == 1) {
                q.push({i , 0});
                grid[i][0] = 0;
            }
            if(grid[i][n - 1] == 1) {
                q.push({i , n - 1});
                grid[i][n - 1] = 0;
            }
        }

        int dRow[] = {-1 , 0 , 1 , 0};
        int dCol[] = {0 , -1 , 0 , 1};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++) {
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];

                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && grid[nRow][nCol] == 1) {
                    q.push({nRow , nCol});
                    grid[nRow][nCol] = 0;
                    
                }
            }
        }  

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) enclave++;
            }
        }
        return enclave;  
    }
};