class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.length();
        
        vector<int> freq(26 , 0);
        for(char ch : text) freq[ch - 'a']++;
        
        int ans = min({
            freq['b' - 'a'],
            freq['a' - 'a'],
            freq['l' - 'a'] / 2,
            freq['o' - 'a'] / 2,
            freq['n' - 'a']
        });
        return ans;
    }
};