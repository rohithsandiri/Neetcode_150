class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int n = prices.size();
        int cur_min = INT_MAX;
        for(int i = 0; i < n; i++){
            cur_min = min(cur_min, prices[i]);
            max_profit = max(max(0, prices[i] - cur_min), max_profit);
        }
        return max_profit;
    }
};
