class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();

        string temp;
        for(int i=0; i<n; i++) {
            if (isalnum(s[i])) temp += tolower(s[i]);
            else if(s[i] >= 'a' && s[i] <= 'z') temp += s[i];
        }
        n = temp.length();
        for(int i=0; i<n/2; i++) {
            if(temp[i] != temp[n - i - 1]) return false;
        }
        return true;
        
    }
};