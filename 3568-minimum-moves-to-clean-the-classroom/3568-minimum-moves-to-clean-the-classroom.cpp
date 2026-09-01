class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int rows[] = {-1 , 0 , 1 , 0};
        int cols[] = {0 , -1 , 0 , 1};

        int startX = -1 , startY = -1 , litterCount = 0;
        vector<vector<int>> litterMap(m, vector<int>(n, -1));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(classroom[i][j] == 'S') startX = i , startY = j;
                else if(classroom[i][j] == 'L') litterMap[i][j] = litterCount++;
            }
        }

        if(litterCount == 0) return 0;

        queue<tuple<int , int , int , int , int>> q;
        q.push({startX, startY, energy, 0, 0});
        int targetMask = (1 << litterCount) - 1;

        vector<vector<vector<vector<bool>>>> visited(m, vector<vector<vector<bool>>>(n, vector<vector<bool>>(energy + 1, vector<bool>(1 << litterCount, false))));
        visited[startX][startY][energy][0] = true;

        while(!q.empty()) {
            auto [row, col, currentEnergy, mask, moves] = q.front();

            q.pop();

            for(int i=0; i<4; i++) {
                int nRow = row + rows[i];
                int nCol = col + cols[i];

                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && classroom[nRow][nCol] != 'X') {
                    int next_energy = currentEnergy - 1;
                    int next_mask = mask;

                    if(classroom[nRow][nCol] == 'L') next_mask |= (1 << litterMap[nRow][nCol]);
                    // next_mask = (1 << litterMap[nRow][nCol]);

                    if(next_mask == targetMask) return moves + 1;

                    if(classroom[nRow][nCol] == 'R') next_energy = energy;

                    if(next_energy == 0 && classroom[nRow][nCol] != 'R') continue;

                    if(!visited[nRow][nCol][next_energy][next_mask]) {
                        visited[nRow][nCol][next_energy][next_mask] = true;
                        q.push({nRow , nCol , next_energy , next_mask , moves + 1});
                    }   
                }
            }
        }
        return -1;
    }
};