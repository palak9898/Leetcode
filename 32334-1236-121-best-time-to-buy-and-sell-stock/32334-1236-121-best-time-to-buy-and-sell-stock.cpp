class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0; // Edge case: empty array
        
        int minPrice = prices[0];
        int maxProfit = 0;
        
        for (int i = 1; i < n; i++) {

            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            
            // Calculate the profit for the current price and update maxProfit
            int profit = prices[i] - minPrice;
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }
        
        return maxProfit;
    }
};
