class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int profit = 0 , cost = INT_MAX;
        for(int i=0; i<n; i++) {
            cost = min(prices[i] , cost);
            profit = max(profit , prices[i] - cost);
        }
        return profit;    
    }
};