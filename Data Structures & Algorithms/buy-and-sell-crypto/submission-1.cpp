class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int low = prices[0];
        int max_profit = 0;
        for(int i = 1; i < n; i ++){
            int cur = prices[i];
            int profit = cur - low;
            max_profit = max(profit, max_profit);
            low = min(cur, low);
        }
        return max_profit;
    }
};
