class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        string res;

        for(char ch : s) {
            if(ch == '(' || ch == '{' || ch == '[') res.push_back(ch);
            else{
                if(res.empty()) return false;
                else if(ch == ')' && res.back() == '(' || 
                        ch == '}' && res.back() == '{' ||
                        ch == ']' && res.back() == '[') res.pop_back();
                else return false;
            }
        }
        return res.empty();
    }
};