class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        if(n <= 8) return n;
            
        int extra = n - 8;
        int ans = 8;
        int i = 2;
        while(extra >= 8) {
            extra = extra - 8;
            ans += 8 * i;
            i++;  
        }
        if(extra > 0) ans += extra * i;
        return ans;
        
    }
};