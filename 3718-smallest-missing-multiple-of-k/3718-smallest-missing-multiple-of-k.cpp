class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> hash(101 , 0);
        for(int num : nums) hash[num]++;

        int gretestMultiple = -1;
        for(int i=1; i<101; i++) {
            if(hash[i] == 0 && i % k == 0) return i;
            else if(hash[i] != 0 && i % k == 0) gretestMultiple = i;
        }
        int times = gretestMultiple / k;
        return k * (times + 1);    
    }
};