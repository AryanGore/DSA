class Solution {
public:
    int dfs(int i, vector<int>& cost, vector<int>&dp){
        if(i >= cost.size()){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        return dp[i] = cost[i] + min(dfs(i+1, cost, dp), dfs(i+2, cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size(), -1);
        // dp[0] = cost[0];
        // dp[1] = cost[1];
        return min(dfs(0, cost, dp), dfs(1,cost, dp));
    }
};
