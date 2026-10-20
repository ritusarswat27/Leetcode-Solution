class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(m != n) return false;
        // sort(s.begin() , s.end());
        // sort(t.begin() , t.end());
        // return (s == t);  


        vector<int> freq(26 , 0);
        for(int i=0; i<m; i++) freq[s[i] - 'a']++;
        for(int i=00; i<n; i++) freq[t[i] - 'a']--;
        for(int i=0; i<26; i++) if(freq[i] != 0) return false;
        return true;
    }
};