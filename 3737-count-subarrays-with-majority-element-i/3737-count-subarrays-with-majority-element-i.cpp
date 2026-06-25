class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        int cnt = 0;

        for(int i=0; i<n; i++) {
            int targetElem = 0;
            for(int j=i; j<n; j++) {
                if(nums[j] == target) targetElem++;
                if(2 * targetElem > j - i + 1) cnt++;
            }
        }
        return cnt;
    }
};