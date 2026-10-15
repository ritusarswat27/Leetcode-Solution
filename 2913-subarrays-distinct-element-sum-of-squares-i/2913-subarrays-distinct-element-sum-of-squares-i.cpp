class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) {
            vector<int> vec(101 , 0);
            for(int j=i; j<n; j++) {
                vec[nums[j]]++;
                int count = 0;
                for(int k=0; k<101; k++) {
                    if(vec[k] > 0) count++;
                }
                sum += count * count;
            }
        }
        return sum;    
    }
};