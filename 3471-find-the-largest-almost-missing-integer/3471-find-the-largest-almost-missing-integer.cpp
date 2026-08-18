class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> hash(51 , 0);
        for(int num : nums) hash[num]++;

        if(k == 1) {
            int max = -1;
            for(int i=0; i<51; i++) {
                if(hash[i] == 1) max = i;
            }
            return max;
        }
        else if (k == n) return *max_element(nums.begin() , nums.end());
        else {
            int freq1 = hash[nums[0]];
            int freq2 = hash[nums[n-1]];
                
            if(freq1 == 1 && freq2 == 1) return max(nums[0] , nums[n-1]);
            else if(freq1 == 1) return nums[0];
            else if(freq2 == 1) return nums[n-1];
        }
        return -1;    
    }
};