class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        ans += numBottles;
        while(numBottles >=  numExchange) {
            int bottle = numBottles / numExchange;
            numBottles = numBottles % numExchange;
            ans += bottle;
            numBottles += bottle;
        }
        return ans;    
    }
};