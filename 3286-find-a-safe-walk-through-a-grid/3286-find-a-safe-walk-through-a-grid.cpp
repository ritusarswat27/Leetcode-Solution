class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        deque<pair<int , int>> dq;
        vector<vector<int>> dist(m , vector<int>(n , INT_MAX));
        dq.push_front({0 , 0});
        dist[0][0] = grid[0][0];

        int dRow[] = {-1 , 0 , 1 , 0};
        int dCol[] = {0 , 1 , 0 , -1};

        while(!dq.empty()) {
            int row = dq.front().first;
            int col = dq.front().second;
            dq.pop_front();

            if(row == m - 1 && col == n - 1) return dist[row][col] < health;

            for(int i=0; i<4; i++) {
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];

                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n) {
                    int w = grid[nRow][nCol];

                    if (dist[row][col] + w < dist[nRow][nCol]) {
                        dist[nRow][nCol] = dist[row][col] + w;

                        if (w == 0) dq.push_front({nRow, nCol});
                        else dq.push_back({nRow , nCol});
                    }
                }
            }
        }
        return (dist[m - 1][n - 1] < health) ? true : false;
    }
};