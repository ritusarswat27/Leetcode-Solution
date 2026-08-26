class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string ans = "";

        int i = 0 , j = 0 , cnt = 0;
        while(i < n && j < n) {
            if(s[j] == '1') cnt++;

            while(cnt == k) {
                string curr = s.substr(i , j - i + 1);
                
                if(ans == "" || curr.length() < ans.length() ||
                (curr.length() == ans.length() && curr < ans)) ans = curr;
                else if(curr.length() < ans.length()) ans = curr;
                
                if(s[i] == '1') cnt--;
                i++;
            }
            j++;
        }
        return ans;
    }
};