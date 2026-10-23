class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();

        // int i = 0 , j = 0;
        // while(i < n) {
        //     if(nums[i] != i) {
        //         j = i;
        //         i++;
        //         break;
        //     }
        //     i++;
        // }
        // while(i < n) {
        //     if(nums[i] != i) {
        //         swap(nums[j] , nums[i]);
        //         return nums[j] & nums[i];
        //     }
        //     i++;
        // }
        // return -1;    


        int k = -1;
        for(int i=0; i<n; i++) {
            if(nums[i] != i) {
                k = k & nums[i];
                if(k == 0) return 0;
            }
        }
        return max(k , 0);
    }
};