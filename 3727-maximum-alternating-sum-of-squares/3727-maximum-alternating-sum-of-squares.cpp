class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n =  nums.size();
        vector<long long> arr(n);
        for(int i=0; i<n; i++) {
            arr[i] = nums[i] * nums[i];
        }
        int i = 0 , j = n - 1;
        sort(arr.begin() , arr.end());
        for(int k=0; k<n; k++) {
            if(k % 2 == 0) {
                nums[k] = arr[j--];
            }
            else {
                nums[k] = arr[i++];
            }
        }
        
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) ans += nums[i];
            else ans -= nums[i];
        }
        return ans;    
    }
};