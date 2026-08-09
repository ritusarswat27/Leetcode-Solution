class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m , vector<int>(n , 0));

        queue<pair<pair<int , int> , int>> q;

        int minutes = 0;

        int dRow[] = {-1 , 0 , 1 , 0};
        int dCol[] = {0 , 1 , 0 , -1};

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i , j} , minutes});
                    visited[i][j] = 2;
                }
            }
        }
        
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();

            minutes = max(minutes , time);

            for(int i=0; i<4; i++) {
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];

                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && grid[nRow][nCol] == 1 && visited[nRow][nCol] == 0) {
                    q.push({{nRow , nCol} , time + 1});
                    visited[nRow][nCol] = 2;
                }
            }
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1 && visited[i][j] != 2) return -1;
            }
        }
        return minutes;
    }
};