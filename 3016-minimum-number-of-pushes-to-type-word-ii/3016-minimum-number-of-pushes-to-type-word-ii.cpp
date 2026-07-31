class Solution {
public:
    int minimumPushes(string word) {
        map<char , int> freq;
        for(char ch : word) freq[ch]++;

        vector<pair<char, int>> v(freq.begin(), freq.end());

        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second > b.second; 
        });
        
        int ans = 0;

        for (int i = 0; i < v.size(); i++) {
            int multiplier = i / 8 + 1;
            ans += v[i].second * multiplier;
        }
        return ans;
    }
};