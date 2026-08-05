class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        //Brute-force Approach
        // for(int i=0; i<m; i++) {
        //     for(int j=0; j<n; j++) {
        //         if(matrix[i][j] == target) return true;
        //     }
        // }
        // return false;


        //Better Approach
        int i = 0;
        while(i < m) {
           if(matrix[i][0] <= target && matrix[i][n-1] >= target) {
                for(int j=0; j<n; j++) {
                    if(matrix[i][j] == target) return true;
                }
            }
            i++;
        }
        return false;


        //Optimal Approach
        // int i = 0;
        // while(i < m) {
        //    if(matrix[i][0] <= target && matrix[i][n-1] >= target) {
        //         int low = 0 , high = n - 1;
        //         while(low <= high) {
        //             int mid = (low + high) / 2;
        //             if(matrix[i][mid] == target) return true;
        //             else if(matrix[i][mid] < target) low = mid + 1;
        //             else high =  mid - 1;
        //         }
        //     }
        //     i++;
        // }
        // return false;    
    }
};