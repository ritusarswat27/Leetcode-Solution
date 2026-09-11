class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();

        //Brute-force Approach
        // set<string> st;
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<n; j++) {
        //         for(int k=0; k<n; k++) {
        //             if(i != j && i != k && j != k && digits[i] != 0 && digits[k] % 2 == 0) {
        //                 string num = "";
        //                 num += to_string(digits[i]);
        //                 num += to_string(digits[j]);
        //                 num += to_string(digits[k]);
        //                 st.insert(num);
        //             }    
        //         }
        //     }
        // }
        // return st.size();


        //Optimal Approach
        unordered_map<int , int> mpp;
        for(auto num : digits) mpp[num] += 1;
        unordered_map<int , int> temp(mpp.begin() , mpp.end());

        int count = 0;
        
        for(int i=100; i<1000; i+=2) {
            int val = i;
            bool flag = false;
            while(val != 0) {
                int rem = val % 10;
                if(mpp.count(rem)) {
                    mpp[rem] -= 1;
                    if(mpp[rem] == 0) mpp.erase(rem);
                    flag = true;
                }
                else {
                    flag = false;
                    break;
                }
                val /= 10;
            }
            mpp = temp;
            if(flag == true) count++;
        }
        return count;
    }
};