class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin() , nums.end());
        int minVal = *min_element(nums.begin() , nums.end());

        // int gcd = 1;
        // for(int i=1 ; i<= maxVal; i++) {
        //     if(minVal % i == 0 && maxVal % i == 0) gcd = i;
        // }
        // return gcd;  
        return gcd(maxVal , minVal);
    }
};