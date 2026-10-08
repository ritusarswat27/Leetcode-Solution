class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        int count = 0;
        string ans = "";
        bool start = true;
        for(int i=0; i<n; i++) {
            if(s[i] == '(' && start == true) {
                count++;
                start = false;
                continue;
            }
            else if(s[i] == '(') {
                count++;
            }
            else count--;

            if(count != 0 && start == false) {
                ans += s[i];
            }
            else if(count == 0) start = true;
        }
        return ans;    
    }
};