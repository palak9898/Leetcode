class Solution {
public:
    int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    
    int n = prices.size();
    vector<int> hold(n, 0), sell(n, 0), cooldown(n, 0);
    
    hold[0] = -prices[0];
    sell[0] = 0;
    cooldown[0] = 0;
    
    for (int i = 1; i < n; i++) {
        hold[i] = max(hold[i-1], cooldown[i-1] - prices[i]);
        sell[i] = hold[i-1] + prices[i];
        cooldown[i] = max(cooldown[i-1], sell[i-1]);
    }
    
    return max(sell[n-1], cooldown[n-1]);
}
};