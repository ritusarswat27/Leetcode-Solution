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


        //Better Approach - 1
        // sort(nums.begin() , nums.end());
        // for(int i=0; i<n; i++) {
        //     if(nums[i] != i) return i;
        // }
        // return n;


        //Better Approach - 2
        // vector<int> vec(n + 1 , 0);
        // for(int num : nums) vec[num]++;
        // for(int i=0; i<vec.size(); i++) if(vec[i] == 0) return i;
        // return -1;


        //Optimal Approach
        int sum1 = (n * (n + 1)) / 2;
        int sum2 = 0;
        for(int num : nums) sum2 += num;
        return sum1 - sum2;
    }
};