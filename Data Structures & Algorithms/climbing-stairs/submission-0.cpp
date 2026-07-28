class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)return 1;
        vector<int>dp(n + 1,0);
        dp[0] = 1;

        for(int i = 1; i <= n;i++){
            int temp = 0;
            if(i >= 1)temp = dp[i-1] + temp;
            if(i >= 2)temp = dp[i-2] + temp;

            dp[i] = temp;
        }
        
        return dp[n];
    }
};
