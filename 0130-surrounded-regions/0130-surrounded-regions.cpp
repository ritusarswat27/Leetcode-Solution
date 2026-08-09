class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        queue<pair<int , int>> q;

        for(int j=0; j<n; j++) {
            if(board[0][j] == 'O') {
                q.push({0 , j});
                board[0][j] = 'S';
            }
            if(board[m - 1][j] == 'O') {
                q.push({m - 1 , j});
                board[m-1][j] = 'S';
            }
        }

        for(int i=0; i<m; i++) {
            if(board[i][0] == 'O') {
                q.push({i , 0});
                board[i][0] = 'S';
            }
            if(board[i][n - 1] == 'O') {
                q.push({i , n - 1});
                board[i][n - 1] = 'S';
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

                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && board[nRow][nCol] == 'O') {
                    q.push({nRow , nCol});
                    board[nRow][nCol] = 'S';
                }
            }
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'S') board[i][j] = 'O';
            }
        }   
    }
};