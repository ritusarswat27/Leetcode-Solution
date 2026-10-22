class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        if(is_sorted(s.begin() , s.end())) return 0;
        else if(n == 2) return -1;

        char mx = *max_element(s.begin() , s.end());
        char mn = *min_element(s.begin() , s.end());

        if (s[0] == mn || s[n - 1] == mx)
            return 1;

        if (s[0] == mx && s[n - 1] == mn) {
            bool middleHasMax = false;
            bool middleHasMin = false;

            for (int i = 1; i < n - 1; i++) {
                if (s[i] == mx) middleHasMax = true;
                if (s[i] == mn) middleHasMin = true;
            }

            if (!middleHasMax && !middleHasMin)
                return 3;
        }

        return 2;   
    }
};