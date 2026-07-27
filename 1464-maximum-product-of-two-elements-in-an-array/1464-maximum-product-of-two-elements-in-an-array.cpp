class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int maxi = 0;
        int secondMaxi = 0;

        for(int i=0; i<n; i++) {
            if(nums[i] >= maxi && nums[i] >= secondMaxi) {
                secondMaxi = maxi;
                maxi = nums[i];
            }
            else if(nums[i] > secondMaxi && nums[i] < maxi) {
                secondMaxi = nums[i];
            }
        }
        return (secondMaxi - 1) * (maxi - 1);      
    }
};