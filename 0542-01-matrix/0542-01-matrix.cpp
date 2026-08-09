class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> visited(m , vector<int>(n , 0));

        queue<pair<pair<int , int> , int>> q;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] == 0) {
                    q.push({{i , j} , 0});
                    visited[i][j] = -1;
                }
            }
        }

        int dRow[] = {-1 , 0 , 1 , 0};
        int dCol[] = {0 , -1 , 0 , 1};

        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();

            for(int i=0; i<4; i++) {
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];

                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && mat[nRow][nCol] == 1 && visited[nRow][nCol] == 0) {
                    q.push({{nRow , nCol} , t + 1});
                    mat[nRow][nCol] = t + 1;
                    visited[nRow][nCol] = -1;
                }
            }
        }
        return mat;
    }
};