class Solution {
public:
    int maxProduct(int n) {
        string str = to_string(n);
        int m = str.length();

        int max_pro = INT_MIN;

        for(int i=0; i<m; i++) {
            for(int j=i+1; j<m; j++) {
                int pro = (str[i] - '0') * (str[j] - '0');
                max_pro = max(max_pro , pro);
            }
        }
        return max_pro;
    }
};