class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        // int n = num.size();
        // string temp;
        // for(int i=0; i<n; i++) {
        //     char digit = num[i] + '0';
        //     temp += digit;
        // }
        // long long number = stoll(temp);
        // number += k;
        // temp = to_string(number);
        // vector<int> ans;
        // for(int i=0; i<temp.size(); i++) {
        //     int digit = temp[i] - '0';
        //     ans.push_back(digit);
        // }
        // return ans;


        int i = num.size() - 1;
    vector<int> ans;

    while(i >= 0 || k > 0) {
        if(i >= 0) {
            k += num[i];
            i--;
        }

        ans.push_back(k % 10);
        k /= 10;
    }

    reverse(ans.begin(), ans.end());

    return ans;
        
    }
};