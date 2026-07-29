class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        if(n == 1)return cost[0];
        if(n == 2)return min(cost[0],cost[1]);

        vector<int>dp(n+1, 0);

        for(int i = 2; i <= n; i++){
            dp[i] = min(dp[i-1] + cost[i-1], cost[i-2] + dp[i-2]);
        }
        
        int min1 = dp[n];

        for(int i = 3; i <= n; i++){
            dp[i] = min(dp[i-1] + cost[i-1], cost[i-2] + dp[i-2]);
        }

        int min2 = dp[n];

        return min(min1, min2);
    }
};
