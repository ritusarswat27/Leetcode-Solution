class Solution {
public:
    int countCommas(int n) {
        if(n < 1000) return 0;
        int cnt = 0;
        int num = 0;
        for(int i=1000; i<= n; i++) {
            num++;
        }
        return num;
    }
};