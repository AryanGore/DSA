class Solution {
public:
    int helper(int n, vector<int>&dp, vector<int>& cost){
        if(n >= cost.size()) return 0;
        if(dp[n] != -1) return dp[n];
        return dp[n] =cost[n] + min(helper(n+1,dp,cost),helper(n+2,dp,cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size(), -1);
        return min(helper(0,dp,cost),helper(1,dp,cost));
    }
};
