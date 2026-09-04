class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i=0; i<n; i++) {
            int maxi = INT_MIN , mini = INT_MAX;
            for(int j=0; j<=i ; j++) {
                maxi = max(maxi , nums[j]);
            }
            for(int k=i; k<n; k++) {
                mini = min(mini , nums[k]);
            }
            if(maxi - mini <= k) return i;
        }  
        return -1;  
    }
};