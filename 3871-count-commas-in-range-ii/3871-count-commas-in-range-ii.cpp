class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000) return 0;
        long long cnt = 0;
        long long smallest = 100;
        long long greatest = 999;
        for(int i=1; i<6; i++) {
            smallest = greatest + 1;
            greatest = 1LL * smallest * 1000 - 1;
            if(smallest < n && greatest < n) {
                long long res = greatest - smallest + 1;
                cnt += res * i;
            }
            else if(smallest <= n && greatest >= n) {
                long long res = n - smallest + 1;
                cnt += res * i;
            }
        }
        return cnt;
    }
};