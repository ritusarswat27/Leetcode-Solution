class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        vector<int> block;
        int cnt0 = 0 , cnt1 = 0;

        for(int i=0; i<n; i++) {
            if(s[i] == '0') cnt0++;
            if(s[i] == '1') {
                if(cnt0 > 0) block.push_back(cnt0);
                cnt0 = 0;
                cnt1++;
            }
        }
        if(cnt0 > 0) block.push_back(cnt0);
        int sum = 0;
        for(int i=1; i<block.size(); i++) {
            sum = max(sum , block[i-1] + block[i]);
        }
        return sum + cnt1;
    }
};