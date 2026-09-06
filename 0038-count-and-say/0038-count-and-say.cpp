class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string say = countAndSay(n - 1);
        string result = "";
        int i = 0;
        while(i<say.length()) {
            int count = 0;
            char ch = say[i];
            while(i < say.length() && ch == say[i]) i++ , count++;
            result += to_string(count) + ch;
        }
        return result;
    }
};