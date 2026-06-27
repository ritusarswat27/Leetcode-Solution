class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<long long , int> mpp;
        for(int num : nums) mpp[num]++;

        int ans = 0;
        if(mpp.count(1)) {
            int cnt = mpp[1];
            ans = max(ans , cnt % 2 == 0 ? cnt - 1 : cnt);
        }

        for(auto it : mpp) {
            if(it.first == 1) continue;

            int len = 0;
            long long x = it.first;
            while(mpp.count(x) && mpp[x] >= 2) {
                len += 2;
                if(x > 1e9) break;
                x = x * x;
            }

            if(mpp.count(x)) len++;
            else len--;
            ans = max(ans , len);
        }
        return ans;    
    }
};