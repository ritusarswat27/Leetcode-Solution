class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();

        int maxOpen = 0;
        int open = 0;
        for(char ch : s) {
            if(ch == '(') open++;
            else if(ch == ')') {
                maxOpen = max(maxOpen , open);
                open--;
            }
        }
        return maxOpen;    
    }
};