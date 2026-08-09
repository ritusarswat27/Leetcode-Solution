class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        int oldColor = image[sr][sc];

        if(oldColor == color) return image;

        queue<pair<int , int>> q;
        q.push({sr , sc});
        image[sr][sc] = color;

        int dRow[] = {-1 , 0 , 1 , 0};
        int dCol[] = {0 , -1 , 0 , 1};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++) {
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];

                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && image[nRow][nCol] == oldColor) {
                    q.push({nRow , nCol});
                    image[nRow][nCol] = color;
                }
            }
        }
        return image;   
    }
};