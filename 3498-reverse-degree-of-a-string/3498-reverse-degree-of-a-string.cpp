class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        int degree = 0;
        for(int i=0; i<n; i++) {
            int pos = 26 - (s[i] - 'a');
            degree += (i + 1) * pos;
        }
        return degree;
    }
};