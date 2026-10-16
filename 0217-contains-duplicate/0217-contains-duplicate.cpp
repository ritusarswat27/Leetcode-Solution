class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {


        // unordered_map<int , int> mpp;
        // for(int num : nums) {
        //     if(mpp.find(num) != mpp.end()) return true;
        //     mpp[num]++;
        // }
        // return false;   

        sort(nums.begin() , nums.end());
        for(int i=1; i<nums.size(); i++) {
            if(nums[i-1] == nums[i]) return true;
        }
        return false;
    }
};