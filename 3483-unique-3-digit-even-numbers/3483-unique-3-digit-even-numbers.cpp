class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        set<string> st;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                for(int k=0; k<n; k++) {
                    if(i != j && i != k && j != k && digits[i] != 0 && digits[k] % 2 == 0) {
                        string num = "";
                        num += to_string(digits[i]);
                        num += to_string(digits[j]);
                        num += to_string(digits[k]);
                        st.insert(num);
                    }    
                }
            }
        }
        return st.size();
    }
};