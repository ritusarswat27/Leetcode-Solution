class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int zeros = 0 , cnt = 0 , j = 0;
        
        for(int i=0; i<n; i++) {
            if(nums[i] == 0) zeros++;
            while(zeros > k) {
                if(nums[j] == 0) zeros--;
                j++;
            }
            cnt = max(cnt , i - j + 1);      
        }
        return cnt;
    }
};