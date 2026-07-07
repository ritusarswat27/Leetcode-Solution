class Solution {
public:
    long long sumAndMultiply(int n) {
        //Brute-force Approach
        // long long sum = 0;
        // string str = to_string(n);
        // str.erase(remove(str.begin(), str.end(), '0'), str.end());
        // for(int i=0; i<str.length(); i++) sum += str[i] - '0';
        // long long num = stoll(str);
        // return 1LL * num * sum; 

        //Optimal Approach
        long long ans = 0;
        long long place = 1;
        long long sum = 0;

        while (n > 0) {
            int digit = n % 10;
            sum += digit;

            if (digit != 0) {
                ans += digit * place;
                place *= 10;
            }
            n /= 10;
        }
        return 1LL * ans * sum;
    }
};