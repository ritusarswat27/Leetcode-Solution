class Solution {
public:
int dRow[4] = {-1 , 0 , 1 , 0};
int dCol[4] = {0 , -1 , 0 , 1};

void bfs(int i , int j , vector<vector<char>>& grid , vector<vector<int>>& visited , int m , int n) {
    queue<pair<int , int>> q;
    q.push({i , j});
    visited[i][j] = 1;

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];

            if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && visited[nRow][nCol] == 0 && grid[nRow][nCol] == '1') {
                q.push({nRow , nCol});
                visited[nRow][nCol] = 1;
            }
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int islands = 0;

        vector<vector<int>> visited(m , vector<int>(n , 0));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '1' && visited[i][j] == 0) {
                    bfs(i , j , grid , visited , m , n);
                    islands++;
                }   
            }
        }
        return islands;    
    }
};