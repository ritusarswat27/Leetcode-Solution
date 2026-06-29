class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = t.length();
        vector<int> hash(26 , 0);
        char ch;
        for(int i=0; i<n; i++) {
            hash[t[i] - 'a']++;
        }
        for(int i=0; i<n-1; i++) {
            hash[s[i] - 'a']--;
        }
        for(int i=0; i<26; i++) {
            if(hash[i] > 0) ch = i + 'a';
        }
        return ch;
    }
};