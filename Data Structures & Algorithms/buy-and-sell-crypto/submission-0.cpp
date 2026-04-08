class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //maintain max seen till now
        int n=prices.size();
        int min_seen=prices[0];
        int max_profit=0;
        for(int i=0;i<n;i++){
            max_profit=max(prices[i]-min_seen,max_profit);
            min_seen=min(min_seen,prices[i]);
        }
        return max_profit;
    }
};
