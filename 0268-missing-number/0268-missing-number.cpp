class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        //Brute-force Approach
        // for(int i=0; i<n+1; i++) {
        //     bool flag = false;
        //     for(int j=0; j<n; j++) {
        //         if(i == nums[j]) flag = true;
        //     }
        //     if(flag == false) return i;
        // }
        // return -1; 


        //Better Approach
        sort(nums.begin() , nums.end());
        for(int i=0; i<n; i++) {
            if(nums[i] != i) return i;
        }
        return n;
    }
};