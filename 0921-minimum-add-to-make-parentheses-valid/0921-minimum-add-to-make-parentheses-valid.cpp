class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        if(n == 0) return 0;
        
        int open = 0 , close = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == '(') open++;
            else {
                if(open != 0) open--;
                else if(open == 0) close++;
            }
        }
        return open+close;
    }
};