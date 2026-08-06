class Solution {
public:
    int smallestNumber(int n, int t) {
        int ans = n;
        while(true) {
            int pro = 1;
            int m = n;
            while(m > 0) {
                int digit = m % 10;
                pro *= digit;
                m /= 10;
            }
            if(pro % t == 0) return n;
            else n++;
        }
        return n;    
    }
};