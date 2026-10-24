class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size = original.size();
        if(m * n != size) return {};
        vector<vector<int>> ans(m , vector<int>(n , 0));
        int i = 0;
        for(int j=0; j<m; j++) {
            for(int k=0; k<n; k++) {
                ans[j][k] = original[i];
                i++;
            }
        }
        return ans;
        
    }
};