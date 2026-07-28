class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        vector<int> freq(26, 0);
        for(char ch : s) freq[ch - 'a']++;

        int j = 0 , k = n - 1;
        for(int i=0; i<26; i++) {
            while(freq[i] > 1) {
                s[j] = i + 'a';
                s[k] = i + 'a';
                freq[i] -=2;
                j++ , k--;
            }
            if(freq[i] == 1) {
                s[j] = i + 'a';
                freq[i]--;
            }
        }
        return s;    
    }
};