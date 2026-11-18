class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // f(n) = min(f(n-1), f(n-2))
        int one  = 0;
        int two = 0;
        for(int i = 2; i <= cost.size(); i ++){
            int temp = one;
            one = min(one + cost[i-1], two + cost[i-2]);
            two = temp;
        }
        return one;
    }
};
